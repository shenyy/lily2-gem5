/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#ifndef __RISC_ISA_CATEGORIES_COMPARE_HH__
#define __RISC_ISA_CATEGORIES_COMPARE_HH__

#include "cpu/risc/isa/static_inst.hh"

namespace LILY2_NS
{
/* *********************************************************************
 * *************************** CMPEQ_D *********************************
 * ********************************************************************/
class CMPEQ_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPEQ_D(ExtMachInst mach_inst);
    
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
 * *************************** CMPEQI_D ********************************
 * ********************************************************************/
class CMPEQI_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPEQI_D(ExtMachInst mach_inst);
    
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
 * *************************** CMPNEQ_D *********************************
 * ********************************************************************/
class CMPNEQ_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPNEQ_D(ExtMachInst mach_inst);
    
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
 * *************************** CMPNEQI_D ********************************
 * ********************************************************************/
class CMPNEQI_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPNEQI_D(ExtMachInst mach_inst);
    
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
 * *************************** CMPGT_D *********************************
 * ********************************************************************/
class CMPGT_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPGT_D(ExtMachInst mach_inst);
    
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
 * *************************** CMPGTI_D *********************************
 * ********************************************************************/
class CMPGTI_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPGTI_D(ExtMachInst mach_inst);
    
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
 * *************************** CMPGTU_D *********************************
 * ********************************************************************/
class CMPGTU_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPGTU_D(ExtMachInst mach_inst);
    
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
 * *************************** CMPGTUI_D *******************************
 * ********************************************************************/
class CMPGTUI_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPGTUI_D(ExtMachInst mach_inst);
    
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
 * *************************** CMPLT_D *********************************
 * ********************************************************************/
class CMPLT_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPLT_D(ExtMachInst mach_inst);
    
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
 * *************************** CMPLTI_D ********************************
 * ********************************************************************/
class CMPLTI_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPLTI_D(ExtMachInst mach_inst);
    
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
 * *************************** CMPLTU_D ********************************
 * ********************************************************************/
class CMPLTU_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPLTU_D(ExtMachInst mach_inst);
    
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
 * *************************** CMPLTUI_D *******************************
 * ********************************************************************/
class CMPLTUI_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    CMPLTUI_D(ExtMachInst mach_inst);
    
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

#endif // __RISC_ISA_CATEGORIES_COMPARE_HH__
