/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "shift.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * *************************** ASL_A ***********************************
 * ********************************************************************/	
ASL_A::ASL_A(ExtMachInst mach_inst)
    : StaticInst("ASL", mach_inst)
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
ASL_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = asl(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ASL_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** ASLI_A **********************************
 * ********************************************************************/	
ASLI_A::ASLI_A(ExtMachInst mach_inst)
    : StaticInst("ASL", mach_inst)
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
ASLI_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = asl(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ASLI_A::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** ASR_A ***********************************
 * ********************************************************************/	
ASR_A::ASR_A(ExtMachInst mach_inst)
    : StaticInst("ASR", mach_inst)
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
ASR_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = asr(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ASR_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** ASRI_A **********************************
 * ********************************************************************/	
ASRI_A::ASRI_A(ExtMachInst mach_inst)
    : StaticInst("ASR", mach_inst)
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
ASRI_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = asr(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ASRI_A::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** LSR_A ***********************************
 * ********************************************************************/	
LSR_A::LSR_A(ExtMachInst mach_inst)
    : StaticInst("LSR", mach_inst)
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
LSR_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = lsr(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LSR_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** LSRI_A **********************************
 * ********************************************************************/	
LSRI_A::LSRI_A(ExtMachInst mach_inst)
    : StaticInst("LSR", mach_inst)
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
LSRI_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = lsr(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LSRI_A::generate_disassembly() const
{
	return print_inst_imm();
}
	
} // namespace LILY2_NS
