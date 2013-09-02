/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#include "static_inst.hh"
#include "cpu/risc/cpu.hh"

namespace LILY2_NS
{
	
StaticInst::StaticInst(const char *mnemonic, ExtMachInst mach_inst)
    : _num_src_regs(0), _num_dst_regs(0),
      _unit(No_Unit), _imm(0), _imm_len(0),
      _mach_inst(mach_inst), _mnemonic(mnemonic),
      _d_ptr(new DynInst())
{
}

StaticInst::~StaticInst(void)
{
}

int
StaticInst::get_total_num_src_regs(void)
{
	int total = 0;
	FOR(i,0,_num_src_regs) total += _src_reg_type[i];
	return total;
}

int
StaticInst::get_total_num_dst_regs(void)
{
	int total = 0;
	FOR(i,0,_num_dst_regs) total += _dst_reg_type[i];
	return total;
}

void
StaticInst::init_src_regs(int num_src_regs, ...)
{
	va_list vl;
	va_start(vl, num_src_regs);
	_num_src_regs = num_src_regs;
	
	FOR(i,0,_num_src_regs) {
		_src_reg_type[i] = (RegType)va_arg(vl, int);
		_src_reg_idx[i] = gen_p2v(va_arg(vl, int));
	}
	
	va_end(vl);
	
	init_cond_regs(CREG);
}

void
StaticInst::init_dst_regs(int num_dst_regs, ...)
{
	va_list vl;
	va_start(vl, num_dst_regs);
	_num_dst_regs = num_dst_regs;
	
	FOR(i,0,_num_dst_regs) {
		_dst_reg_type[i] = (RegType)va_arg(vl, int);
		_dst_reg_idx[i] = gen_p2v(va_arg(vl, int));
		_delay_slot[i] = va_arg(vl, int);
	}
	
	va_end(vl);
}

void
StaticInst::init_cond_regs(RegIndex reg_idx)
{
	_cond_reg_idx = cond_p2v(reg_idx);
}

void
StaticInst::init_imm(uint32_t imm, int imm_len)
{
	_imm = imm;
	_imm_len = imm_len;
}

void
StaticInst::init_unit(Unit unit)
{
	switch(unit) {
		case A:
		    _unit = CLUSTER ? YA : XA; break;
		case M:
		    _unit = CLUSTER ? YM : XM; break;
		case D:
		    _unit = CLUSTER ? YD : XD; break;
		default:
		    AST(0); /* Other cases are not allowed anyway. */
	}
}

bool
StaticInst::cond_execute(RiscCPU *cpu) const
{
	if(!is_cond()) return true;
	else {
		if(CREG) {
			uint32_t cond_val = cpu->read_cond_w_operand(this);
			if((Z && !cond_val)||(!Z && cond_val)) 
			    return true;
            else 
                return false;
            return true;
		}
		else return true;
	}
}

RegIndex
StaticInst::gen_p2v(ExtMachInst field) const
{
	if(field>=C_Base_DepTag)
	    return field;
	else {
		if(field>=Num_X_Regs && field<Num_X_Regs+Num_G_Regs)
		    return field + Num_Y_Regs;
		else
		    return field + CLUSTER*Num_X_Regs;
	}
}

RegIndex
StaticInst::cond_p2v(ExtMachInst field) const
{
    switch(field) {
		case 0x0: { return -1; } // ALWAYS
        case 0x1: { return 48; } // G0
        case 0x2: { return 49; } // G1
        case 0x3: { return 50; } // G2
        case 0x4: { return 0;  } // X0
        case 0x5: { return 1;  } // X1
        case 0x6: { return 24; } // Y0
        case 0x7: { return 25; } // Y1
        default: { ERR(0);     }
    }
}

void
StaticInst::print_reg(std::ostream &os, RegIndex reg_idx) const
{
	ASSERT_GTE(reg_idx, X_Base_DepTag);
	ASSERT_LT(reg_idx, O_Base_DepTag);
	
	if(reg_idx<Y_Base_DepTag) 
	    ccprintf(os, " X%d", reg_idx - X_Base_DepTag);
	else if(reg_idx<G_Base_DepTag)
	    ccprintf(os, " Y%d", reg_idx - Y_Base_DepTag);
	else if(reg_idx<C_Base_DepTag)
	    ccprintf(os, " G%d", reg_idx - G_Base_DepTag);
	else
	    ccprintf(os, " C%d", reg_idx - C_Base_DepTag);
}

void
StaticInst::print_mnemonic(std::ostream &os) const
{
	ccprintf(os, "%s", _mnemonic);
}

void
StaticInst::print_cond(std::ostream &os) const
{
	if(is_cond() && (CREG)) {
        ccprintf(os, Z?"[!":"[");    
        print_reg(os, _cond_reg_idx);
        ccprintf(os, "]");
	}
}

void
StaticInst::print_len(std::ostream &os) const
{
	ccprintf(os, is_16_bit()?".16":".32");
}

void
StaticInst::print_unit(std::ostream &os) const
{
	switch(_unit) {
        case XA: { ccprintf(os, "(.XA)"); break; }
        case XM: { ccprintf(os, "(.XM)"); break; }
        case XD: { ccprintf(os, "(.XD)"); break; }
        case YA: { ccprintf(os, "(.YA)"); break; }
        case YM: { ccprintf(os, "(.YM)"); break; }
        case YD: { ccprintf(os, "(.YD)"); break; }
        default: { AST(0); /* Other cases is not allowed. */ } 
    }
}

void
StaticInst::print_src_reg(std::ostream &os) const
{
	FOR(i,0,_num_src_regs) {
		RegIndex reg_idx = get_src_reg_idx(i);
		RegIndex reg_type = get_src_reg_type(i);
		switch(reg_type) {
			case REG     : /* No break here. */
			case DREG    : /* No break here. */
			case QREG    : print_reg(os, reg_idx); break;
			case REG_PAIR: 
			    print_reg(os, reg_idx);
			    ccprintf(os, ":");
			    print_reg(os, reg_idx + 1);
			    break;
			default:
			    AST(0); /* Other cases is not allowed. */
		}
	}
}

void
StaticInst::print_dst_reg(std::ostream &os) const
{
	FOR(i,0,_num_dst_regs) {
		RegIndex reg_idx = get_dst_reg_idx(i);
		RegIndex reg_type = get_dst_reg_type(i);
		switch(reg_type) {
			case REG     : /* No break here. */
			case DREG    : /* No break here. */
			case QREG    : print_reg(os, reg_idx); break;
			case REG_PAIR: 
			    print_reg(os, reg_idx);
			    ccprintf(os, ":");
			    print_reg(os, reg_idx + 1);
			    break;
			default:
			    AST(0); /* Other cases is not allowed. */
		}
	}
}

void
StaticInst::print_imm(std::ostream &os) const
{
	ccprintf(os, " #0x%x", bits(_imm, _imm_len - 1, 0));
}

std::string
StaticInst::print_inst(void) const
{
	std::stringstream ss;
	
	print_cond(ss);
	print_mnemonic(ss);
	print_len(ss);
	print_unit(ss);
	
    print_dst_reg(ss);
	print_src_reg(ss);
	
	return ss.str();
}

std::string
StaticInst::print_inst_imm(void) const
{
	std::stringstream ss;
	
	print_cond(ss);
	print_mnemonic(ss);
	print_len(ss);
	print_unit(ss);
	
    print_dst_reg(ss);
	print_src_reg(ss);
	print_imm(ss);
	
	return ss.str();
}

std::string
StaticInst::print_inst_mem_no_offset(void) const
{
	std::stringstream ss;
	
	print_cond(ss);
	print_mnemonic(ss);
	print_len(ss);
	print_unit(ss);
	
    print_dst_reg(ss);
    ss << " *";
	print_src_reg(ss);
	
	return ss.str();
}

std::string
StaticInst::print_inst_mem_offset(void) const
{
	std::stringstream ss;
	
	print_cond(ss);
	print_mnemonic(ss);
	print_len(ss);
	print_unit(ss);
	
    print_dst_reg(ss);
    ss << " *";
    switch(bits(MODE, 0, 0)) {
		case 0x0: { ss << "+"; break; }
		case 0x1: { ss << "-"; break; }
	}
	print_src_reg(ss);
	
	return ss.str();
}

std::string
StaticInst::print_inst_mem_offset_imm(void) const
{
	std::stringstream ss;
	
	print_cond(ss);
	print_mnemonic(ss);
	print_len(ss);
	print_unit(ss);
	
    print_dst_reg(ss);
    ss << " *";
    switch(bits(MODE, 0, 0)) {
		case 0x0: { ss << "+"; break; }
		case 0x1: { ss << "-"; break; }
	}
	print_src_reg(ss);
	print_imm(ss);
	
	return ss.str();
}
	
} // namespace LILY2_NS
