/*
 * Copyright (c) 2012 ARM Limited
 * All rights reserved.
 *
 * The license below extends only to copyright in the software and shall
 * not be construed as granting a license to any other intellectual
 * property including but not limited to intellectual property relating
 * to a hardware implementation of the functionality of the software
 * licensed hereunder.  You may use the software subject to the license
 * terms below provided that you ensure that this notice is replicated
 * unmodified and in its entirety in all distributions of the software,
 * modified or unmodified, in source code or in binary form.
 *
 * Copyright (c) 2002-2005 The Regents of The University of Michigan
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Steve Reinhardt
 */

#include "arch/locked_mem.hh"
#include "arch/mmapped_ipr.hh"
#include "arch/utility.hh"
#include "base/bigint.hh"
#include "config/the_isa.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/exetrace.hh"
#include "debug/ExecFaulting.hh"
#include "debug/SimpleCPU.hh"
#include "mem/packet.hh"
#include "mem/packet_access.hh"
#include "mem/physical.hh"
#include "params/RiscCPU.hh"
#include "sim/faults.hh"
#include "sim/system.hh"
#include "sim/full_system.hh"

#include "cpu/risc/resources/pc_state.hh"
#include "cpu/risc/isa/static_inst.hh"
#include "cpu/risc/resources/fetch.hh"
#include "cpu/risc/resources/decode.hh"
#include "cpu/risc/resources/dispatch.hh"
#include "cpu/risc/resources/execute.hh"
#include "cpu/risc/resources/reg_file.hh"
#include "cpu/risc/resources/stack.hh"

using namespace std;
using namespace TheISA;

RiscCPU::TickEvent::TickEvent(RiscCPU *c)
    : Event(CPU_Tick_Pri), cpu(c)
{
}


void
RiscCPU::TickEvent::process()
{
    cpu->tick();
}

const char *
RiscCPU::TickEvent::description() const
{
    return "RiscCPU tick";
}

void
RiscCPU::init()
{
    BaseCPU::init();

    // Initialise the ThreadContext's memory proxies
    tcBase()->initMemProxies(tcBase());

    if (FullSystem && !params()->defer_registration) {
        ThreadID size = threadContexts.size();
        for (ThreadID i = 0; i < size; ++i) {
            ThreadContext *tc = threadContexts[i];
            // initialize CPU, including PC
            TheISA::initCPU(tc, tc->contextId());
        }
    }

    // Atomic doesn't do MT right now, so contextId == threadId
    ifetch_req.setThreadContext(_cpuId, 0); // Add thread ID if we add MT
    data_read_req.setThreadContext(_cpuId, 0); // Add thread ID here too
    data_write_req.setThreadContext(_cpuId, 0); // Add thread ID here too
}

RiscCPU::RiscCPU(RiscCPUParams *p)
    : BaseSimpleCPU(p), tickEvent(this), width(p->width), locked(false),
      simulate_data_stalls(p->simulate_data_stalls),
      simulate_inst_stalls(p->simulate_inst_stalls),
      icachePort(name() + "-iport", this), dcachePort(name() + "-iport", this),
      fastmem(p->fastmem),
      __pc_state(new PCState(this)),
      __fetch(new Fetch(this)),
      __decode(new Decode(this)),
      __dispatch(new Dispatch(this, 1, 2)),
      __xa_exec(new Execute(this,1,1)),
      __xm_exec(new Execute(this,1,1)),
      __xd_exec(new Execute(this,1,1)),
      __ya_exec(new Execute(this,1,1)),
      __ym_exec(new Execute(this,1,1)),
      __yd_exec(new Execute(this,1,1)),
      __x_regfile(new XRegFile(this,2,10,10)),
      __y_regfile(new YRegFile(this,2,10,10)),
      __g_regfile(new GRegFile(this,2,10,10)),
      __c_regfile(new CRegFile(this,2,10,10)),
      __ret_stack(new RetStack(this)),
      __mode(VLIW), __state(INITIAL), __cycle(0)
{
    _status = Idle;
}


RiscCPU::~RiscCPU()
{
    if (tickEvent.scheduled()) {
        deschedule(tickEvent);
    }
}

void
RiscCPU::serialize(ostream &os)
{
    SimObject::State so_state = SimObject::getState();
    SERIALIZE_ENUM(so_state);
    SERIALIZE_SCALAR(locked);
    BaseSimpleCPU::serialize(os);
    nameOut(os, csprintf("%s.tickEvent", name()));
    tickEvent.serialize(os);
}

void
RiscCPU::unserialize(Checkpoint *cp, const string &section)
{
    SimObject::State so_state;
    UNSERIALIZE_ENUM(so_state);
    UNSERIALIZE_SCALAR(locked);
    BaseSimpleCPU::unserialize(cp, section);
    tickEvent.unserialize(cp, csprintf("%s.tickEvent", section));
}

void
RiscCPU::resume()
{
    if (_status == Idle || _status == SwitchedOut)
        return;

    DPRINTF(SimpleCPU, "Resume\n");
    assert(system->getMemoryMode() == Enums::atomic);

    changeState(SimObject::Running);
    if (thread->status() == ThreadContext::Active) {
        if (!tickEvent.scheduled())
            schedule(tickEvent, nextCycle());
    }
    system->totalNumInsts = 0;
}

void
RiscCPU::switchOut()
{
    assert(_status == Running || _status == Idle);
    _status = SwitchedOut;

    tickEvent.squash();
}


void
RiscCPU::takeOverFrom(BaseCPU *oldCPU)
{
    BaseCPU::takeOverFrom(oldCPU);

    assert(!tickEvent.scheduled());

    // if any of this CPU's ThreadContexts are active, mark the CPU as
    // running and schedule its tick event.
    ThreadID size = threadContexts.size();
    for (ThreadID i = 0; i < size; ++i) {
        ThreadContext *tc = threadContexts[i];
        if (tc->status() == ThreadContext::Active && _status != Running) {
            _status = Running;
            schedule(tickEvent, nextCycle());
            break;
        }
    }
    if (_status != Running) {
        _status = Idle;
    }
    assert(threadContexts.size() == 1);
    ifetch_req.setThreadContext(_cpuId, 0); // Add thread ID if we add MT
    data_read_req.setThreadContext(_cpuId, 0); // Add thread ID here too
    data_write_req.setThreadContext(_cpuId, 0); // Add thread ID here too
}


void
RiscCPU::activateContext(ThreadID thread_num, int delay)
{
    DPRINTF(SimpleCPU, "ActivateContext %d (%d cycles)\n", thread_num, delay);

    assert(thread_num == 0);
    assert(thread);

    assert(_status == Idle);
    assert(!tickEvent.scheduled());

    notIdleFraction++;
    numCycles += tickToCycles(thread->lastActivate - thread->lastSuspend);

    //Make sure ticks are still on multiples of cycles
    schedule(tickEvent, nextCycle(curTick() + ticks(delay)));
    _status = Running;
}


void
RiscCPU::suspendContext(ThreadID thread_num)
{
    DPRINTF(SimpleCPU, "SuspendContext %d\n", thread_num);

    assert(thread_num == 0);
    assert(thread);

    if (_status == Idle)
        return;

    assert(_status == Running);

    // tick event may not be scheduled if this gets called from inside
    // an instruction's execution, e.g. "quiesce"
    if (tickEvent.scheduled())
        deschedule(tickEvent);

    notIdleFraction--;
    _status = Idle;
}


Fault
RiscCPU::readMem(Addr addr, uint8_t * data,
                         unsigned size, unsigned flags)
{
    // use the CPU's statically allocated read request and packet objects
    Request *req = &data_read_req;

    if (traceData) {
        traceData->setAddr(addr);
    }

    //The block size of our peer.
    unsigned blockSize = dcachePort.peerBlockSize();
    //The size of the data we're trying to read.
    int fullSize = size;

    //The address of the second part of this access if it needs to be split
    //across a cache line boundary.
    Addr secondAddr = roundDown(addr + size - 1, blockSize);

    if (secondAddr > addr)
        size = secondAddr - addr;

    dcache_latency = 0;

    while (1) {
        req->setVirt(0, addr, size, flags, dataMasterId(), thread->pcState().instAddr());

        // translate to physical address
        Fault fault = thread->dtb->translateAtomic(req, tc, BaseTLB::Read);

        // Now do the access.
        if (fault == NoFault && !req->getFlags().isSet(Request::NO_ACCESS)) {
            Packet pkt = Packet(req,
                                req->isLLSC() ? MemCmd::LoadLockedReq :
                                MemCmd::ReadReq);
            pkt.dataStatic(data);

            if (req->isMmappedIpr())
                dcache_latency += TheISA::handleIprRead(thread->getTC(), &pkt);
            else {
                if (fastmem && system->isMemAddr(pkt.getAddr()))
                    system->getPhysMem().access(&pkt);
                else
                    dcache_latency += dcachePort.sendAtomic(&pkt);
            }
            dcache_access = true;

            assert(!pkt.isError());

            if (req->isLLSC()) {
                TheISA::handleLockedRead(thread, req);
            }
        }

        //If there's a fault, return it
        if (fault != NoFault) {
            if (req->isPrefetch()) {
                return NoFault;
            } else {
                return fault;
            }
        }

        //If we don't need to access a second cache line, stop now.
        if (secondAddr <= addr)
        {
            if (req->isLocked() && fault == NoFault) {
                assert(!locked);
                locked = true;
            }
            return fault;
        }

        /*
         * Set up for accessing the second cache line.
         */

        //Move the pointer we're reading into to the correct location.
        data += size;
        //Adjust the size to get the remaining bytes.
        size = addr + fullSize - secondAddr;
        //And access the right address.
        addr = secondAddr;
    }
}


Fault
RiscCPU::writeMem(uint8_t *data, unsigned size,
                          Addr addr, unsigned flags, uint64_t *res)
{
    // use the CPU's statically allocated write request and packet objects
    Request *req = &data_write_req;

    if (traceData) {
        traceData->setAddr(addr);
    }

    //The block size of our peer.
    unsigned blockSize = dcachePort.peerBlockSize();
    //The size of the data we're trying to read.
    int fullSize = size;

    //The address of the second part of this access if it needs to be split
    //across a cache line boundary.
    Addr secondAddr = roundDown(addr + size - 1, blockSize);

    if(secondAddr > addr)
        size = secondAddr - addr;

    dcache_latency = 0;

    while(1) {
        req->setVirt(0, addr, size, flags, dataMasterId(), thread->pcState().instAddr());

        // translate to physical address
        Fault fault = thread->dtb->translateAtomic(req, tc, BaseTLB::Write);

        // Now do the access.
        if (fault == NoFault) {
            MemCmd cmd = MemCmd::WriteReq; // default
            bool do_access = true;  // flag to suppress cache access

            if (req->isLLSC()) {
                cmd = MemCmd::StoreCondReq;
                do_access = TheISA::handleLockedWrite(thread, req);
            } else if (req->isSwap()) {
                cmd = MemCmd::SwapReq;
                if (req->isCondSwap()) {
                    assert(res);
                    req->setExtraData(*res);
                }
            }

            if (do_access && !req->getFlags().isSet(Request::NO_ACCESS)) {
                Packet pkt = Packet(req, cmd);
                pkt.dataStatic(data);

                if (req->isMmappedIpr()) {
                    dcache_latency +=
                        TheISA::handleIprWrite(thread->getTC(), &pkt);
                } else {
                    if (fastmem && system->isMemAddr(pkt.getAddr()))
                        system->getPhysMem().access(&pkt);
                    else
                        dcache_latency += dcachePort.sendAtomic(&pkt);
                }
                dcache_access = true;
                assert(!pkt.isError());

                if (req->isSwap()) {
                    assert(res);
                    memcpy(res, pkt.getPtr<uint8_t>(), fullSize);
                }
            }

            if (res && !req->isSwap()) {
                *res = req->getExtraData();
            }
        }

        //If there's a fault or we don't need to access a second cache line,
        //stop now.
        if (fault != NoFault || secondAddr <= addr)
        {
            if (req->isLocked() && fault == NoFault) {
                assert(locked);
                locked = false;
            }
            if (fault != NoFault && req->isPrefetch()) {
                return NoFault;
            } else {
                return fault;
            }
        }

        /*
         * Set up for accessing the second cache line.
         */

        //Move the pointer we're reading into to the correct location.
        data += size;
        //Adjust the size to get the remaining bytes.
        size = addr + fullSize - secondAddr;
        //And access the right address.
        addr = secondAddr;
    }
}


void
RiscCPU::tick()
{
    DPRINTF(SimpleCPU, "Tick\n");

    Tick latency = 0;

    if(!__pc_state->is_init())
        __pc_state->init((thread->pcState()).instAddr());

    for (int i = 0; i < width || locked; ++i) {
		DPF("\n\n\n");
		DPF("Cycle = %ld\n", __cycle);

		switch(__state) {
			case INITIAL: {
				__cycle += Initial_Cycle;
				__state = RUNNING;
				break;
			}

			case BUBBLES: {
				FOR(i,0,Bubbles_Cycle) commit();
				__cycle += Bubbles_Cycle;
				__state = RUNNING;
				break;
			}

			case MODECUT: {
				FOR(i,0,Modecut_Cycle) commit();
				__cycle += Modecut_Cycle;
				__state = RUNNING;
				break;
			}

			case RUNNING: {
				int count = 0;
				bool keep_on;
				do {
					/* Fetch. */
					Addr addr = __pc_state->get_fetch_addr();
					if(addr==0x100008c) { printf("Enter the dead loop\n"); exit(0); }
					ExtMachInst mach_inst = __fetch->fetch_inst();

					/* Decode. */
					StaticInst *s_ptr = __decode->decode_inst(mach_inst);

					/* Dispatch. */
					keep_on = __dispatch->dispatch_inst(s_ptr, VLIW);

					/* Execute. */
					if(keep_on) {
						if(!(count++)) __pc_state->set_dpkt_addr(addr);
						__pc_state->set_inst_addr(addr);
						s_ptr->get_dyn_inst()->set_inst_addr(addr);
						__xa_exec->execute_inst(s_ptr);
						__xa_exec->__DEBUG();

						// 16-bit instructions.
						if(s_ptr->is_16_bit()) addr+=2;
						// 32-bit instructions.
						else addr+=4;

						/* Branch instructions. */
						if(s_ptr->is_control()) {
							// Branch taken.
							if(s_ptr->get_dyn_inst()->is_branch()) {
								addr = s_ptr->get_dyn_inst()->get_branch_target();
								__state = BUBBLES;
							}
						}

                        /* Mode. */
                        if(s_ptr->is_setr()) {
                            __mode = RISC;
                        }
                        if(s_ptr->is_setv()) {
                            __mode = VLIW;
                        }

						__pc_state->set_fetch_addr(addr);
					}

					delete s_ptr;
				} while(keep_on);

				break;
			}

			default: {
				assert(0);
			}
		}

		commit();
		clr_res(__dispatch);
		__cycle++;
		printf("X:\n");
		__x_regfile->__DEBUG();
		printf("Y:\n");
		__y_regfile->__DEBUG();
		printf("G:\n");
		__g_regfile->__DEBUG();

        //numCycles++;

        //if (!curStaticInst || !curStaticInst->isDelayedCommit())
            //checkForInterrupts();

        //checkPcEventQueue();
        // We must have just got suspended by a PC event
        //if (_status == Idle)
            //return;
        /*
        Fault fault = NoFault;

        TheISA::PCState pcState = thread->pcState();

        bool needToFetch = !isRomMicroPC(pcState.microPC()) &&
                           !curMacroStaticInst;
        if (needToFetch) {
            setupFetchRequest(&ifetch_req);
            fault = thread->itb->translateAtomic(&ifetch_req, tc,
                                                 BaseTLB::Execute);
        }

        if (fault == NoFault) {
            //Tick icache_latency = 0;
            //bool icache_access = false;
            //dcache_access = false; // assume no dcache access


            if (needToFetch) {
                // This is commented out because the decoder would act like
                // a tiny cache otherwise. It wouldn't be flushed when needed
                // like the I cache. It should be flushed, and when that works
                // this code should be uncommented.
                //Fetch more instruction memory if necessary
                //if(decoder.needMoreBytes())
                //{
                    icache_access = true;
                    Packet ifetch_pkt = Packet(&ifetch_req, MemCmd::ReadReq);
                    ifetch_pkt.dataStatic(&inst);

                    if (fastmem && system->isMemAddr(ifetch_pkt.getAddr()))
                        system->getPhysMem().access(&ifetch_pkt);
                    else
                        icache_latency = icachePort.sendAtomic(&ifetch_pkt);

                    assert(!ifetch_pkt.isError());

                    // ifetch_req is initialized to read the instruction directly
                    // into the CPU object's inst field.
                //}
            }



            preExecute();

            if (curStaticInst) {
                fault = curStaticInst->execute(this, traceData);

                // keep an instruction count
                if (fault == NoFault)
                    countInst();
                else if (traceData && !DTRACE(ExecFaulting)) {
                    delete traceData;
                    traceData = NULL;
                }

                postExecute();
            }

            // @todo remove me after debugging with legion done
            if (curStaticInst && (!curStaticInst->isMicroop() ||
                        curStaticInst->isFirstMicroop()))
                instCnt++;

            Tick stall_ticks = 0;
            if (simulate_inst_stalls && icache_access)
                stall_ticks += icache_latency;

            if (simulate_data_stalls && dcache_access)
                stall_ticks += dcache_latency;

            if (stall_ticks) {
                Tick stall_cycles = stall_ticks / ticks(1);
                Tick aligned_stall_ticks = ticks(stall_cycles);

                if (aligned_stall_ticks < stall_ticks)
                    aligned_stall_ticks += 1;

                latency += aligned_stall_ticks;
            }

        }
        if(fault != NoFault || !stayAtPC)
            advancePC(fault);
        */
    }

    // instruction takes at least one cycle
    if (latency < ticks(1))
        latency = ticks(1);

    if (_status != Idle)
        schedule(tickEvent, curTick() + latency);
}


void
RiscCPU::printAddr(Addr a)
{
    dcachePort.printAddr(a);
}


////////////////////////////////////////////////////////////////////////
//
//  RiscCPU Simulation Object
//
RiscCPU *
RiscCPUParams::create()
{
    numThreads = 1;
    if (!FullSystem && workload.size() != 1)
        panic("only one workload allowed");
    return new RiscCPU(this);
}

int
RiscCPU::get_num_res(Resource *res)
{
	return res->get_num_res();
}

bool
RiscCPU::no_res(Resource *res, int res_idx)
{
	return res->no_res(res_idx);
}

void
RiscCPU::incr_res(Resource *res, int res_idx, int delta)
{
	res->incr_res(res_idx, delta);
}

void
RiscCPU::clr_res(Resource *res)
{
	res->clr_res();
}

RiscCPU::WORD
RiscCPU::read_src_w_operand(const StaticInst *s_ptr, int idx)
{
	RegIndex reg_idx = s_ptr->get_src_reg_idx(idx);

	/* Could be X,Y,G,C. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::O_Base_DepTag);

	if(reg_idx<LILY2_NS::Y_Base_DepTag)
	    return __x_regfile->read_h0(reg_idx-LILY2_NS::X_Base_DepTag);
	else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    return __y_regfile->read_h0(reg_idx-LILY2_NS::Y_Base_DepTag);
	else if(reg_idx<LILY2_NS::C_Base_DepTag)
	    return __g_regfile->read_h0(reg_idx-LILY2_NS::G_Base_DepTag);
	else
	    return __c_regfile->read(reg_idx-LILY2_NS::C_Base_DepTag);
}

RiscCPU::DWORD
RiscCPU::read_src_dw_operand(const StaticInst *s_ptr, int idx)
{
	RegIndex reg_idx = s_ptr->get_src_reg_idx(idx);

	/* Could be X-Pair,Y,G. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

	if(reg_idx<LILY2_NS::Y_Base_DepTag) {
		return __x_regfile->read_h1h0(reg_idx-LILY2_NS::X_Base_DepTag);
	}
	else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    return __y_regfile->read_h1h0(reg_idx-LILY2_NS::Y_Base_DepTag);
	else
	    return __g_regfile->read_h1h0(reg_idx-LILY2_NS::G_Base_DepTag);
}

RiscCPU::QWORD
RiscCPU::read_src_qw_operand(const StaticInst *s_ptr, int idx)
{
	RegIndex reg_idx = s_ptr->get_src_reg_idx(idx);

	/* Could be Y,G. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

    if(reg_idx<LILY2_NS::Y_Base_DepTag)
        return __x_regfile->read(reg_idx-LILY2_NS::X_Base_DepTag);
    else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    return __y_regfile->read(reg_idx-LILY2_NS::Y_Base_DepTag);
	else
	    return __g_regfile->read(reg_idx-LILY2_NS::G_Base_DepTag);
}

RiscCPU::QSP
RiscCPU::read_src_qsp_operand(const StaticInst *s_ptr, int idx)
{
	RegIndex reg_idx = s_ptr->get_src_reg_idx(idx);

	QWORD reg_val;
	QSP treg_val;

	/* Could be Y,G. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

    if(reg_idx<LILY2_NS::X_Base_DepTag)
        reg_val = __x_regfile->read(reg_idx-LILY2_NS::X_Base_DepTag);
    else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    reg_val = __y_regfile->read(reg_idx-LILY2_NS::Y_Base_DepTag);
	else
	    reg_val = __g_regfile->read(reg_idx-LILY2_NS::G_Base_DepTag);

	treg_val._h0 = *reinterpret_cast<SP *>(&reg_val._h0);
	treg_val._h1 = *reinterpret_cast<SP *>(&reg_val._h1);
	treg_val._h2 = *reinterpret_cast<SP *>(&reg_val._h2);
	treg_val._h3 = *reinterpret_cast<SP *>(&reg_val._h3);

	return treg_val;
}

RiscCPU::SP
RiscCPU::read_src_sp_operand(const StaticInst *s_ptr, int idx)
{
	RegIndex reg_idx = s_ptr->get_src_reg_idx(idx);

	/* Could be X,Y,G. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

	WORD val;
	if(reg_idx<LILY2_NS::Y_Base_DepTag)
	    val = __x_regfile->read_h0(reg_idx-LILY2_NS::X_Base_DepTag);
	else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    val = __y_regfile->read_h0(reg_idx-LILY2_NS::Y_Base_DepTag);
	else
	    val = __g_regfile->read_h0(reg_idx-LILY2_NS::G_Base_DepTag);

	return *reinterpret_cast<SP *>(&val);
}

RiscCPU::DP
RiscCPU::read_src_dp_operand(const StaticInst *s_ptr, int idx)
{
	RegIndex reg_idx = s_ptr->get_src_reg_idx(idx);

	/* Could be X-Pair,Y,G. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

	DWORD val;
	if(reg_idx<LILY2_NS::Y_Base_DepTag) {
	    val = __x_regfile->read_h1h0(reg_idx-LILY2_NS::X_Base_DepTag);
	}
	else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    val = __y_regfile->read_h1h0(reg_idx-LILY2_NS::Y_Base_DepTag);
	else
	    val = __g_regfile->read_h1h0(reg_idx-LILY2_NS::G_Base_DepTag);

	return *reinterpret_cast<DP *>(&val);
}

void
RiscCPU::cache_dst_w_operand(const StaticInst *s_ptr, int idx, WORD reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	/* Could be X,Y,G,C. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::O_Base_DepTag);

	if(reg_idx<LILY2_NS::Y_Base_DepTag)
	    __x_regfile->cache_h0(reg_idx-LILY2_NS::X_Base_DepTag, \
	        reg_val, delay_slot);
	else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache_h0(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        reg_val, delay_slot);
	else if(reg_idx<LILY2_NS::C_Base_DepTag)
	    __g_regfile->cache_h0(reg_idx-LILY2_NS::G_Base_DepTag, \
	        reg_val, delay_slot);
	else
	    __c_regfile->cache(reg_idx-LILY2_NS::C_Base_DepTag, \
	        reg_val, delay_slot);
}

void
RiscCPU::cache_dst_dw_operand(const StaticInst *s_ptr, int idx, DWORD reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	/* Could be X-Pair,Y,G. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

    if(reg_idx<LILY2_NS::Y_Base_DepTag) {
	    __x_regfile->cache_h1h0(reg_idx-LILY2_NS::X_Base_DepTag, \
	        reg_val, delay_slot);
	}
	else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache_h1h0(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        reg_val, delay_slot);
	else
	    __g_regfile->cache_h1h0(reg_idx-LILY2_NS::G_Base_DepTag, \
	        reg_val, delay_slot);
}

void
RiscCPU::cache_dst_qw_operand(const StaticInst *s_ptr, int idx, QWORD reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	/* Could be Y,G. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

    if(reg_idx<LILY2_NS::Y_Base_DepTag)
	    __x_regfile->cache(reg_idx-LILY2_NS::X_Base_DepTag, \
	        reg_val, delay_slot);
    else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        reg_val, delay_slot);
	else
	    __g_regfile->cache(reg_idx-LILY2_NS::G_Base_DepTag, \
	        reg_val, delay_slot);
}

void
RiscCPU::cache_dst_qsp_operand(const StaticInst *s_ptr, int idx, QSP reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	QWORD treg_val;
	treg_val._h0 = *reinterpret_cast<WORD *>(&reg_val._h0);
	treg_val._h1 = *reinterpret_cast<WORD *>(&reg_val._h1);
	treg_val._h2 = *reinterpret_cast<WORD *>(&reg_val._h2);
	treg_val._h3 = *reinterpret_cast<WORD *>(&reg_val._h3);

	/* Could be Y,G. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

	if(reg_idx<LILY2_NS::Y_Base_DepTag)
	    __x_regfile->cache(reg_idx-LILY2_NS::X_Base_DepTag, \
	        treg_val, delay_slot);
    else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        treg_val, delay_slot);
	else
	    __g_regfile->cache(reg_idx-LILY2_NS::G_Base_DepTag, \
	        treg_val, delay_slot);
}

void
RiscCPU::cache_dst_qw_h0_operand(const StaticInst *s_ptr, int idx, WORD reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	/* Could be Y,G. */
	ERR(reg_idx>=LILY2_NS::Y_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

	if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache_h0(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        reg_val, delay_slot);
	else
	    __g_regfile->cache_h0(reg_idx-LILY2_NS::G_Base_DepTag, \
	        reg_val, delay_slot);
}

void
RiscCPU::cache_dst_qw_h1_operand(const StaticInst *s_ptr, int idx, WORD reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	/* Could be Y,G. */
	ERR(reg_idx>=LILY2_NS::Y_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

	if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache_h1(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        reg_val, delay_slot);
	else
	    __g_regfile->cache_h1(reg_idx-LILY2_NS::G_Base_DepTag, \
	        reg_val, delay_slot);
}

void
RiscCPU::cache_dst_qw_h2_operand(const StaticInst *s_ptr, int idx, WORD reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	/* Could be Y,G. */
	ERR(reg_idx>=LILY2_NS::Y_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

	if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache_h2(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        reg_val, delay_slot);
	else
	    __g_regfile->cache_h2(reg_idx-LILY2_NS::G_Base_DepTag, \
	        reg_val, delay_slot);
}

void
RiscCPU::cache_dst_qw_h3_operand(const StaticInst *s_ptr, int idx, WORD reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	/* Could be Y,G. */
	ERR(reg_idx>=LILY2_NS::Y_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

	if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache_h3(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        reg_val, delay_slot);
	else
	    __g_regfile->cache_h3(reg_idx-LILY2_NS::G_Base_DepTag, \
	        reg_val, delay_slot);
}

void
RiscCPU::cache_dst_sp_operand(const StaticInst *s_ptr, int idx, SP reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	/* Could be X,Y,G. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

	if(reg_idx<LILY2_NS::Y_Base_DepTag)
	    __x_regfile->cache_h0(reg_idx-LILY2_NS::X_Base_DepTag, \
	        *reinterpret_cast<WORD *>(&reg_val), delay_slot);
	else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache_h0(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        *reinterpret_cast<WORD *>(&reg_val), delay_slot);
	else
	    __g_regfile->cache_h0(reg_idx-LILY2_NS::G_Base_DepTag, \
	        *reinterpret_cast<WORD *>(&reg_val), delay_slot);
}

void
RiscCPU::cache_dst_dp_operand(const StaticInst *s_ptr, int idx, DP reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	/* Could be X-Pair,Y,G. */
	AST(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

	if(reg_idx<LILY2_NS::Y_Base_DepTag) {
		__x_regfile->cache_h1h0(reg_idx-LILY2_NS::X_Base_DepTag, \
            *reinterpret_cast<DWORD *>(&reg_val), delay_slot);
	}
	else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache_h1h0(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        *reinterpret_cast<DWORD *>(&reg_val), delay_slot);
	else
	    __g_regfile->cache_h1h0(reg_idx-LILY2_NS::G_Base_DepTag, \
	        *reinterpret_cast<DWORD *>(&reg_val), delay_slot);
}

void
RiscCPU::cache_dst_w_hi_operand(const StaticInst *s_ptr, int idx, WORD reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	/* Could be X,Y,G,C. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::O_Base_DepTag);

	if(reg_idx<LILY2_NS::Y_Base_DepTag) {
	    __x_regfile->cache_h0_hi(reg_idx-LILY2_NS::X_Base_DepTag, \
	        reg_val, delay_slot);
	}
	else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache_h0_hi(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        reg_val, delay_slot);
	else if(reg_idx<LILY2_NS::C_Base_DepTag)
	    __g_regfile->cache_h0_hi(reg_idx-LILY2_NS::G_Base_DepTag, \
	        reg_val, delay_slot);
	else
	    __c_regfile->cache_hi(reg_idx-LILY2_NS::C_Base_DepTag, \
	        reg_val, delay_slot);
}

void
RiscCPU::cache_dst_w_lo_operand(const StaticInst *s_ptr, int idx, WORD reg_val)
{
	RegIndex reg_idx = s_ptr->get_dst_reg_idx(idx);
	Tick delay_slot = s_ptr->get_dyn_inst()->get_dyn_delay_slot(idx);

	/* Could be X,Y,G,C. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::O_Base_DepTag);

	if(reg_idx<LILY2_NS::Y_Base_DepTag)
	    __x_regfile->cache_h0_lo(reg_idx-LILY2_NS::X_Base_DepTag, \
	        reg_val, delay_slot);
	else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    __y_regfile->cache_h0_lo(reg_idx-LILY2_NS::Y_Base_DepTag, \
	        reg_val, delay_slot);
	else if(reg_idx<LILY2_NS::C_Base_DepTag)
	    __g_regfile->cache_h0_lo(reg_idx-LILY2_NS::G_Base_DepTag, \
	        reg_val, delay_slot);
	else
	    __c_regfile->cache_lo(reg_idx-LILY2_NS::C_Base_DepTag, \
	        reg_val, delay_slot);
}


RiscCPU::WORD
RiscCPU::read_cond_w_operand(const StaticInst *s_ptr)
{
	RegIndex reg_idx = s_ptr->get_cond_reg_idx();

	/* Could be X-Pair,Y,G. */
	ERR(reg_idx>=LILY2_NS::X_Base_DepTag \
	    && reg_idx<LILY2_NS::C_Base_DepTag);

	if(reg_idx<LILY2_NS::Y_Base_DepTag)
	    return __x_regfile->read_h0(reg_idx-LILY2_NS::X_Base_DepTag);
	else if(reg_idx<LILY2_NS::G_Base_DepTag)
	    return  __y_regfile->read_h0(reg_idx-LILY2_NS::Y_Base_DepTag);
	else
	    return __g_regfile->read_h0(reg_idx-LILY2_NS::G_Base_DepTag);
}

void
RiscCPU::set_branch_target(Addr branch_target)
{
	__pc_state->set_branch_addr(branch_target);
}

void
RiscCPU::set_return_target(Addr return_target)
{
	__ret_stack->push(return_target);
}

Addr
RiscCPU::get_return_target(void)
{
	return __ret_stack->pop();
}

Addr
RiscCPU::get_inst_addr(void)
{
	return __pc_state->get_inst_addr();
}

void
RiscCPU::commit(void)
{
	__x_regfile->commit();
	__y_regfile->commit();
	__g_regfile->commit();
	__c_regfile->commit();
}
