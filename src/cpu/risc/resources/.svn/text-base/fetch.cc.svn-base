/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 19 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#include "fetch.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/resources/pc_state.hh"

namespace LILY2_NS
{

Fetch::Fetch(RiscCPU *cpu)
    : Resource(cpu),
      _inst_addr(0), _mach_inst(0),
      _pc_state(cpu->get_pcs()),
      _thread(cpu->get_thd()), _tc(cpu->get_tc())
{
}

Fetch::~Fetch(void)
{
}
      
ExtMachInst
Fetch::fetch_inst(void)
{
	MachInst inst_hi, inst_lo;
	_inst_addr = _pc_state->get_fetch_addr();
	inst_hi = _fetch_inst(_inst_addr);
	inst_lo = _fetch_inst(_inst_addr + sizeof(MachInst));
	_mach_inst = (ExtMachInst)inst_lo + ((ExtMachInst)inst_hi << 16);
	return _mach_inst;
}

MachInst
Fetch::_fetch_inst(Addr fetch_addr)
{
	MachInst inst;
	Request ifetch_req;
	(&ifetch_req)->setVirt(0, fetch_addr, sizeof(MachInst), \
	    Request::INST_FETCH, _cpu->instMasterId(), fetch_addr);
	_thread->itb->translateAtomic(&ifetch_req, _tc, BaseTLB::Execute);
	Packet ifetch_pkt = Packet(&ifetch_req, MemCmd::ReadReq);
	ifetch_pkt.dataStatic(&inst);
	_cpu->get_icp()->sendAtomic(&ifetch_pkt);
	return inst;
}

} // namespace LILY2_NS
