/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#ifndef __RISC_ISA_CATEGORIES_SHIFT_HH__
#define __RISC_ISA_CATEGORIES_SHIFT_HH__

#include "cpu/risc/isa/static_inst.hh"

namespace LILY2_NS
{
/* *********************************************************************
 * *************************** ASL_A ***********************************
 * ********************************************************************/
class ASL_A : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    ASL_A(ExtMachInst mach_inst);
    
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
 * *************************** ASLI_A **********************************
 * ********************************************************************/
class ASLI_A : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    ASLI_A(ExtMachInst mach_inst);
    
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
 * *************************** ASR_A ***********************************
 * ********************************************************************/
class ASR_A : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    ASR_A(ExtMachInst mach_inst);
    
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
 * *************************** ASRI_A **********************************
 * ********************************************************************/
class ASRI_A : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    ASRI_A(ExtMachInst mach_inst);
    
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
 * *************************** LSR_A ***********************************
 * ********************************************************************/
class LSR_A : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    LSR_A(ExtMachInst mach_inst);
    
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
 * *************************** LSRI_A ***********************************
 * ********************************************************************/
class LSRI_A : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    LSRI_A(ExtMachInst mach_inst);
    
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

#endif // __RISC_ISA_CATEGORIES_SHIFT_HH__
