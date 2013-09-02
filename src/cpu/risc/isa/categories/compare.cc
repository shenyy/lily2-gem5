/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "compare.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * *************************** CMPEQ_D *********************************
 * ********************************************************************/	
CMPEQ_D::CMPEQ_D(ExtMachInst mach_inst)
    : StaticInst("CMPEQ", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPEQ_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = cmpeq(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPEQ_D::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** CMPEQI_D ********************************
 * ********************************************************************/	
CMPEQI_D::CMPEQI_D(ExtMachInst mach_inst)
    : StaticInst("CMPEQ", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPEQI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = cmpeq(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPEQI_D::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** CMPNEQ_D *********************************
 * ********************************************************************/	
CMPNEQ_D::CMPNEQ_D(ExtMachInst mach_inst)
    : StaticInst("CMPNEQ", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPNEQ_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = cmpneq(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPNEQ_D::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** CMPNEQI_D ********************************
 * ********************************************************************/	
CMPNEQI_D::CMPNEQI_D(ExtMachInst mach_inst)
    : StaticInst("CMPNEQ", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPNEQI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = cmpneq(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPNEQI_D::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** CMPGT_D *********************************
 * ********************************************************************/	
CMPGT_D::CMPGT_D(ExtMachInst mach_inst)
    : StaticInst("CMPGT", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPGT_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		S_WORD final = cmpgt(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPGT_D::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** CMPGTI_D ********************************
 * ********************************************************************/	
CMPGTI_D::CMPGTI_D(ExtMachInst mach_inst)
    : StaticInst("CMPGT", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPGTI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = _imm;
		
		/* Execution. */
		S_WORD final = cmpgt(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPGTI_D::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** CMPGTU_D ********************************
 * ********************************************************************/	
CMPGTU_D::CMPGTU_D(ExtMachInst mach_inst)
    : StaticInst("CMPGTU", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPGTU_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = cmpgt(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPGTU_D::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** CMPGTUI_D *******************************
 * ********************************************************************/	
CMPGTUI_D::CMPGTUI_D(ExtMachInst mach_inst)
    : StaticInst("CMPGTU", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPGTUI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = cmpgt(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPGTUI_D::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** CMPLT_D *********************************
 * ********************************************************************/	
CMPLT_D::CMPLT_D(ExtMachInst mach_inst)
    : StaticInst("CMPLT", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPLT_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		S_WORD final = cmplt(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPLT_D::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** CMPLTI_D ********************************
 * ********************************************************************/	
CMPLTI_D::CMPLTI_D(ExtMachInst mach_inst)
    : StaticInst("CMPLT", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPLTI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = _imm;
		
		/* Execution. */
		S_WORD final = cmplt(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPLTI_D::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** CMPLTU_D ********************************
 * ********************************************************************/	
CMPLTU_D::CMPLTU_D(ExtMachInst mach_inst)
    : StaticInst("CMPLTU", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPLTU_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = cmplt(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPLTU_D::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** CMPLTUI_D *******************************
 * ********************************************************************/	
CMPLTUI_D::CMPLTUI_D(ExtMachInst mach_inst)
    : StaticInst("CMPLTU", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
CMPLTUI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = cmplt(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CMPLTUI_D::generate_disassembly() const
{
	return print_inst_imm();
}
	
} // namespace LILY2_NS
