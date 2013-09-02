/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 10 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "logic.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * *************************** AND_A ***********************************
 * ********************************************************************/	
AND_A::AND_A(ExtMachInst mach_inst)
    : StaticInst("AND", mach_inst)
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
AND_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = bit_and(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
AND_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** ANDI_A **********************************
 * ********************************************************************/	
ANDI_A::ANDI_A(ExtMachInst mach_inst)
    : StaticInst("AND", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<5>(CST5_A), 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
ANDI_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = bit_and(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ANDI_A::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** NAND_A **********************************
 * ********************************************************************/	
NAND_A::NAND_A(ExtMachInst mach_inst)
    : StaticInst("NAND", mach_inst)
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
NAND_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = bit_nand(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
NAND_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** NANDI_A *********************************
 * ********************************************************************/	
NANDI_A::NANDI_A(ExtMachInst mach_inst)
    : StaticInst("NAND", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<5>(CST5_A), 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
NANDI_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = bit_nand(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
NANDI_A::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** OR_A ************************************
 * ********************************************************************/	
OR_A::OR_A(ExtMachInst mach_inst)
    : StaticInst("OR", mach_inst)
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
OR_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = bit_or(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
OR_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** ORI_A ***********************************
 * ********************************************************************/	
ORI_A::ORI_A(ExtMachInst mach_inst)
    : StaticInst("OR", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<5>(CST5_A), 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
ORI_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = bit_or(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ORI_A::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** NOR_A ***********************************
 * ********************************************************************/	
NOR_A::NOR_A(ExtMachInst mach_inst)
    : StaticInst("NOR", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = false;
	_flags[Is_Cond   ]  = false;
	
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
NOR_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = bit_nor(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
NOR_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** NORI_A **********************************
 * ********************************************************************/	
NORI_A::NORI_A(ExtMachInst mach_inst)
    : StaticInst("NOR", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<5>(CST5_A), 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
NORI_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = bit_nor(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
NORI_A::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** XOR_A ***********************************
 * ********************************************************************/	
XOR_A::XOR_A(ExtMachInst mach_inst)
    : StaticInst("XOR", mach_inst)
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
XOR_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = bit_xor(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
XOR_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** XORI_A **********************************
 * ********************************************************************/	
XORI_A::XORI_A(ExtMachInst mach_inst)
    : StaticInst("XOR", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<5>(CST5_A), 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
XORI_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = bit_xor(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
XORI_A::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** XNOR_A **********************************
 * ********************************************************************/	
XNOR_A::XNOR_A(ExtMachInst mach_inst)
    : StaticInst("XNOR", mach_inst)
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
XNOR_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = bit_xnor(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
XNOR_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** XNORI_A *********************************
 * ********************************************************************/	
XNORI_A::XNORI_A(ExtMachInst mach_inst)
    : StaticInst("XNOR", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<5>(CST5_A), 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
XNORI_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = _imm;
		
		/* Execution. */
		WORD final = bit_xnor(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
XNORI_A::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** NOT_A ***********************************
 * ********************************************************************/	
NOT_A::NOT_A(ExtMachInst mach_inst)
    : StaticInst("NOT", mach_inst)
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
NOT_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		WORD final = bit_not(op);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
NOT_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** ANDN_A **********************************
 * ********************************************************************/	
ANDN_A::ANDN_A(ExtMachInst mach_inst)
    : StaticInst("ANDN", mach_inst)
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
ANDN_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = bit_andn(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ANDN_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** ORN_A ***********************************
 * ********************************************************************/	
ORN_A::ORN_A(ExtMachInst mach_inst)
    : StaticInst("ORN", mach_inst)
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
ORN_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = bit_orn(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ORN_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** XORN_A **********************************
 * ********************************************************************/	
XORN_A::XORN_A(ExtMachInst mach_inst)
    : StaticInst("XORN", mach_inst)
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
XORN_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = bit_xorn(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
XORN_A::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** XOR3_A **********************************
 * ********************************************************************/	
XOR3_A::XOR3_A(ExtMachInst mach_inst)
    : StaticInst("ANDN", mach_inst)
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
XOR3_A::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = bit_xor3(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
XOR3_A::generate_disassembly() const
{
	return print_inst();
}
	
} // namespace LILY2_NS
