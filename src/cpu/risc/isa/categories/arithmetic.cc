/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 08 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "arithmetic.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * *************************** ADD_A ***********************************
 * ********************************************************************/	
ADD_A::ADD_A(ExtMachInst mach_inst)
    : StaticInst("ADD_A", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	init_unit(A);
	
	/* Immediate. */
	
	/* Registers. */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
ADD_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		S_WORD final = add(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
    }
    else {
		_d_ptr->set_op2nop();
	}
}

std::string
ADD_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** ADDI_A **********************************
 * ********************************************************************/
ADDI_A::ADDI_A(ExtMachInst mach_inst)
    : StaticInst("ADD_A", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
ADDI_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = _imm;
		
		/* Execution. */
		S_WORD final = add(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ADDI_A::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** ADDK_A **********************************
 * ********************************************************************/	
ADDK_A::ADDK_A(ExtMachInst mach_inst)
    : StaticInst("ADDK_A", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<16>(CST16_A), 16);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RD_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
ADDK_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = _imm;
		
		/* Execution. */
		S_WORD final = add(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ADDK_A::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** SUB_A ***********************************
 * ********************************************************************/	
SUB_A::SUB_A(ExtMachInst mach_inst)
    : StaticInst("SUB_A", mach_inst)
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
SUB_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		S_WORD final = sub(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
SUB_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** SUBI_A **********************************
 * ********************************************************************/	
SUBI_A::SUBI_A(ExtMachInst mach_inst)
    : StaticInst("SUB_A", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
SUBI_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = _imm;
		
		/* Execution. */
		S_WORD final = sub(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
SUBI_A::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** MAX_A ***********************************
 * ********************************************************************/	
MAX_A::MAX_A(ExtMachInst mach_inst)
    : StaticInst("MAX_A", mach_inst)
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
MAX_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		S_WORD final = max(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MAX_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** MIN_A ***********************************
 * ********************************************************************/	
MIN_A::MIN_A(ExtMachInst mach_inst)
    : StaticInst("MIN_A", mach_inst)
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
MIN_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		S_WORD final = min(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MIN_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** ABS_A ***********************************
 * ********************************************************************/	
ABS_A::ABS_A(ExtMachInst mach_inst)
    : StaticInst("ABS_A", mach_inst)
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
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
ABS_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		S_WORD final = abs(op);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ABS_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** NEG_A ***********************************
 * ********************************************************************/	
NEG_A::NEG_A(ExtMachInst mach_inst)
    : StaticInst("NEG_A", mach_inst)
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
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
NEG_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		S_WORD final = neg(op);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
NEG_A::generate_disassembly() const
{
	return print_inst();
}
	
} // namespace LILY2_NS
