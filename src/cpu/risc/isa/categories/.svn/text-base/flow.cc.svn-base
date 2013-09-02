/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 23 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "flow.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * *************************** CALL_D **********************************
 * ********************************************************************/	
CALL_D::CALL_D(ExtMachInst mach_inst)
    : StaticInst("CALL", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Control]  = true;
	_flags[Is_Call   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<20>(CST20_A), 20);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(0);
	init_dst_regs(0);
}

void
CALL_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		Addr cur_addr = cpu->get_inst_addr();
		Addr branch_target = cur_addr + static_cast<int32_t>(_imm << 1);
		Addr return_target = cur_addr + 4;
		
		/* Execution. */
		cpu->set_return_target(return_target);
		
		/* Dynamic information. */
		_d_ptr->set_branch_target(branch_target);
		_d_ptr->set_return_target(return_target);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CALL_D::generate_disassembly() const
{
	return print_inst_imm();
}

/* *********************************************************************
 * *************************** CALLR_D *********************************
 * ********************************************************************/	
CALLR_D::CALLR_D(ExtMachInst mach_inst)
    : StaticInst("CALL", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Control]  = true;
	_flags[Is_Call   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(0);
}

void
CALLR_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		Addr cur_addr = cpu->get_inst_addr();
		Addr branch_target = cpu->read_src_w_operand(this, 0);
		Addr return_target = cur_addr + 4;
		
		/* Execution. */
		cpu->set_return_target(return_target);
		
		/* Dynamic information. */
		_d_ptr->set_branch_target(branch_target);
		_d_ptr->set_return_target(return_target);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
CALLR_D::generate_disassembly() const
{
	return print_inst();
}

/* *********************************************************************
 * ***************************** B_D ***********************************
 * ********************************************************************/	
B_D::B_D(ExtMachInst mach_inst)
    : StaticInst("B", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Control]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(sext<20>(CST20_A), 20);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(0);
	init_dst_regs(0);
}

void
B_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		Addr cur_addr = cpu->get_inst_addr();
		Addr branch_target = cur_addr + static_cast<int32_t>(_imm << 1);
		
		/* Execution. */
		
		/* Dynamic information. */
		_d_ptr->set_branch_target(branch_target);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
B_D::generate_disassembly() const
{
	return print_inst_imm();
}	

/* *********************************************************************
 * ***************************** BR_D **********************************
 * ********************************************************************/	
BR_D::BR_D(ExtMachInst mach_inst)
    : StaticInst("B", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Control]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(0);
}

void
BR_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		Addr branch_target = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		
		/* Dynamic information. */
		_d_ptr->set_branch_target(branch_target);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
BR_D::generate_disassembly() const
{
	return print_inst();
}	

/* *********************************************************************
 * *************************** RET16_D *********************************
 * ********************************************************************/	
RET16_D::RET16_D(ExtMachInst mach_inst)
    : StaticInst("RET", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Control]  = true;
	_flags[Is_Return ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(0);
	init_dst_regs(0);
}

void
RET16_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		Addr branch_target = cpu->get_return_target();
		
		/* Execution. */
		
		/* Dynamic information. */
		_d_ptr->set_branch_target(branch_target);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
RET16_D::generate_disassembly() const
{
	return print_inst();
}

} // namespace LILY2_NS
