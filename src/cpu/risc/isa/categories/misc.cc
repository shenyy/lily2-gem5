/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 23 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "misc.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * ****************************** EOC **********************************
 * ********************************************************************/	
EOC::EOC(ExtMachInst mach_inst)
    : StaticInst("EOC", mach_inst)
{
	/* Flags. */
	_flags[Is_32_Bit ]  = true;
	_flags[Is_Eoc    ]  = true;
}

void
EOC::execute(RiscCPU *cpu) const
{
}

std::string
EOC::generate_disassembly() const
{
	return "";
}

/* *********************************************************************
 * *************************** UNKNOWN *********************************
 * ********************************************************************/	
UNKNOWN::UNKNOWN(ExtMachInst mach_inst)
    : StaticInst("UNKNOWN", mach_inst)
{
	/* Flags. */
	_flags[Is_Unknown]  = true;
}

void
UNKNOWN::execute(RiscCPU *cpu) const
{
}

std::string
UNKNOWN::generate_disassembly() const
{
	return csprintf("%-10s (inst 0x%x)", "unknown", _mach_inst);
}
	
} // namespace LILY2_NS
