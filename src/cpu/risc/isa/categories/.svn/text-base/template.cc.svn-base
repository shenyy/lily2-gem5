/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 06 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "template.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * *************************** TEMPLATE ********************************
 * ********************************************************************/	
TEMPLATE::TEMPLATE(ExtMachInst mach_inst)
    : StaticInst("TEMPLATE", mach_inst)
{
	/* Flags. */
	_flags[Is_16_Bit ]  = true;
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Mode   ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Nop    ]  = true;
	_flags[Is_Unknown]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	_flags[Is_Store  ]  = true;
	_flags[Is_Control]  = true;
	_flags[Is_Call   ]  = true;
	_flags[Is_Return ]  = true;
	_flags[Is_Eoc    ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(A/M/D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(num_src_regs, ...);
	init_dst_regs(num_dst_regs, ...);
}

void
TEMPLATE::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD op_0 = cpu->read_src_w_operand(this, 0);
		S_WORD op_0 = cpu->read_src_w_operand(this, 0);
		DWORD op_0 = cpu->read_src_dw_operand(this, 0);
		S_DWORD op_0 = cpu->read_src_dw_operand(this, 0);
		QWORD op_0 = cpu->read_src_qw_operand(this, 0);
		SP op_0 = cpu->read_src_sp_operand(this, 0);
		DP op_0 = cpu->read_src_dp_operand(this, 0);
		
		/* Execution. */
		WORD final = ...;
		S_WORD final = ...;
		DWORD final = ...;
		S_DWORD final = ...;
		QWORD final = ...;
		SP final = ...;
		DP final = ...;
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		cpu->cache_dst_dw_operand(this, 0, final);
		cpu->cache_dst_qw_operand(this, 0, final);
		cpu->cache_dst_sp_operand(this, 0, final);
		cpu->cache_dst_dp_operand(this, 0, final);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
TEMPLATE::generate_disassembly() const
{
	return print_inst();
	return print_inst_imm();
	return print_inst_mem_no_offset();
	return print_inst_mem_offset();
	return print_inst_mem_offset_imm();
}
	
} // namespace LILY2_NS
