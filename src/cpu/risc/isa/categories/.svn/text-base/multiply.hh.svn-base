/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 23 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#ifndef __RISC_ISA_CATEGORIES_MULTIPLY_HH__
#define __RISC_ISA_CATEGORIES_MULTIPLY_HH__

#include "cpu/risc/isa/static_inst.hh"

namespace LILY2_NS
{
/* *********************************************************************
 * *************************** MULSL_M *********************************
 * ********************************************************************/
class MULSL_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    MULSL_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** DIV_M ***********************************
 * ********************************************************************/
class DIV_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    DIV_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** DIVU_M **********************************
 * ********************************************************************/
class DIVU_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    DIVU_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};
	
} // namespace LILY2_NS

#endif // __RISC_ISA_CATEGORIES_MULTIPLY_HH__
