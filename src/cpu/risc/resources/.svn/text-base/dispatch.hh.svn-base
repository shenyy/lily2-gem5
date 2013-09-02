/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 24 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#ifndef __RISC_RESOURCES_DISPATCH_HH__
#define __RISC_RESOURCES_DISPATCH_HH__

#include "resource.hh"
#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/includes.hh"
#include "cpu/risc/isa/static_inst.hh"
#include "cpu/risc/resources/reg_dep.hh"

namespace LILY2_NS
{
	
class Dispatch : public Resource
{
private:
    /* Register dependence table. */
    RegDepTable *_reg_dep;
    
    int num_branch, num_store;
	
private:
    typedef struct {
		int reg_dep;
		int branch;
		int mem_ref;
		int issue_width;
	} Parallel_Record;

    /* Parallel record table. */
    Parallel_Record table;
    
public:
    /**
     * Recommended constructor.
     * 
     * @param (cpu)         : Pointer to cpu.
     * @param (num_res)     : Kinds of resource.
     * @param (issue_width) : Issue width.
     */
    Dispatch(RiscCPU *cpu, int num_res, int issue_width);
    
    ~Dispatch(void);
    
public:
    /**
     * Dispatch the instructions.
     */
    bool dispatch_inst(const StaticInst *s_ptr);
    
    /**
     * Instruction parallelism detection in Risc.
     * a. Register dependence relationship.
     * b. Branch instruction restriction.
     * c. Memory access restriction.
     * d. Resource restriction(Issue width).
     */
    bool is_parallel_reg_dep(const StaticInst *s_ptr);
    bool is_parallel_branch(const StaticInst *s_ptr);
    bool is_parallel_mem_ref(const StaticInst *s_ptr);
    bool is_parallel_issue_width(const StaticInst *s_ptr);
    
    /**
     * Do statistics after dispatch.
     * a. Update register dependence table.
     * b. Branch instruction statistics.
     * c. Memory access instruction statistics.
     * d. Resources statistics(Issue width).
     */
    void statistics_reg_dep(const StaticInst *s_ptr);
    void statistics_branch(const StaticInst *s_ptr);
    void statistics_mem_ref(const StaticInst *s_ptr);
    void statistics_issue_width(const StaticInst *s_ptr);
    
    void clr_res(void)
    {
		Resource::clr_res();
		_reg_dep->update();
		num_branch = 0;
		num_store = 0;
	}
    
/* ********************************************************************
 * *************************** DEBUG CODE *****************************
 * *******************************************************************/
private:
    bool __FLAG;
    
public:
    void __DEBUG(void)
    {
		DPF("[DISPATCH DEBUG] %s\n", __FLAG ? "Yes" : "No");
		_reg_dep->__DEBUG();
	}
};
	
}

#endif // __RISC_RESOURCES_DISPATCH_HH__
