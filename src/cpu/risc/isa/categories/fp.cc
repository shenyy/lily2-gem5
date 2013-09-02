/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 06 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "fp.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * ***************************** MIN_SP_M ******************************
 * ********************************************************************/	
MIN_SP_M::MIN_SP_M(ExtMachInst mach_inst)
    : StaticInst("MIN_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
MIN_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);
		
		/* Execution. */
		SP final = min(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MIN_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * ***************************** MIN_DP_M ******************************
 * ********************************************************************/	
MIN_DP_M::MIN_DP_M(ExtMachInst mach_inst)
    : StaticInst("MIN_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
MIN_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);
		
		/* Execution. */
		DP final = min(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MIN_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * ***************************** MAX_SP_M ******************************
 * ********************************************************************/	
MAX_SP_M::MAX_SP_M(ExtMachInst mach_inst)
    : StaticInst("MAX_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
MAX_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);
		
		/* Execution. */
		SP final = max(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MAX_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * ***************************** MAX_DP_M ******************************
 * ********************************************************************/	
MAX_DP_M::MAX_DP_M(ExtMachInst mach_inst)
    : StaticInst("MAX_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
MAX_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);
		
		/* Execution. */
		DP final = max(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MAX_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * **************************** CMPLT_SP_M *****************************
 * ********************************************************************/	
CMPLT_SP_M::CMPLT_SP_M(ExtMachInst mach_inst)
    : StaticInst("CMPLT_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
 	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);       
}

void
CMPLT_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);		
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
CMPLT_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * **************************** CMPLT_DP_M *****************************
 * ********************************************************************/	
CMPLT_DP_M::CMPLT_DP_M(ExtMachInst mach_inst)
    : StaticInst("CMPLT_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
 	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);       
}

void
CMPLT_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);		
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
CMPLT_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * *************************** CMPGT_SP_M ******************************
 * ********************************************************************/	
CMPGT_SP_M::CMPGT_SP_M(ExtMachInst mach_inst)
    : StaticInst("CMPGT_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
 	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);       
}

void
CMPGT_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);		
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
CMPGT_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * *************************** CMPGT_DP_M ******************************
 * ********************************************************************/	
CMPGT_DP_M::CMPGT_DP_M(ExtMachInst mach_inst)
    : StaticInst("CMPGT_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
 	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);       
}

void
CMPGT_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);		
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
CMPGT_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * ************************* CMPEQ_SP_M ********************************
 * ********************************************************************/	
CMPEQ_SP_M::CMPEQ_SP_M(ExtMachInst mach_inst)
    : StaticInst("CMPEQ_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
 	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);       
}

void
CMPEQ_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);		
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
CMPEQ_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * ************************* CMPEQ_DP_M ********************************
 * ********************************************************************/
CMPEQ_DP_M::CMPEQ_DP_M(ExtMachInst mach_inst)
    : StaticInst("CMPEQ_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
 	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);       
}

void
CMPEQ_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);		
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
CMPEQ_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * **************************** ADD_SP_M *******************************
 * ********************************************************************/	
 ADD_SP_M::ADD_SP_M(ExtMachInst mach_inst)
    : StaticInst("ADD_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
ADD_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);
		
		/* Execution. */
		SP final = add(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ADD_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * **************************** ADD_DP_M *******************************
 * ********************************************************************/

ADD_DP_M::ADD_DP_M(ExtMachInst mach_inst)
    : StaticInst("ADD_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
ADD_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);
		
		/* Execution. */
		DP final = add(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ADD_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}
	

/* *********************************************************************
 * **************************** SUB_SP_M *******************************
 * ********************************************************************/	
SUB_SP_M::SUB_SP_M(ExtMachInst mach_inst)
    : StaticInst("SUB_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
SUB_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);
		
		/* Execution. */
		SP final = sub(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
SUB_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * **************************** SUB_DP_M *******************************
 * ********************************************************************/	
SUB_DP_M::SUB_DP_M(ExtMachInst mach_inst)
    : StaticInst("SUB_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
SUB_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);
		
		/* Execution. */
		DP final = sub(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
SUB_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * **************************** MPY_SP_M *******************************
 * ********************************************************************/	
MPY_SP_M::MPY_SP_M(ExtMachInst mach_inst)
    : StaticInst("MPY_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
MPY_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);
		
		/* Execution. */
		SP final = mul(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MPY_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * **************************** MPY_DP_M *******************************
 * ********************************************************************/
MPY_DP_M::MPY_DP_M(ExtMachInst mach_inst)
    : StaticInst("MPY_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
MPY_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);
		
		/* Execution. */
		DP final = mul(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MPY_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * **************************** DIV_SP_M *******************************
 * ********************************************************************/
DIV_SP_M::DIV_SP_M(ExtMachInst mach_inst)
    : StaticInst("DIV_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
DIV_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);
		
		/* Execution. */
		SP final = div(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
DIV_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * **************************** DIV_DP_M *******************************
 * ********************************************************************/	
DIV_DP_M::DIV_DP_M(ExtMachInst mach_inst)
    : StaticInst("DIV_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
DIV_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);
		
		/* Execution. */
		DP final = div(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
DIV_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * ************************ MPYADD_SP_M ********************************
 * ********************************************************************/	
MPYADD_SP_M::MPYADD_SP_M(ExtMachInst mach_inst)
    : StaticInst("MPYADD_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
MPYADD_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);
		SP op_2 = cpu->read_src_sp_operand(this, 2);

		/* Execution. */
		SP final = mac(op_0, op_1, op_2);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MPYADD_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * ************************ MPYADD_DP_M ********************************
 * ********************************************************************/
MPYADD_DP_M::MPYADD_DP_M(ExtMachInst mach_inst)
    : StaticInst("MPYADD_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
MPYADD_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);
		DP op_2 = cpu->read_src_dp_operand(this, 2);

		/* Execution. */
		DP final = mac(op_0, op_1, op_2);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MPYADD_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * ************************* NMPYADD_SP_M ******************************
 * ********************************************************************/	
NMPYADD_SP_M::NMPYADD_SP_M(ExtMachInst mach_inst)
    : StaticInst("NMPYADD_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
NMPYADD_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);
		SP op_2 = cpu->read_src_sp_operand(this, 2);

		/* Execution. */
		SP final = nmac(op_0, op_1, op_2);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
NMPYADD_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * ************************* NMPYADD_DP_M ******************************
 * ********************************************************************/
NMPYADD_DP_M::NMPYADD_DP_M(ExtMachInst mach_inst)
    : StaticInst("NMPYADD_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
NMPYADD_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);
		DP op_2 = cpu->read_src_dp_operand(this, 2);

		/* Execution. */
		DP final = nmac(op_0, op_1, op_2);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
NMPYADD_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


/* *********************************************************************
 * ************************** MPYSUB_SP_M ******************************
 * ********************************************************************/	
MPYSUB_SP_M::MPYSUB_SP_M(ExtMachInst mach_inst)
    : StaticInst("MPYSUB_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
MPYSUB_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);
		SP op_2 = cpu->read_src_sp_operand(this, 2);

		/* Execution. */
		SP final = msu(op_0, op_1, op_2);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MPYSUB_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

 
/* *********************************************************************
 * ************************** MPYSUB_DP_M ******************************
 * ********************************************************************/
MPYSUB_DP_M::MPYSUB_DP_M(ExtMachInst mach_inst)
    : StaticInst("MPYSUB_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
MPYSUB_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);
		DP op_2 = cpu->read_src_dp_operand(this, 2);

		/* Execution. */
		DP final = msu(op_0, op_1, op_2);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MPYSUB_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * *************************** NMPYSUB_SP_M ****************************
 * ********************************************************************/	
NMPYSUB_SP_M::NMPYSUB_SP_M(ExtMachInst mach_inst)
    : StaticInst("NMPYSUB_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
NMPYSUB_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		SP op_1 = cpu->read_src_sp_operand(this, 1);
		SP op_2 = cpu->read_src_sp_operand(this, 2);

		/* Execution. */
		SP final = nmsu(op_0, op_1, op_2);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
NMPYSUB_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * *************************** NMPYSUB_DP_M ****************************
 * ********************************************************************/
NMPYSUB_DP_M::NMPYSUB_DP_M(ExtMachInst mach_inst)
    : StaticInst("NMPYSUB_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
	init_dst_regs(1, REG, RD_A, 2);
}

void
NMPYSUB_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		DP op_1 = cpu->read_src_dp_operand(this, 1);
		DP op_2 = cpu->read_src_dp_operand(this, 2);

		/* Execution. */
		DP final = nmsu(op_0, op_1, op_2);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
NMPYSUB_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * ***************************** ABS_SP_M ******************************
 * ********************************************************************/	
ABS_SP_M::ABS_SP_M(ExtMachInst mach_inst)
    : StaticInst("ABS_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
ABS_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op = cpu->read_src_sp_operand(this, 0);
		
		/* Execution. */
		SP final = abs(op);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ABS_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * ***************************** ABS_DP_M ******************************
 * ********************************************************************/
ABS_DP_M::ABS_DP_M(ExtMachInst mach_inst)
    : StaticInst("ABS_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
ABS_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op = cpu->read_src_dp_operand(this, 0);
		
		/* Execution. */
		DP final = abs(op);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
ABS_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * **************************** SQRT_SP_M ******************************
 * ********************************************************************/	
SQRT_SP_M::SQRT_SP_M(ExtMachInst mach_inst)
    : StaticInst("SQRT_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
SQRT_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op = cpu->read_src_sp_operand(this, 0);
		
		/* Execution. */
		SP final = sqrt(op);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
SQRT_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * **************************** SQRT_DP_M ******************************
 * ********************************************************************/
SQRT_DP_M::SQRT_DP_M(ExtMachInst mach_inst)
    : StaticInst("SQRT_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
SQRT_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op = cpu->read_src_dp_operand(this, 0);
		
		/* Execution. */
		DP final = sqrt(op);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
SQRT_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * ***************************** RCP_SP_M ******************************
 * ********************************************************************/	
RCP_SP_M::RCP_SP_M(ExtMachInst mach_inst)
    : StaticInst("RCP_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
RCP_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op = cpu->read_src_sp_operand(this, 0);
		
		/* Execution. */
		SP final = rcp(op);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
RCP_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * ***************************** RCP_DP_M ******************************
 * ********************************************************************/
RCP_DP_M::RCP_DP_M(ExtMachInst mach_inst)
    : StaticInst("RCP_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
RCP_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op = cpu->read_src_dp_operand(this, 0);
		
		/* Execution. */
		DP final = rcp(op);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
RCP_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * *************************** RSQRT_SP_M ******************************
 * ********************************************************************/	
RSQRT_SP_M::RSQRT_SP_M(ExtMachInst mach_inst)
    : StaticInst("RSQRT_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
RSQRT_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op = cpu->read_src_sp_operand(this, 0);
		
		/* Execution. */
		SP final = rsqr(op);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
RSQRT_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * *************************** RSQRT_DP_M ******************************
 * ********************************************************************/	
RSQRT_DP_M::RSQRT_DP_M(ExtMachInst mach_inst)
    : StaticInst("RSQRT_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
RSQRT_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op = cpu->read_src_dp_operand(this, 0);
		
		/* Execution. */
		DP final = rsqr(op);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
RSQRT_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * ***************************** EXP_SP_M ******************************
 * ********************************************************************/	
EXP_SP_M::EXP_SP_M(ExtMachInst mach_inst)
    : StaticInst("EXP_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
EXP_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op = cpu->read_src_sp_operand(this, 0);
		
		/* Execution. */
		SP final = exp(op, OP_3);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
EXP_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

/* *********************************************************************
 * ***************************** EXP_DP_M ******************************
 * ********************************************************************/
EXP_DP_M::EXP_DP_M(ExtMachInst mach_inst)
    : StaticInst("EXP_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
EXP_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op = cpu->read_src_dp_operand(this, 0);
		
		/* Execution. */
		DP final = exp(op, OP_3);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
EXP_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

	

/* *********************************************************************
 * ***************************** LOG_SP_M ******************************
 * ********************************************************************/	
LOG_SP_M::LOG_SP_M(ExtMachInst mach_inst)
    : StaticInst("LOG_SP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
LOG_SP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		SP op = cpu->read_src_sp_operand(this, 0);
		
		/* Execution. */
		SP final = log(op, OP_3);
		
		/* Writing registers. */
		cpu->cache_dst_sp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LOG_SP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}


	
/* *********************************************************************
 * ***************************** LOG_DP_M ******************************
 * ********************************************************************/
LOG_DP_M::LOG_DP_M(ExtMachInst mach_inst)
    : StaticInst("LOG_DP_M", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;

	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
LOG_DP_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		DP op = cpu->read_src_dp_operand(this, 0);
		
		/* Execution. */
		DP final = log(op, OP_3);
		
		/* Writing registers. */
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LOG_DP_M::generate_disassembly() const
{
	std::stringstream ss;
	
	/* Output condition. */
	print_cond(ss);
	
	/* Output instruction mnemonic. */
	print_mnemonic(ss);
	
	/* Output instruction length. */
	print_len(ss);
	
	/* Output insruction unit. */
	print_unit(ss);
	
	/* Output destination registers. */
	print_dst_reg(ss);
	
	/* Output source registers. */
	print_src_reg(ss);
	
	/* Output the immediate. */
	
	return ss.str();
}

//
///* *********************************************************************
// * *************************** SPINT_W_M *******************************
// * ********************************************************************/
//SPINT_W_M::SPINT_W_M(ExtMachInst mach_inst)
//    : StaticInst("SPINT_W_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//SPINT_W_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		SP op = cpu->read_src_sp_operand(this, 0);
//		
//		/* Execution. */
//		S_WORD final = round(op, OP_3);
//		
//		/* Writing registers. */
//		cpu->cache_dst_w_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//SPINT_W_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * *************************** SPINT_DW_M ******************************
// * ********************************************************************/
//SPINT_DW_M::SPINT_DW_M(ExtMachInst mach_inst)
//    : StaticInst("SPINT_DW_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//SPINT_DW_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		SP op = cpu->read_src_sp_operand(this, 0);
//		
//		/* Execution. */
//		S_DWORD final = round(op, OP_3);
//		
//		/* Writing registers. */
//		cpu->cache_dst_dw_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//SPINT_DW_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * *************************** DPINT_W_M *******************************
// * ********************************************************************/
//DPINT_W_M::DPINT_W_M(ExtMachInst mach_inst)
//    : StaticInst("DPINT_W_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//DPINT_W_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		DP op = cpu->read_src_dp_operand(this, 0);
//		
//		/* Execution. */
//		S_WORD final = round(op, OP_3);
//		
//		/* Writing registers. */
//		cpu->cache_dst_w_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//DPINT_W_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * *************************** DPINT_DW_M ******************************
// * ********************************************************************/
//DPINT_DW_M::DPINT_DW_M(ExtMachInst mach_inst)
//    : StaticInst("DPINT_DW_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//DPINT_DW_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		DP op = cpu->read_src_dp_operand(this, 0);
//		
//		/* Execution. */
//		S_DWORD final = round(op, OP_3);
//		
//		/* Writing registers. */
//		cpu->cache_dst_dw_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//DPINT_DW_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * *************************** SPINTU_W_M ******************************
// * ********************************************************************/	
//SPINTU_W_M::SPINTU_W_M(ExtMachInst mach_inst)
//    : StaticInst("SPINTU_W_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//SPINTU_W_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		SP op = cpu->read_src_sp_operand(this, 0);
//		
//		/* Execution. */
//		WORD final = static_cast<WORD>flt_to_uint(op, OP_3);
//		
//		/* Writing registers. */
//		cpu->cache_dst_w_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//SPINTU_W_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * *************************** SPINTU_DW_M *****************************
// * ********************************************************************/
//SPINTU_DW_M::SPINTU_DW_M(ExtMachInst mach_inst)
//    : StaticInst("SPINTU_DW_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//SPINTU_DW_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		SP op = cpu->read_src_sp_operand(this, 0);
//		
//		/* Execution. */
//		DWORD final = static_cast<DWORD>flt_to_uint(op, OP_3);
//		
//		/* Writing registers. */
//		cpu->cache_dst_dw_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//SPINTU_DW_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * *************************** DPINTU_W_M ******************************
// * ********************************************************************/
//DPINTU_W_M::DPINTU_W_M(ExtMachInst mach_inst)
//    : StaticInst("DPINTU_W_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//DPINTU_W_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		DP op = cpu->read_src_dp_operand(this, 0);
//		
//		/* Execution. */
//		WORD final = static_cast<WORD>flt_to_uint(op, OP_3);
//		
//		/* Writing registers. */
//		cpu->cache_dst_w_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//DPINTU_W_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * *************************** DPINTU_DW_M *****************************
// * ********************************************************************/
//DPINTU_DW_M::DPINTU_DW_M(ExtMachInst mach_inst)
//    : StaticInst("DPINTU_DW_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//DPINTU_DW_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		DP op = cpu->read_src_dp_operand(this, 0);
//		
//		/* Execution. */
//		DWORD final = static_cast<DWORD>flt_to_uint(op, OP_3);
//		
//		/* Writing registers. */
//		cpu->cache_dst_dw_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//DPINTU_DW_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * **************************** ROUND_SP_M *****************************
// * ********************************************************************/	
//ROUND_SP_M::ROUND_SP_M(ExtMachInst mach_inst)
//    : StaticInst("ROUND_SP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//ROUND_SP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		SP op = cpu->read_src_sp_operand(this, 0);
//		
//		/* Execution. */
//		SP final = round(op, OP_3);
//		
//		/* Writing registers. */
//		cpu->cache_dst_sp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//ROUND_SP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * **************************** ROUND_DP_M *****************************
// * ********************************************************************/
//ROUND_DP_M::ROUND_DP_M(ExtMachInst mach_inst)
//    : StaticInst("ROUND_DP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//ROUND_DP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		DP op = cpu->read_src_dp_operand(this, 0);
//		
//		/* Execution. */
//		DP final = round(op, OP_3);
//		
//		/* Writing registers. */
//		cpu->cache_dst_dp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//ROUND_DP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
//
///* *********************************************************************
// * **************************** W_INTSP_M ******************************
// * ********************************************************************/	
//W_INTSP_M::W_INTSP_M(ExtMachInst mach_inst)
//    : StaticInst("W_INTSP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//W_INTSP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		S_WORD op = cpu->read_src_w_operand(this, 0);
//		
//		/* Execution. */
//		SP final = int_uint_flt(op);
//		
//		/* Writing registers. */
//		cpu->cache_dst_sp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//W_INTSP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * **************************** W_INTDP_M ******************************
// * ********************************************************************/
//W_INTDP_M::W_INTDP_M(ExtMachInst mach_inst)
//    : StaticInst("W_INTDP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//W_INTDP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		S_WORD op = cpu->read_src_w_operand(this, 0);
//		
//		/* Execution. */
//		DP final = int_uint_flt(op);
//		
//		/* Writing registers. */
//		cpu->cache_dst_dp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//W_INTDP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//	
///* *********************************************************************
// * **************************** DW_INTSP_M *****************************
// * ********************************************************************/
//DW_INTSP_M::DW_INTSP_M(ExtMachInst mach_inst)
//    : StaticInst("DW_INTSP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//DW_INTSP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		S_DWORD op = cpu->read_src_dw_operand(this, 0);
//		
//		/* Execution. */
//		SP final = int_uint_flt(op);
//		
//		/* Writing registers. */
//		cpu->cache_dst_sp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//DW_INTSP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//		
///* *********************************************************************
// * **************************** DW_INTDP_M *****************************
// * ********************************************************************/	
//DW_INTDP_M::DW_INTDP_M(ExtMachInst mach_inst)
//    : StaticInst("DW_INTDP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//DW_INTDP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		S_DWORD op = cpu->read_src_dw_operand(this, 0);
//		
//		/* Execution. */
//		DP final = int_uint_flt(op);
//		
//		/* Writing registers. */
//		cpu->cache_dst_dp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//DW_INTDP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * *************************** W_INTUSP_M ******************************
// * ********************************************************************/	
//W_INTUSP_M::W_INTUSP_M(ExtMachInst mach_inst)
//    : StaticInst("W_INTUSP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//W_INTUSP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		WORD op = cpu->read_src_w_operand(this, 0);
//		
//		/* Execution. */
//		SP final = int_uint_flt(op);
//		
//		/* Writing registers. */
//		cpu->cache_dst_sp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//W_INTUSP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//		
///* *********************************************************************
// * *************************** W_INTUDP_M ******************************
// * ********************************************************************/
//W_INTUDP_M::W_INTUDP_M(ExtMachInst mach_inst)
//    : StaticInst("W_INTUDP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//W_INTUDP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		WORD op = cpu->read_src_w_operand(this, 0);
//		
//		/* Execution. */
//		DP final = int_uint_flt(op);
//		
//		/* Writing registers. */
//		cpu->cache_dst_dp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//W_INTUDP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
///* *********************************************************************
// * *************************** DW_INTUSP_M *****************************
// * ********************************************************************/
//DW_INTUSP_M::DW_INTUSP_M(ExtMachInst mach_inst)
//    : StaticInst("DW_INTUSP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//DW_INTUSP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		DWORD op = cpu->read_src_dw_operand(this, 0);
//		
//		/* Execution. */
//		SP final = int_uint_flt(op);
//		
//		/* Writing registers. */
//		cpu->cache_dst_sp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//DW_INTUSP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
///* *********************************************************************
// * *************************** DW_INTUDP_M *****************************
// * ********************************************************************/
//DW_INTUDP_M::DW_INTUDP_M(ExtMachInst mach_inst)
//    : StaticInst("DW_INTUDP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//DW_INTUDP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		DWORD op = cpu->read_src_dw_operand(this, 0);
//		
//		/* Execution. */
//		DP final = int_uint_flt(op);
//		
//		/* Writing registers. */
//		cpu->cache_dst_dp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//DW_INTUDP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * ***************************** SPDP_M ********************************
// * ********************************************************************/	
//SPDP_M::SPDP_M(ExtMachInst mach_inst)
//    : StaticInst("SPDP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//SPDP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		SP op = cpu->read_src_sp_operand(this, 0);
//		
//		/* Execution. */
//		DP final = static_cast<DP>flt_to_doub(op);
//		
//		/* Writing registers. */
//		cpu->cache_dst_dp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//SPDP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
//
///* *********************************************************************
// * **************************** DPSP_M *********************************
// * ********************************************************************/	
//DPSP_M::DPSP_M(ExtMachInst mach_inst)
//    : StaticInst("DPSP_M", mach_inst)
//{
//	/* Flags. */
//	_flags[Is_32_Bit ]  = true;
//	_flags[Is_Cond   ]  = true;
//
//	
//	/* Unit. */
//	/* Parameters: A/M/D. */
//	init_unit(M);
//	
//	/* Immediate. */
//	/* Parameters: imm, imm_len. */
//	
//	/* Registers. */
//	/* Parameters: num_src_regs, num_dst_regs, ... */
//	init_src_regs(1, REG, RS_1_A);
//	init_dst_regs(1, REG, RD_A, 0);
//}
//
//void
//DPSP_M::execute(RiscCPU *cpu) const
//{
//	if(cond_execute(cpu)) {
//		/* Reading registers. */
//		DP op = cpu->read_src_dp_operand(this, 0);
//		
//		/* Execution. */
//		SP final = static_cast<SP>doub_to_flt(op, OP_3, 5);
//		
//		/* Writing registers. */
//		cpu->cache_dst_sp_operand(this, 0, final);
//	}
//	else {
//		_d_ptr->set_op2nop();
//	}
//}
//
//std::string
//DPSP_M::generate_disassembly() const
//{
//	std::stringstream ss;
//	
//	/* Output condition. */
//	print_cond(ss);
//	
//	/* Output instruction mnemonic. */
//	print_mnemonic(ss);
//	
//	/* Output instruction length. */
//	print_len(ss);
//	
//	/* Output insruction unit. */
//	print_unit(ss);
//	
//	/* Output destination registers. */
//	print_dst_reg(ss);
//	
//	/* Output source registers. */
//	print_src_reg(ss);
//	
//	/* Output the immediate. */
//	
//	return ss.str();
//}
} // namespace LILY2_NS;

