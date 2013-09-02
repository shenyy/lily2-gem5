/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 24 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#ifndef __RISC_ISA_DYN_INST_HH__
#define __RISC_ISA_DYN_INST_HH__

#include "base/refcnt.hh"
#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/includes.hh"

namespace LILY2_NS
{
	
class DynInst : public RefCounted
{
private:
    /* Instruction address. */
    Addr _inst_addr;
    
    /* Dispatch packet head address. */
    Addr _dpkt_addr;
    
    /* Execution unit(In Risc mode). */
    Unit _dyn_unit;
    
    /* Execution mode. */
    Mode _mode;
    
    /* Dynamic instruction delay slot. */
    Tick _dyn_delay_slot[Max_Dst_Regs];
    
    /* Value of source operands. */
    
    /* Value of destination operands. */
    
    /* Cond execution. */
    bool _op2nop;
    
    /* Memory access address information. */
    Addr _mem_ref_addr;
    int _mem_ref_size;
    
    /* Branch information. */
    bool _branch;
    Addr _branch_target;
    Addr _return_target;
    
    /* Branch prediction information. */
    bool _predicted;
    
public:
    /**
     * Get instruction address.
     */
    Addr get_inst_addr(void) const { return _inst_addr; }
    
    /**
     * Get dispatch packet head address.
     */
    Addr get_dpkt_addr(void) const { return _dpkt_addr; }
    
    /**
     * Get dynamic execution unit.
     */
    Unit get_dyn_unit(void) const { return _dyn_unit; }
    
    /**
     * Get instruction execution mode.
     */
    Mode get_mode(void) const { return _mode; }
    
    /**
     * Get dynamic delay slot.
     */
    Tick get_dyn_delay_slot(int idx) const { return _dyn_delay_slot[idx]; }
    
    /**
     * Is conditional execute?
     */
    bool is_op2nop(void) const { return _op2nop; }
    
    /**
     * Get memory access information.
     */
    Addr get_mem_ref_addr(void) const { return _mem_ref_addr; }
    int get_mem_ref_size(void) const { return _mem_ref_size; }
    
    /**
     * Get branch information.
     */
    bool is_branch(void) const { return _branch; }
    Addr get_branch_target(void) const { return _branch_target; }
    
    /**
     * Get branch prediction information.
     */
    bool is_predicted(void) const { return _predicted; }
    
    /**
     * Set dynamic delay slot.
     */
    void set_dyn_delay_slot(int idx, Tick dyn_delay_slot)
    {
		_dyn_delay_slot[idx] = dyn_delay_slot;
	}
	
	void set_op2nop(void)
	{
		_op2nop = true;
	}
	
	void set_branch_target(Addr branch_target)
	{
		_branch = true;
		_branch_target = branch_target;
	}
	
	void set_return_target(Addr return_target)
	{
		_return_target = return_target;
	}
	
	/**
	 * 
	 */
	void set_mem_ref_addr(Addr mem_ref_addr) 
	{
		_mem_ref_addr = mem_ref_addr;
	}
	
	void set_inst_addr(Addr inst_addr)
	{
		_inst_addr = inst_addr;
	}
};
	
} // namespace LILY2_NS

#endif // __RISC_ISA_DYN_INST_HH__
