/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 24 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#ifndef __RISC_RESOURCES_EXECUTE_HH__
#define __RISC_RESOURCES_EXECUTE_HH__

#include "resource.hh"
#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/includes.hh"

namespace LILY2_NS
{
	
class Execute : public Resource
{
private:
    typedef StaticInst::StaticInstPtr StaticInstPtr;
	
public:
    /**
     * Recommended constructor.
     * 
     * @param (cpu)     : Pointer to cpu.
     * @param (num_res) : Kinds of resources.
     * @param (unit)    : Number of unit resources.
     */
    Execute(RiscCPU *cpu, int num_res, int num_unit);
    
    ~Execute(void) {}
    
public:
    /**
     * Execute the instructions.
     * 
     * @param (s_ptr) : Pointer to static instruction object.
     */
    void execute_inst(const StaticInst *s_ptr);
    
/* ********************************************************************
 * *************************** DEBUG CODE *****************************
 * *******************************************************************/
private:
    const StaticInst *_S_PTR;
    int cnt;

public:
    void __DEBUG(void)
    {
		DPF("%d. ", cnt++);
		if(_S_PTR->is_mem_ref()) {
			DPF("[ADDR] 0x%08x   [INST] %s   [MEM] 0x%08x\n", \
			    _S_PTR->get_dyn_inst()->get_inst_addr(), \
			    _S_PTR->generate_disassembly().c_str(), \
			    _S_PTR->get_dyn_inst()->get_mem_ref_addr());
		}
		else if(_S_PTR->is_control()) {
			if(_S_PTR->get_dyn_inst()->is_branch()) {
				DPF("[ADDR] 0x%08x   [INST] %s   [TARGET] 0x%08x\n", \
					_S_PTR->get_dyn_inst()->get_inst_addr(), \
					_S_PTR->generate_disassembly().c_str(), \
					_S_PTR->get_dyn_inst()->get_branch_target());
			}
			else {
			    DPF("[ADDR] 0x%08x   [INST] %s   [NO TARGET]", \
					_S_PTR->get_dyn_inst()->get_inst_addr(), \
					_S_PTR->generate_disassembly().c_str());	
			}
		}
		else {
			DPF("[ADDR] 0x%08x   [INST] %s\n", \
			    _S_PTR->get_dyn_inst()->get_inst_addr(), \
			    _S_PTR->generate_disassembly().c_str());
		}
	}
};
	
} // namespace LILY2_NS

#endif // __RISC_RESOURCES_EXECUTE_HH__
