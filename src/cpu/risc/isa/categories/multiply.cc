/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 23 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "multiply.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * *************************** MULSL_M *********************************
 * ********************************************************************/	
MULSL_M::MULSL_M(ExtMachInst mach_inst)
    : StaticInst("MUL.S.L", mach_inst)
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
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 1);
}

void
MULSL_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = mul(sext<16>(bits(op_0, 15, 0)), \
		    sext<16>(bits(op_1, 15, 0)));
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
MULSL_M::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** DIV_M ***********************************
 * ********************************************************************/	
DIV_M::DIV_M(ExtMachInst mach_inst)
    : StaticInst("DIV", mach_inst)
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
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 1);
}

void
DIV_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = div(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
DIV_M::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * *************************** DIVU_M **********************************
 * ********************************************************************/	
DIVU_M::DIVU_M(ExtMachInst mach_inst)
    : StaticInst("DIVU", mach_inst)
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
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 1);
}

void
DIVU_M::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		WORD op_1 = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		WORD final = div(op_0, op_1);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
DIVU_M::generate_disassembly() const
{
	return print_inst();
}
	
} // namespace LILY2_NS
