/**
 * Copyright (C) Tsinghua University 2013
 *
 * Version : 1.0
 * Date    : 08 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#ifndef __RISC_ISA_CATEGORIES_MOVE_HH__
#define __RISC_ISA_CATEGORIES_MOVE_HH__

#include "cpu/risc/isa/static_inst.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * *************************** MOVK_M **********************************
 * ********************************************************************/
class MOVK_M : public StaticInst
{
public:
    /**
     * Constructor.
     *
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    MOVK_M(ExtMachInst mach_inst);

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
 * *************************** MOVKH_M *********************************
 * ********************************************************************/
class MOVKH_M : public StaticInst
{
public:
    /**
     * Constructor.
     *
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    MOVKH_M(ExtMachInst mach_inst);

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
 * *************************** MOVRC_D *********************************
 * ********************************************************************/
class MOVRC_D : public StaticInst
{
public:
    /**
     * Constructor.
     *
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    MOVRC_D(ExtMachInst mach_inst);

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
 * *************************** MOVR_M **********************************
 * ********************************************************************/
class MOVR_M : public StaticInst
{
public:
    /**
     * Constructor.
     *
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    MOVR_M(ExtMachInst mach_inst);

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
 * *************************** MOVQ_D **********************************
 * ********************************************************************/
class MOVQ_D : public StaticInst
{
public:
    /**
     * Constructor.
     *
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    MOVQ_D(ExtMachInst mach_inst);

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
 * *************************** MOVQF_D **********************************
 * ********************************************************************/
class MOVQF_D : public StaticInst
{
public:
    /**
     * Constructor.
     *
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    MOVQF_D(ExtMachInst mach_inst);

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
 * *************************** MOVFQ_D **********************************
 * ********************************************************************/
class MOVFQ_D : public StaticInst
{
public:
    /**
     * Constructor.
     *
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    MOVFQ_D(ExtMachInst mach_inst);

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
 * *************************** MOVXY_D **********************************
 * ********************************************************************/
class MOVXY_D : public StaticInst
{
public:
    /**
     * Constructor.
     *
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    MOVXY_D(ExtMachInst mach_inst);

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

#endif // __RISC_ISA_CATEGORIES_MOVE_HH__
