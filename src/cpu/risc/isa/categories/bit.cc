/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "bit.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * *************************** ZXT1_M **********************************
 * ********************************************************************/	
ZXT1_M::ZXT1_M(ExtMachInst mach_inst)
    : StaticInst("ZXT1", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
ZXT1_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		WORD final = bits(op, 7, 0);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ZXT1_M::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** ZXT2_M **********************************
 * ********************************************************************/	
ZXT2_M::ZXT2_M(ExtMachInst mach_inst)
    : StaticInst("ZXT2", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
ZXT2_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		WORD final = bits(op, 15, 0);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ZXT2_M::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** SXT1_M **********************************
 * ********************************************************************/	
SXT1_M::SXT1_M(ExtMachInst mach_inst)
    : StaticInst("SXT1", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
SXT1_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		S_WORD final = sext<8>(bits(op, 7, 0));
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
SXT1_M::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** SXT2_M **********************************
 * ********************************************************************/	
SXT2_M::SXT2_M(ExtMachInst mach_inst)
    : StaticInst("SXT2", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
SXT2_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		S_WORD final = sext<16>(bits(op, 15, 0));
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
SXT2_M::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** PUTB_A **********************************
 * ********************************************************************/	
PUTB_A::PUTB_A(ExtMachInst mach_inst)
    : StaticInst("PUTB", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
PUTB_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = put_byte(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
PUTB_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** SELB_A **********************************
 * ********************************************************************/	
SELB_A::SELB_A(ExtMachInst mach_inst)
    : StaticInst("SELB", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
SELB_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = select_byte(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
SELB_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** EXT_A ***********************************
 * ********************************************************************/	
EXT_A::EXT_A(ExtMachInst mach_inst)
    : StaticInst("EXT", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
EXT_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = extract_sign(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
EXT_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** EXTU_A **********************************
 * ********************************************************************/	
EXTU_A::EXTU_A(ExtMachInst mach_inst)
    : StaticInst("EXTU", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
EXTU_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = extract_unsign(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
EXTU_A::generate_disassembly() const
{
	return print_inst();
}
	
} // namespace LILY2_NS
