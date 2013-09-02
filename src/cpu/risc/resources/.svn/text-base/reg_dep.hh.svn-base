/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 07 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#ifndef __RISC_RESOURCES_REG_DEP_HH__
#define __RISC_RESOURCES_REG_DEP_HH__

#include "resource.hh"
#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/type.hh"
#include "arch/lily2/lily2_traits/register.hh"

namespace LILY2_NS
{

class RegDepTable : public Resource
{
private:
    std::map<RegIndex, Tick> reg_dep_table;
	
public:
    RegDepTable(RiscCPU *cpu);
    ~RegDepTable(void);
    
public:
    /**
     * Add registers into register dependence table.
     * 
     * @param (reg_idx)    : Index of the register.
     * @param (delay_slot) : Delay slot of the register. 
     * 
     * @attention : Here the delay slot may be static delay slot(Vliw)
     *               or dynamic delay slot(Risc).
     */
    void push_reg(RegIndex reg_idx, Tick delay_slot);
    
    /**
     * Add register pairs into register dependence table.
     * 
     * @param (reg_idx)    : Index of the register pair.
     * @param (delay_slot) : Delay slot of the register pair. 
     * 
     * @attention : Here the delay slot may be static delay slot(Vliw)
     *               or dynamic delay slot(Risc).
     */
    void push_reg_pair(RegIndex reg_idx, Tick delay_slot);
    
    /**
     * Update the register dependence table.
     * 
     * @attention : The update operation includes two steps:
     *               1. Pop items whose delay slot is 0.
     *               2. Decrease delay slot of others by 1. 
     */
    void update(void);
    
    /**
     * Check register dependence.
     * 
     * @param (reg_idx) : Index of the register.
     * 
     * @return : Exist register dependence or not.
     */
    bool is_reg_dep(RegIndex reg_idx);
    
    /**
     * Check register pair dependence.
     * 
     * @param (reg_idx) : Index of the register pair.
     * 
     * @return : Exist register pair dependence or not.
     */
    bool is_reg_dep_pair(RegIndex reg_idx);
    
    /**
     * Find the maximum delay slot of an register.
     * 
     * @param (reg_idx) : Index of the register.
     * 
     * @return : The maximum delay slot of the given register.
     */
    Tick get_max_slot_reg(RegIndex reg_idx);
    Tick get_max_slot_reg_pair(RegIndex reg_idx);
    
/* ********************************************************************
 * *************************** DEBUG CODE *****************************
 * *******************************************************************/
public:
    void __DEBUG(void)
    {
		DPF("[REG DEP DEBUG]");
		std::map<RegIndex, Tick>::iterator	 iter;
		for(iter=reg_dep_table.begin(); iter!=reg_dep_table.end(); iter++) {
			DPF("<%d,%lld> ", iter->first, iter->second);
		}
		DPF("\n");
	}
};
	
} // namespace LILY2_NS

#endif // __RISC_RESOURCES_REG_DEP_HH__
