/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 08 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#include "move.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{
	
/* *********************************************************************
 * *************************** MOVK_M **********************************
 * ********************************************************************/	
MOVK_M::MOVK_M(ExtMachInst mach_inst)
    : StaticInst("MOV.K", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<16>(CST16_A), 16);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(0);
	init_dst_regs(1, REG, RD_A, 0);
}

void
MOVK_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		
		/* Execution. */
		WORD final = _imm;
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MOVK_M::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** MOVKH_M *********************************
 * ********************************************************************/	
MOVKH_M::MOVKH_M(ExtMachInst mach_inst)
    : StaticInst("MOV.KH", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<16>(CST16_A), 16);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(0);
	init_dst_regs(1, REG, RD_A, 0);
}

void
MOVKH_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {	
		/* Reading registers. */
		
		/* Execution. */
		WORD final = _imm;
		
		/* Writing registers. */
		cpu->cache_dst_w_hi_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MOVKH_M::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** MOVRC_D *********************************
 * ********************************************************************/	
MOVRC_D::MOVRC_D(ExtMachInst mach_inst)
    : StaticInst("MOVE", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(sext<16>(CST16_A), 16);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	//init_src_regs(num_src_regs, ...);
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A + C_Base_DepTag, 0);
}

void
MOVRC_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		WORD final = op;
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MOVRC_D::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** MOVR_M **********************************
 * ********************************************************************/	
MOVR_M::MOVR_M(ExtMachInst mach_inst)
    : StaticInst("MOVE", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(sext<16>(CST16_A), 16);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	//init_src_regs(num_src_regs, ...);
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
MOVR_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		WORD final = op;
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MOVR_M::generate_disassembly() const
{
	return print_inst();
}
	
} // namespace LILY2_NS
