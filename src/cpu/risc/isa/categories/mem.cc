/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "mem.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"
#include "mem/request.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * ************************* LDB_NO_OFFSET_D ***************************
 * ********************************************************************/	
LDB_NO_OFFSET_D::LDB_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("LDB", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDB_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 1;
		uint8_t mem[1];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = sext<8>(*reinterpret_cast<int8_t *>(mem));
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDB_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** LDB_D *********************************
 * ********************************************************************/	
LDB_D::LDB_D(ExtMachInst mach_inst)
    : StaticInst("LDB", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDB_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset; 
		int size = 1;
		uint8_t mem[1];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = sext<8>(*reinterpret_cast<int8_t *>(mem));
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDB_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** LDBI_D ********************************
 * ********************************************************************/	
LDBI_D::LDBI_D(ExtMachInst mach_inst)
    : StaticInst("LDB", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDBI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset; break; }
			case 0x1: { eff_addr = base-offset; break; }
			case 0x2: { eff_addr = base+offset; break; }
			case 0x3: { eff_addr = base-offset; break; }
		}
		int size = 1;
		uint8_t mem[1];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = sext<8>(*reinterpret_cast<int8_t *>(mem));
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDBI_D::generate_disassembly() const
{
	return print_inst_mem_offset_imm();
}

/* *********************************************************************
 * ************************* LDBU_NO_OFFSET_D **************************
 * ********************************************************************/	
LDBU_NO_OFFSET_D::LDBU_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("LDBU", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDBU_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 1;
		uint8_t mem[1];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = bits((*reinterpret_cast<int8_t *>(mem)), 7, 0);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDBU_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** LDBU_D ********************************
 * ********************************************************************/	
LDBU_D::LDBU_D(ExtMachInst mach_inst)
    : StaticInst("LDBU", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDBU_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset; 
		int size = 1;
		uint8_t mem[1];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = bits(*reinterpret_cast<int8_t *>(mem), 7, 0);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDBU_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** LDBUI_D *******************************
 * ********************************************************************/	
LDBUI_D::LDBUI_D(ExtMachInst mach_inst)
    : StaticInst("LDBU", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDBUI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset; break; }
			case 0x1: { eff_addr = base-offset; break; }
			case 0x2: { eff_addr = base+offset; break; }
			case 0x3: { eff_addr = base-offset; break; }
		}
		int size = 1;
		uint8_t mem[1];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = bits(*reinterpret_cast<int8_t *>(mem), 7, 0);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDBUI_D::generate_disassembly() const
{
	return print_inst_mem_offset_imm();
}

/* *********************************************************************
 * ************************* LDH_NO_OFFSET_D ***************************
 * ********************************************************************/	
LDH_NO_OFFSET_D::LDH_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("LDH", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDH_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 2;
		uint8_t mem[2];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = sext<16>(*reinterpret_cast<int16_t *>(mem));
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDH_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** LDH_D *********************************
 * ********************************************************************/	
LDH_D::LDH_D(ExtMachInst mach_inst)
    : StaticInst("LDH", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDH_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset; 
		int size = 2;
		uint8_t mem[2];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = sext<16>(*reinterpret_cast<int16_t *>(mem));
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDH_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** LDHI_D ********************************
 * ********************************************************************/	
LDHI_D::LDHI_D(ExtMachInst mach_inst)
    : StaticInst("LDH", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDHI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset;   break; }
			case 0x1: { eff_addr = base-offset;   break; }
			case 0x2: { eff_addr = base+offset*2; break; }
			case 0x3: { eff_addr = base-offset*2; break; }
		}
		int size = 2;
		uint8_t mem[2];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = sext<16>(*reinterpret_cast<int16_t *>(mem));
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDHI_D::generate_disassembly() const
{
	return print_inst_mem_offset_imm();
}

/* *********************************************************************
 * ************************* LDHU_NO_OFFSET_D **************************
 * ********************************************************************/	
LDHU_NO_OFFSET_D::LDHU_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("LDHU", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDHU_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 2;
		uint8_t mem[2];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = bits(*reinterpret_cast<int16_t *>(mem), 15, 0);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDHU_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** LDHU_D ********************************
 * ********************************************************************/	
LDHU_D::LDHU_D(ExtMachInst mach_inst)
    : StaticInst("LDHU", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDHU_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset; 
		int size = 2;
		uint8_t mem[2];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = bits(*reinterpret_cast<int16_t *>(mem), 15, 0);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDHU_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** LDHUI_D *******************************
 * ********************************************************************/	
LDHUI_D::LDHUI_D(ExtMachInst mach_inst)
    : StaticInst("LDHU", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDHUI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset;   break; }
			case 0x1: { eff_addr = base-offset;   break; }
			case 0x2: { eff_addr = base+offset*2; break; }
			case 0x3: { eff_addr = base-offset*2; break; }
		}
		int size = 2;
		uint8_t mem[2];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = bits(*reinterpret_cast<int16_t *>(mem), 15, 0);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDHUI_D::generate_disassembly() const
{
	return print_inst_mem_offset_imm();
}

/* *********************************************************************
 * ************************* LDW_NO_OFFSET_D ***************************
 * ********************************************************************/	
LDW_NO_OFFSET_D::LDW_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("LDW", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDW_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 4;
		uint8_t mem[4];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = *reinterpret_cast<int32_t *>(mem);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDW_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** LDW_D *********************************
 * ********************************************************************/	
LDW_D::LDW_D(ExtMachInst mach_inst)
    : StaticInst("LDW", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDW_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset; 
		int size = 4;
		uint8_t mem[4];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = *reinterpret_cast<int32_t *>(mem);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDW_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** LDWI_D ********************************
 * ********************************************************************/	
LDWI_D::LDWI_D(ExtMachInst mach_inst)
    : StaticInst("LDW", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDWI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset;   break; }
			case 0x1: { eff_addr = base-offset;   break; }
			case 0x2: { eff_addr = base+offset*4; break; }
			case 0x3: { eff_addr = base-offset*4; break; }
		}
		int size = 4;
		uint8_t mem[4];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		WORD final = *reinterpret_cast<int32_t *>(mem);
		
		/* Writing registers. */
		cpu->cache_dst_w_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDWI_D::generate_disassembly() const
{
	return print_inst_mem_offset_imm();
}

/* *********************************************************************
 * ************************* LDD_NO_OFFSET_D ***************************
 * ********************************************************************/	
LDD_NO_OFFSET_D::LDD_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("LDD", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDD_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 8;
		uint8_t mem[8];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		DWORD final = *reinterpret_cast<int64_t *>(mem);
		
		/* Writing registers. */
		cpu->cache_dst_dw_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDD_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** LDD_D *********************************
 * ********************************************************************/	
LDD_D::LDD_D(ExtMachInst mach_inst)
    : StaticInst("LDD", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDD_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset; 
		int size = 8;
		uint8_t mem[8];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		DWORD final = *reinterpret_cast<int64_t *>(mem);
		
		/* Writing registers. */
		cpu->cache_dst_dw_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDD_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** LDDI_D ********************************
 * ********************************************************************/	
LDDI_D::LDDI_D(ExtMachInst mach_inst)
    : StaticInst("LDD", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDDI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset;   break; }
			case 0x1: { eff_addr = base-offset;   break; }
			case 0x2: { eff_addr = base+offset*4; break; }
			case 0x3: { eff_addr = base-offset*4; break; }
		}
		int size = 8;
		uint8_t mem[8];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		DWORD final = *reinterpret_cast<int64_t *>(mem);
		
		/* Writing registers. */
		cpu->cache_dst_dw_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDDI_D::generate_disassembly() const
{
	return print_inst_mem_offset_imm();
}

/* *********************************************************************
 * ************************* LDQ_NO_OFFSET_D ***************************
 * ********************************************************************/	
LDQ_NO_OFFSET_D::LDQ_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("LDQ", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDQ_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 16;
		uint8_t mem[16];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		QWORD final;
		final._h0 = *reinterpret_cast<int32_t *>(mem);
		final._h1 = *reinterpret_cast<int32_t *>(mem+4);
		final._h2 = *reinterpret_cast<int32_t *>(mem+8);
		final._h3 = *reinterpret_cast<int32_t *>(mem+12);
		
		/* Writing registers. */
		cpu->cache_dst_qw_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDQ_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** LDQ_D *********************************
 * ********************************************************************/	
LDQ_D::LDQ_D(ExtMachInst mach_inst)
    : StaticInst("LDQ", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDQ_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset; 
		int size = 16;
		uint8_t mem[16];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		QWORD final;
		final._h0 = *reinterpret_cast<int32_t *>(mem);
		final._h1 = *reinterpret_cast<int32_t *>(mem+4);
		final._h2 = *reinterpret_cast<int32_t *>(mem+8);
		final._h3 = *reinterpret_cast<int32_t *>(mem+12);
		
		/* Writing registers. */
		cpu->cache_dst_qw_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDQ_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** LDQI_D ********************************
 * ********************************************************************/	
LDQI_D::LDQI_D(ExtMachInst mach_inst)
    : StaticInst("LDQ", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Load   ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(1, REG, RS_1_A);
	init_dst_regs(1, REG, RD_A, 3);
}

void
LDQI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset;   break; }
			case 0x1: { eff_addr = base-offset;   break; }
			case 0x2: { eff_addr = base+offset*4; break; }
			case 0x3: { eff_addr = base-offset*4; break; }
		}
		int size = 4;
		uint8_t mem[16];
		Request::Flags mem_access_flags;
		cpu->readMem(eff_addr, mem, size, mem_access_flags);
		QWORD final;
		final._h0 = *reinterpret_cast<int32_t *>(mem);
		final._h1 = *reinterpret_cast<int32_t *>(mem+4);
		final._h2 = *reinterpret_cast<int32_t *>(mem+8);
		final._h3 = *reinterpret_cast<int32_t *>(mem+12);
		
		/* Writing registers. */
		cpu->cache_dst_qw_operand(this, 0, final);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
LDQI_D::generate_disassembly() const
{
	return print_inst_mem_offset_imm();
}


/* *********************************************************************
 * ************************* STB_NO_OFFSET_D ***************************
 * ********************************************************************/	
STB_NO_OFFSET_D::STB_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("STB", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RD_A);
}

void
STB_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD op = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 1;
		uint8_t mem[1];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		//memset(mem, op, 1);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STB_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** STB_D *********************************
 * ********************************************************************/	
STB_D::STB_D(ExtMachInst mach_inst)
    : StaticInst("STB", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
}

void
STB_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		WORD op = cpu->read_src_w_operand(this, 2);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset;
		int size = 1;
		uint8_t mem[1];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		//memset(mem, op, 1);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STB_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** STBI_D ********************************
 * ********************************************************************/	
STBI_D::STBI_D(ExtMachInst mach_inst)
    : StaticInst("STB", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RD_A);
}

void
STBI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD op = cpu->read_src_w_operand(this, 1);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset; break; }
			case 0x1: { eff_addr = base-offset; break; }
			case 0x2: { eff_addr = base+offset; break; }
			case 0x3: { eff_addr = base-offset; break; }
		}
		int size = 1;
		uint8_t mem[1];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		//memset(mem, op, 1);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STBI_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ************************* STH_NO_OFFSET_D ***************************
 * ********************************************************************/	
STH_NO_OFFSET_D::STH_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("STH", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RD_A);
}

void
STH_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD op = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 2;
		uint8_t mem[2];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		mem[1] = bits(op,15,8);
		//memset(mem, op, 2);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STH_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** STH_D *********************************
 * ********************************************************************/	
STH_D::STH_D(ExtMachInst mach_inst)
    : StaticInst("STH", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
}

void
STH_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		WORD op = cpu->read_src_w_operand(this, 2);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset;
		int size = 2;
		uint8_t mem[2];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		mem[1] = bits(op,15,8);
		//memset(mem, op, 2);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STH_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** STHI_D ********************************
 * ********************************************************************/	
STHI_D::STHI_D(ExtMachInst mach_inst)
    : StaticInst("STH", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RD_A);
}

void
STHI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD op = cpu->read_src_w_operand(this, 1);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset;   break; }
			case 0x1: { eff_addr = base-offset;   break; }
			case 0x2: { eff_addr = base+offset*2; break; }
			case 0x3: { eff_addr = base-offset*2; break; }
		}
		int size = 2;
		uint8_t mem[2];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		mem[1] = bits(op,15,8);
		//memset(mem, op, 2);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STHI_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ************************* STW_NO_OFFSET_D ***************************
 * ********************************************************************/	
STW_NO_OFFSET_D::STW_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("STW", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RD_A);
}

void
STW_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD op = cpu->read_src_w_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 4;
		uint8_t mem[4];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		mem[1] = bits(op,15,8);
		mem[2] = bits(op,23,16);
		mem[3] = bits(op,31,24);
		//memset(mem, op, 4);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STW_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** STW_D *********************************
 * ********************************************************************/	
STW_D::STW_D(ExtMachInst mach_inst)
    : StaticInst("STW", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
}

void
STW_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		WORD op = cpu->read_src_w_operand(this, 2);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset;
		int size = 4;
		uint8_t mem[4];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		mem[1] = bits(op,15,8);
		mem[2] = bits(op,23,16);
		mem[3] = bits(op,31,24);
		//memset(mem, op, 4);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STW_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** STWI_D ********************************
 * ********************************************************************/	
STWI_D::STWI_D(ExtMachInst mach_inst)
    : StaticInst("STW", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RD_A);
}

void
STWI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD op = cpu->read_src_w_operand(this, 1);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset;   break; }
			case 0x1: { eff_addr = base-offset;   break; }
			case 0x2: { eff_addr = base+offset*4; break; }
			case 0x3: { eff_addr = base-offset*4; break; }
		}
		int size = 4;
		uint8_t mem[4];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		mem[1] = bits(op,15,8);
		mem[2] = bits(op,23,16);
		mem[3] = bits(op,31,24);
		//memset(mem, op, 4);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STWI_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}
	
/* *********************************************************************
 * ************************* STD_NO_OFFSET_D ***************************
 * ********************************************************************/	
STD_NO_OFFSET_D::STD_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("ST.D", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RD_A);
}

void
STD_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		DWORD op = cpu->read_src_dw_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 8;
		uint8_t mem[8];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		mem[1] = bits(op,15,8);
		mem[2] = bits(op,23,16);
		mem[3] = bits(op,31,24);
		mem[4] = bits(op,39,32);
		mem[5] = bits(op,47,40);
		mem[6] = bits(op,55,48);
		mem[7] = bits(op,63,56);
		//memset(mem, op, 4);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STD_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** STD_D *********************************
 * ********************************************************************/	
STD_D::STD_D(ExtMachInst mach_inst)
    : StaticInst("ST.D", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
}

void
STD_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		DWORD op = cpu->read_src_dw_operand(this, 2);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset;
		int size = 8;
		uint8_t mem[8];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		mem[1] = bits(op,15,8);
		mem[2] = bits(op,23,16);
		mem[3] = bits(op,31,24);
		mem[4] = bits(op,39,32);
		mem[5] = bits(op,47,40);
		mem[6] = bits(op,55,48);
		mem[7] = bits(op,63,56);
		//memset(mem, op, 4);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STD_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** STDI_D ********************************
 * ********************************************************************/	
STDI_D::STDI_D(ExtMachInst mach_inst)
    : StaticInst("ST.D", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RD_A);
}

void
STDI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		DWORD op = cpu->read_src_dw_operand(this, 1);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset;   break; }
			case 0x1: { eff_addr = base-offset;   break; }
			case 0x2: { eff_addr = base+offset*4; break; }
			case 0x3: { eff_addr = base-offset*4; break; }
		}
		int size = 8;
		uint8_t mem[8];
		Request::Flags mem_access_flags;
		mem[0] = bits(op,7,0);
		mem[1] = bits(op,15,8);
		mem[2] = bits(op,23,16);
		mem[3] = bits(op,31,24);
		mem[4] = bits(op,39,32);
		mem[5] = bits(op,47,40);
		mem[6] = bits(op,55,48);
		mem[7] = bits(op,63,56);
		//memset(mem, op, 4);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STDI_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ************************* STQ_NO_OFFSET_D ***************************
 * ********************************************************************/	
STQ_NO_OFFSET_D::STQ_NO_OFFSET_D(ExtMachInst mach_inst)
    : StaticInst("ST.Q", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RD_A);
}

void
STQ_NO_OFFSET_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		QWORD op = cpu->read_src_qw_operand(this, 1);
		
		/* Execution. */
		Addr eff_addr = base;
		int size = 16;
		uint8_t mem[16];
		Request::Flags mem_access_flags;
		mem[0] = bits(op._h0,7,0);
		mem[1] = bits(op._h0,15,8);
		mem[2] = bits(op._h0,23,16);
		mem[3] = bits(op._h0,31,24);
		mem[4] = bits(op._h1,39,32);
		mem[5] = bits(op._h1,47,40);
		mem[6] = bits(op._h1,55,48);
		mem[7] = bits(op._h1,63,56);
		mem[8] = bits(op._h2,71,64);
		mem[9] = bits(op._h2,79,72);
		mem[10] = bits(op._h2,87,80);
		mem[11] = bits(op._h2,95,88);
		mem[12] = bits(op._h3,103,96);
		mem[13] = bits(op._h3,111,104);
		mem[14] = bits(op._h3,119,112);
		mem[15] = bits(op._h3,127,120);
		//memset(mem, op, 4);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STQ_NO_OFFSET_D::generate_disassembly() const
{
	return print_inst_mem_no_offset();
}

/* *********************************************************************
 * ***************************** STQ_D *********************************
 * ********************************************************************/	
STQ_D::STQ_D(ExtMachInst mach_inst)
    : StaticInst("ST.Q", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	//init_imm(imm, imm_len);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
}

void
STQ_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		WORD offset = cpu->read_src_w_operand(this, 1);
		QWORD op = cpu->read_src_qw_operand(this, 2);
		
		/* Execution. */
		Addr eff_addr = bits(MODE,0,0) ? base-offset : base+offset;
		int size = 16;
		uint8_t mem[16];
		Request::Flags mem_access_flags;
		mem[0] = bits(op._h0,7,0);
		mem[1] = bits(op._h0,15,8);
		mem[2] = bits(op._h0,23,16);
		mem[3] = bits(op._h0,31,24);
		mem[4] = bits(op._h1,39,32);
		mem[5] = bits(op._h1,47,40);
		mem[6] = bits(op._h1,55,48);
		mem[7] = bits(op._h1,63,56);
		mem[8] = bits(op._h2,71,64);
		mem[9] = bits(op._h2,79,72);
		mem[10] = bits(op._h2,87,80);
		mem[11] = bits(op._h2,95,88);
		mem[12] = bits(op._h3,103,96);
		mem[13] = bits(op._h3,111,104);
		mem[14] = bits(op._h3,119,112);
		mem[15] = bits(op._h3,127,120);
		//memset(mem, op, 4);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STQ_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

/* *********************************************************************
 * ***************************** STQI_D ********************************
 * ********************************************************************/	
STQI_D::STQI_D(ExtMachInst mach_inst)
    : StaticInst("ST.Q", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Cond   ]  = true;
	_flags[Is_Mem_Ref]  = true;
	_flags[Is_Store  ]  = true;
	
	/* Unit. */
	/* Parameters: A/M/D. */
	init_unit(D);
	
	/* Immediate. */
	/* Parameters: imm, imm_len. */
	init_imm(CST5_A, 5);
	
	/* Registers. */
	/* Parameters: num_src_regs, num_dst_regs, ... */
	init_src_regs(2, REG, RS_1_A, REG, RD_A);
}

void
STQI_D::execute(RiscCPU *cpu) const
{
	if(cond_execute(cpu)) {
		/* Reading registers. */
		WORD base = cpu->read_src_w_operand(this, 0);
		QWORD op = cpu->read_src_qw_operand(this, 1);
		WORD offset = _imm;
		
		/* Execution. */
		Addr eff_addr;
		switch(bits(MODE,1,0)) {
			case 0x0: { eff_addr = base+offset;   break; }
			case 0x1: { eff_addr = base-offset;   break; }
			case 0x2: { eff_addr = base+offset*4; break; }
			case 0x3: { eff_addr = base-offset*4; break; }
		}
		int size = 16;
		uint8_t mem[16];
		Request::Flags mem_access_flags;
		mem[0] = bits(op._h0,7,0);
		mem[1] = bits(op._h0,15,8);
		mem[2] = bits(op._h0,23,16);
		mem[3] = bits(op._h0,31,24);
		mem[4] = bits(op._h1,39,32);
		mem[5] = bits(op._h1,47,40);
		mem[6] = bits(op._h1,55,48);
		mem[7] = bits(op._h1,63,56);
		mem[8] = bits(op._h2,71,64);
		mem[9] = bits(op._h2,79,72);
		mem[10] = bits(op._h2,87,80);
		mem[11] = bits(op._h2,95,88);
		mem[12] = bits(op._h3,103,96);
		mem[13] = bits(op._h3,111,104);
		mem[14] = bits(op._h3,119,112);
		mem[15] = bits(op._h3,127,120);
		//memset(mem, op, 4);
		cpu->writeMem(mem, size, eff_addr, mem_access_flags, NULL);
		
		/* Dynamic information. */
		_d_ptr->set_mem_ref_addr(eff_addr);
	}
	else {
		_d_ptr->set_op2nop();
	}
}

std::string
STQI_D::generate_disassembly() const
{
	return print_inst_mem_offset();
}

} // namespace LILY2_NS
