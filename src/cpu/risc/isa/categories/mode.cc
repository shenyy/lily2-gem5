/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "mode.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * *************************** SETR_D **********************************
 * ********************************************************************/	
SETR_D::SETR_D(ExtMachInst mach_inst)
    : StaticInst("SETR", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Mode   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(0);
	init_dst_regs(0);
}

void
SETR_D::execute(RiscCPU *cpu) const
{
	
}

std::string
SETR_D::generate_disassembly() const
{
	return print_inst();
}
	
} // namespace LILY2_NS
