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

/**
 * Modifier: Li Xiaotian
 * Description: Implement a risc cpu in this file.
 */

#ifndef __CPU_RISC_RISC_HH__
#define __CPU_RISC_RISC_HH__

#include "cpu/risc/base.hh"
#include "params/RiscCPU.hh"

#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/includes.hh"

/* Forward declaration. */
namespace LILY2_NS
{
class Resource;
class PCState;

class Fetch;
class Decode;
class Dispatch;
class Execute;

class RetStack;
template <int N> class WRegFile;
template <int N> class QWRegFile;
}

class RiscCPU : public BaseSimpleCPU
{	
  public:

    RiscCPU(RiscCPUParams *params);
    virtual ~RiscCPU();

    virtual void init();

  private:

    struct TickEvent : public Event
    {
        RiscCPU *cpu;

        TickEvent(RiscCPU *c);
        void process();
        const char *description() const;
    };

    TickEvent tickEvent;

    const int width;
    bool locked;
    const bool simulate_data_stalls;
    const bool simulate_inst_stalls;

    // main simulation loop (one cycle)
    void tick();

    /**
     * An AtomicCPUPort overrides the default behaviour of the
     * recvAtomic and ignores the packet instead of panicking.
     */
    class AtomicCPUPort : public CpuPort
    {

      public:

        AtomicCPUPort(const std::string &_name, BaseCPU* _cpu)
            : CpuPort(_name, _cpu)
        { }

      protected:

        virtual Tick recvAtomicSnoop(PacketPtr pkt)
        {
            // Snooping a coherence request, just return
            return 0;
        }

    };

    AtomicCPUPort icachePort;
    AtomicCPUPort dcachePort;

    bool fastmem;
    Request ifetch_req;
    Request data_read_req;
    Request data_write_req;

    bool dcache_access;
    Tick dcache_latency;                  

  protected:

    /** Return a reference to the data port. */
    virtual CpuPort &getDataPort() { return dcachePort; }

    /** Return a reference to the instruction port. */
    virtual CpuPort &getInstPort() { return icachePort; }

  public:

    virtual void serialize(std::ostream &os);
    virtual void unserialize(Checkpoint *cp, const std::string &section);
    virtual void resume();

    void switchOut();
    void takeOverFrom(BaseCPU *oldCPU);

    virtual void activateContext(ThreadID thread_num, int delay);
    virtual void suspendContext(ThreadID thread_num);

    Fault readMem(Addr addr, uint8_t *data, unsigned size, unsigned flags);

    Fault writeMem(uint8_t *data, unsigned size,
                   Addr addr, unsigned flags, uint64_t *res);

    /**
     * Print state of address in memory system via PrintReq (for
     * debugging).
     */
    void printAddr(Addr a);
    
public:
    typedef LILY2_NS::WORD WORD;
    typedef LILY2_NS::DWORD DWORD;
    typedef LILY2_NS::QWORD QWORD;
    typedef LILY2_NS::SP SP;
    typedef LILY2_NS::DP DP;
    typedef LILY2_NS::QSP QSP;
    typedef LILY2_NS::StaticInst StaticInst;
    typedef LILY2_NS::StaticInst::StaticInstPtr StaticInstPtr;
    typedef LILY2_NS::PCState PCState;
    typedef LILY2_NS::RegIndex RegIndex;
    typedef LILY2_NS::RegType RegType;
    
    typedef LILY2_NS::Resource Resource;
    typedef LILY2_NS::Fetch Fetch;
    typedef LILY2_NS::Decode Decode;
    typedef LILY2_NS::Dispatch Dispatch;
    typedef LILY2_NS::Execute Execute;
    
    typedef LILY2_NS::RetStack RetStack;
    typedef LILY2_NS::WRegFile<LILY2_NS::Num_X_Regs> XRegFile;
    typedef LILY2_NS::QWRegFile<LILY2_NS::Num_Y_Regs> YRegFile;
    typedef LILY2_NS::QWRegFile<LILY2_NS::Num_G_Regs> GRegFile;
    typedef LILY2_NS::WRegFile<LILY2_NS::Num_C_Regs> CRegFile;
    
private:
    /* Pc State. */
    LILY2_NS::PCState *__pc_state;
    
    /* Pipeline: Fetch. */
    LILY2_NS::Fetch *__fetch;
    
    /* Pipeline: Decode. */
    Decode *__decode;
    
    /* Pipeline: Dispatch. */
    Dispatch *__dispatch;
    
    /* Pipeline: Execute. */
    Execute *__xa_exec, *__xm_exec, *__xd_exec;
    Execute *__ya_exec, *__ym_exec, *__yd_exec;
    
    /* Register files. */
    XRegFile *__x_regfile;
    YRegFile *__y_regfile;
    GRegFile *__g_regfile;
    CRegFile *__c_regfile;
    
    /* Return address stack. */
    RetStack *__ret_stack;
    
private:
    enum State {
		INITIAL,
		RUNNING, 
		BUBBLES, 
		MODECUT,  
		HALTING     
	};
	
	static const int Initial_Cycle = 6;
	static const int Bubbles_Cycle = 6;
	static const int Modecut_Cycle = 3;
	
	State __state;
	Tick __cycle;

public:
    /**
     * List of the interfaces of modules.
     */
    ThreadContext   *get_tc (void) { return tc;          }
    SimpleThread    *get_thd(void) { return thread;      }
    AtomicCPUPort *get_icp(void) { return &icachePort; }
    
    /**
     * List of the interfaces of resources.
     */
    LILY2_NS::PCState *get_pcs(void) { return __pc_state; }  
    LILY2_NS::Fetch *get_fetch(void) { return __fetch; }
	
	int get_num_res(Resource *res);
	
	/**
	 * Check whether there is no resources.
	 * 
	 * @param (res)     : Pointer to resource.
	 * @param (res_idx) : Index of the resources.
     * 
     * @return : No resources or not.
	 */
	bool no_res(Resource *res, int res_idx);
	
	/**
     * Increase tick-used and total-used resources.
     * 
     * @param (res)     : Pointer to resource.
     * @param (res_idx) : Index of the resources.
     * @param (delta)   : Increment, default value is 1.
     */
    void incr_res(Resource *res, int res_idx, int delta = 1);
    
    /**
     * Clear the tick-used resources.
     * 
     * @param (res) : Pointer to resource.
     */
    void clr_res(Resource *res);
    
    /**
     * Source operands reading interfaces.
     */
    WORD read_src_w_operand (const StaticInst *s_ptr, int idx);
    DWORD read_src_dw_operand(const StaticInst *s_ptr, int idx);
    QWORD read_src_qw_operand(const StaticInst *s_ptr, int idx);
    SP read_src_sp_operand(const StaticInst *s_ptr, int idx);
    DP read_src_dp_operand(const StaticInst *s_ptr, int idx);
    QSP read_src_qsp_operand(const StaticInst *s_ptr, int idx);
    /**
     * Results caching interfaces.
     */
    void cache_dst_w_operand (const StaticInst *s_ptr, int idx, WORD val);
    void cache_dst_dw_operand(const StaticInst *s_ptr, int idx, DWORD val);
    void cache_dst_qw_operand(const StaticInst *s_ptr, int idx, QWORD val);
    void cache_dst_sp_operand(const StaticInst *s_ptr, int idx, SP val);
    void cache_dst_dp_operand(const StaticInst *s_ptr, int idx, DP val);
    void cache_dst_qsp_operand(const StaticInst *s_ptr, int idx, QSP val);

    void cache_dst_w_hi_operand(const StaticInst *s_ptr, int idx, WORD val);
    void cache_dst_w_lo_operand(const StaticInst *s_ptr, int idx, WORD val);
    void cache_dst_qw_h0_operand(const StaticInst *s_ptr, int idx, WORD val);
    void cache_dst_qw_h1_operand(const StaticInst *s_ptr, int idx, WORD val);
    void cache_dst_qw_h2_operand(const StaticInst *s_ptr, int idx, WORD val);
    void cache_dst_qw_h3_operand(const StaticInst *s_ptr, int idx, WORD val);

    /**
     * Condition register interfaces.
     */
    WORD read_cond_w_operand(const StaticInst *s_ptr);
    
    Addr get_inst_addr(void);
    void set_branch_target(Addr branch_target);
    void set_return_target(Addr return_target);
    Addr get_return_target(void);
    
public:
    void commit(void);
};

#endif // __CPU_RISC_RISC_HH__
