/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#ifndef __RISC_RESOURCE_DECODE_HH__
#define __RISC_RESOURCE_DECODE_HH__

#include "resource.hh"
#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/includes.hh"

namespace LILY2_NS
{
	
class Decode : public Resource
{
private:
    
public:
    /**
     * Constructor.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    Decode(RiscCPU *cpu);
    
    ~Decode(void);
    
public:
    /**
     * Decode instructions.
     * 
     * @param (mach_inst) : Machine code of the instruction.
     * 
     * @return : Pointer to static instruction information.
     */
    StaticInst *decode_inst(ExtMachInst mach_inst);

/* ********************************************************************
 * *************************** DEBUG CODE *****************************
 * *******************************************************************/
private:
    StaticInst *s_ptr;
    ExtMachInst _mach_inst; 
    
public:
    void __DEBUG(void)
    {
		/* Machine code of instruction. */
		printf("[DECODE DEBUG] Machine Code: 0x%08x\n", _mach_inst);
		
		/* Mnemonic of instruction. */
		//std::stringstream ss;
		//s_ptr->print_mnemonic(ss);
		//DPF("[DECODE DEBUG] Mnemonic: %s\n", ss.str().c_str());
	}
};
	
} // namespace LILY2_NS

#endif // __RISC_RESOURCE_DECODE_HH__
