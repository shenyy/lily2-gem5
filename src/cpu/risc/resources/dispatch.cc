/**
 * Copyright (C) Tsinghua University 2013
 *
 * Version : 1.0
 * Date    : 24 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "dispatch.hh"
#include "cpu/risc/cpu.hh"
#include "reg_dep.hh"

namespace LILY2_NS
{

Dispatch::Dispatch(RiscCPU *cpu, int num_res, int issue_width)
    : Resource(cpu, num_res, issue_width),
      _reg_dep(new RegDepTable(cpu)),unit(No_Unit)
{
}

Dispatch::~Dispatch(void)
{
}

bool
Dispatch::dispatch_inst(const StaticInst *s_ptr, int mode)
{
    if(!mode) {
	__FLAG = true;
	if(!is_parallel_reg_dep(s_ptr)) {
		__FLAG = false;
		if(!__FLAG) printf("1\n");
		table.reg_dep++;
	}
	if(!is_parallel_branch(s_ptr)) {
		__FLAG = false;
		if(!__FLAG) printf("2\n");
		table.branch++;
	}
	if(!is_parallel_mem_ref(s_ptr)) {
		__FLAG = false;
		if(!__FLAG) printf("3\n");
		table.mem_ref++;
	}
	if(!is_parallel_issue_width(s_ptr)) {
		__FLAG = false;
		if(!__FLAG) printf("4\n");
		table.issue_width++;
	}

	/* After dispatch statistics. */
	if(__FLAG) {
		statistics_reg_dep(s_ptr);
		statistics_branch(s_ptr);
		statistics_mem_ref(s_ptr);
		statistics_issue_width(s_ptr);
	}}
    else {
        if(s_ptr->get_unit() <= unit) {
            unit = No_Unit;
            return false;
        }
        else {
            unit = s_ptr->get_unit();
            return true;
        }
    }

	return __FLAG;
}

bool
Dispatch::is_parallel_reg_dep(const StaticInst *s_ptr)
{
	// Source registers.
	FOR(i,0,s_ptr->get_num_src_regs()) {
		RegIndex reg_idx = s_ptr->get_src_reg_idx(i);
		RegType reg_type = s_ptr->get_src_reg_type(i);

		/* Register. */
		if(reg_type==REG)
		    if(_reg_dep->is_reg_dep(reg_idx))
		        return false;

		/* Register pair. */
	    if(reg_type==REG_PAIR)
			if(_reg_dep->is_reg_dep_pair(reg_idx))
			    return false;
	}

	// Condition register.
	RegIndex cond_reg_idx = s_ptr->get_cond_reg_idx();
	if(cond_reg_idx!=-1 && _reg_dep->is_reg_dep(cond_reg_idx))
	    return false;

	return true;
}

bool
Dispatch::is_parallel_branch(const StaticInst *s_ptr)
{
	return !num_branch;
}

bool
Dispatch::is_parallel_mem_ref(const StaticInst *s_ptr)
{
	return !num_store;
}

bool
Dispatch::is_parallel_issue_width(const StaticInst *s_ptr)
{
	/* Issue width resource restriction. */
	if(!_cpu->no_res(this, 0)) return true;
    else return false;
}

void
Dispatch::statistics_reg_dep(const StaticInst *s_ptr)
{
	FOR(i,0,s_ptr->get_num_dst_regs()) {
		RegIndex reg_idx = s_ptr->get_dst_reg_idx(i);
		RegType reg_type = s_ptr->get_dst_reg_type(i);
		Tick delay_slot = s_ptr->get_delay_slot(i);
		Tick dyn_delay_slot = 0;

		/* Register. */
		if(reg_type==REG) {
			if(_reg_dep->is_reg_dep(reg_idx)) {
				dyn_delay_slot = delay_slot + _reg_dep->get_max_slot_reg(reg_idx) + 1;
			}
			else {
				dyn_delay_slot = delay_slot;
			}
		    _reg_dep->push_reg(reg_idx, dyn_delay_slot);
		}

		/* Register pair. */
	    if(reg_type==REG_PAIR) {
			if(_reg_dep->is_reg_dep_pair(reg_idx)) {
			    dyn_delay_slot = delay_slot + _reg_dep->get_max_slot_reg_pair(reg_idx) + 1;
			}
			else {
				dyn_delay_slot = delay_slot;
			}
			_reg_dep->push_reg_pair(reg_idx, dyn_delay_slot);
		}
		/* Set dynamic delay slot. */
		s_ptr->get_dyn_inst()->set_dyn_delay_slot(i, dyn_delay_slot);
	}
}

void
Dispatch::statistics_branch(const StaticInst *s_ptr)
{
    if(s_ptr->is_control()) num_branch++;
}

void
Dispatch::statistics_mem_ref(const StaticInst *s_ptr)
{
	if(s_ptr->is_store()) num_store++;
}

void
Dispatch::statistics_issue_width(const StaticInst *s_ptr)
{
	_cpu->incr_res(this,0);
}

} // namespace LILY2_NS
