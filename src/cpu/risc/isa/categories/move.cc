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
	_flags[Is_Cond   ]  = false;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<16>(SCST16), 16);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(0);
	init_dst_regs(1, REG, RD_B, 0);
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
	_flags[Is_Cond   ]  = false;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(M);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<16>(SCST16), 16);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(0);
	init_dst_regs(1, REG, RD_B, 0);
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
    : StaticInst("MOV.RC", mach_inst)
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
    : StaticInst("MOV.R", mach_inst)
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
	
/* *********************************************************************
 * *************************** MOVQ_D **********************************
 * ********************************************************************/	
MOVQ_D::MOVQ_D(ExtMachInst mach_inst)
    : StaticInst("MOV.Q", mach_inst)
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
	init_dst_regs(1, REG, RD_A, 0);
}

void
MOVQ_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		QWORD op = cpu->read_src_qw_operand(this, 0);
		
		/* Execution. */
		QWORD final = op;
		
		/* Writing registers. */
		cpu->cache_dst_qw_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MOVQ_D::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** MOVQF_D **********************************
 * ********************************************************************/	
MOVQF_D::MOVQF_D(ExtMachInst mach_inst)
    : StaticInst("MOV.QF", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<5>(CST5_A), 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	//init_src_regs(num_src_regs, ...);
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
MOVQF_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		QWORD op = cpu->read_src_qw_operand(this, 0);
		
		/* Execution. */
		WORD final = QFselect(op, _imm);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MOVQF_D::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** MOVFQ_D **********************************
 * ********************************************************************/	
MOVFQ_D::MOVFQ_D(ExtMachInst mach_inst)
    : StaticInst("MOV.FQ", mach_inst)
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
	//init_src_regs(num_src_regs, ...);
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 0);
}

void
MOVFQ_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		WORD final = op;
		
		/* Writing registers. */
		switch(_imm)
		{
			case 0:
				cpu->cache_dst_qw_h0_operand(this, 0, final);
				break;
			case 1: 
				cpu->cache_dst_qw_h1_operand(this, 0, final);
				break;
			case 2: 
				cpu->cache_dst_qw_h2_operand(this, 0, final);
				break;
			case 3: 
				cpu->cache_dst_qw_h3_operand(this, 0, final);
				break;
			default: 
				cpu->cache_dst_qw_h0_operand(this, 0, final);
				break;
		}
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MOVFQ_D::generate_disassembly() const
{
	return print_inst();
}

} // namespace LILY2_NS
