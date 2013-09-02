/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#ifndef __RISC_RESOURCES_REG_FILE_HH__
#define __RISC_RESOURCES_REG_FILE_HH__

#include "resource.hh"
#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/includes.hh"

namespace LILY2_NS
{

/***********************************************************************
 * 32-bit width register file template.
 * This template is suitable to X register file in Lily2 whose register 
 * width is exactly 32-bit.
 **********************************************************************/
template <int N>
class WRegFile : public Resource
{
public:
    /* Mnemonic of resources. */
    enum ResIndex {
		R_PORT, 
		W_PORT
	};
	
private:
    typedef WORD RegWidth;
    
    /* Registers. */
    RegWidth _reg[N];
    
    /* *
     * If cpu model is not atomic, the followings are needed. 
     * We should cache the results until the right time and write them
     * back to the registers. 
     * */
    enum CacheConst {
		C = 2
	};
    RegWidth _cache[N][C];
    RegWidth _mask[N][C];
    bool _dirty[N][C];
    Tick _slot[N][C];	
    
public:
    /**
     * Recommended constructor.
     * 
     * @param (cpu)     : Pointer to cpu.
     * @param (num_res) : Kinds of resources.
     * @param (r_port)  : Number of reading ports resource.
     * @param (w_port)  : Number of writing ports resource.
     * 
     * @todo : At this moment, we only care about reading and writing 
     *          port resources in register file module.
     */
    WRegFile(RiscCPU *cpu, int num_res, int r_port, int w_port);
    
    ~WRegFile(void) {}
    
public:
    /**
     * Register file reading interfaces.
     * 
     * @param (reg_idx) : Physical index of the register to be read.
     * 
     * @return : Value in the register.
     */
    RegWidth read(RegIndex reg_idx);
    
    /**
     * Register file writing interfaces.
     * 
     * @param (reg_idx) : Physical index of the register to be written.
     * @param (reg_val) : Value to be written into the register.
     */
    void write(RegIndex reg_idx, RegWidth reg_val);
    
    /**
     * Clear the register file.
     */
    void clear(void);
    
    /**
     * Commit the cached register value.
     */
    void commit(void);
    
    /**
     * Cache the register value.
     * 
     * @param (reg_idx)    : Physical index of the register to be cached.
     * @param (reg_val)    : Value to be cached into the register.
     * @param (delay_slot) : Delay slot of the destination register.
     */
    void cache(RegIndex reg_idx, RegWidth reg_val, Tick delay_slot);
    
    void cache_hi(RegIndex reg_idx, RegWidth reg_val, Tick delay_slot);
    void cache_lo(RegIndex reg_idx, RegWidth reg_val, Tick delay_slot);
    
/* ********************************************************************
 * *************************** DEBUG CODE *****************************
 * *******************************************************************/
public:
    void __DEBUG(void)
    {
		FON(i,0,N,4) {
			DPF("[%02d] = 0x%08x  ", i+0, _reg[i+0]);
			DPF("[%02d] = 0x%08x  ", i+1, _reg[i+1]);
			DPF("[%02d] = 0x%08x  ", i+2, _reg[i+2]);
			DPF("[%02d] = 0x%08x  ", i+3, _reg[i+3]);
			DPF("\n");
		}
	}
};

template <int N>
WRegFile<N>::WRegFile(RiscCPU *cpu, int num_res, \
                        int r_port, int w_port)
    : Resource(cpu, num_res, r_port, w_port)
{
	/* Regfile size checking. */
	AST(N>0);
	
	/* *
	 * To make sure that the register file is all-zero-state at 
	 * the very beginning. 
	 * */
	clear();
}

template <int N>
typename WRegFile<N>::RegWidth
WRegFile<N>::read(RegIndex reg_idx)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	return _reg[reg_idx];
}

template <int N>
void
WRegFile<N>::write(RegIndex reg_idx, RegWidth reg_val)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	_reg[reg_idx] = reg_val;
}

template <int N>
void
WRegFile<N>::clear(void)
{
	CLR(_reg, N * sizeof(RegWidth));
	CLR(_mask, N*C*sizeof(RegWidth));
	CLR(_dirty, N*C*sizeof(bool));
	CLR(_slot, N*C*sizeof(Tick));
}

template <int N>
void
WRegFile<N>::commit(void)
{
	FOR(i,0,N) FOR(j,0,C) {
		if(_dirty[i][j]) {
			if(_slot[i][j]) _slot[i][j]--;
			else {
				_reg[i] = (_cache[i][j]&_mask[i][j]) \
				   | (_reg[i]&(~_mask[i][j]));
				_dirty[i][j] = false;
			}
		}
	}
}

template <int N>
void
WRegFile<N>::cache(RegIndex reg_idx, RegWidth reg_val, Tick delay_slot)
{
	/* Index range checking. */
	ERR(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i] = reg_val;
		_mask[reg_idx][i] = Mask_1;
		_slot [reg_idx][i] = delay_slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}

template <int N>
void
WRegFile<N>::cache_hi(RegIndex reg_idx, RegWidth reg_val, Tick delay_slot)
{
	/* Index range checking. */
	ERR(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i] = reg_val<<16;
		_mask[reg_idx][i] = Mask_hi;
		_slot [reg_idx][i] = delay_slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}

template <int N>
void
WRegFile<N>::cache_lo(RegIndex reg_idx, RegWidth reg_val, Tick delay_slot)
{
	/* Index range checking. */
	ERR(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i] = reg_val;
		_mask[reg_idx][i] = Mask_lo;
		_slot [reg_idx][i] = delay_slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}

/***********************************************************************
 * 128-bit width register file template.
 * This template is suitable to Y/G register file in Lily2 whose 
 * register width is exactly 128-bit.
 **********************************************************************/
template <int N>
class QWRegFile : public Resource
{
public:
    /* Mnemonic of resources. */
    enum ResIndex {
		R_PORT, 
		W_PORT
	};
	
private:
    typedef QWORD RegWidth;
    typedef DWORD HalfRegWidth;
    typedef WORD  QuarRegWidth;
    
    RegWidth _reg[N];
    
    /* *
     * If cpu model is not atomic, the followings are needed. 
     * We should cache the results until the right time and write them
     * back to the registers. 
     * */
    enum CacheConst {
		C = 2
	};
    RegWidth _cache[N][C];
    RegWidth _mask[N][C];
    bool _dirty[N][C];
    Tick _slot[N][C];		
    
public:
    /**
     * Recommended constructor.
     * 
     * @param (cpu)     : Pointer to cpu.
     * @param (num_res) : Kinds of resources.
     * @param (r_port)  : Number of reading ports resource.
     * @param (w_port)  : Number of writing ports resource.
     * 
     * @todo : At this moment, we only care about reading and writing 
     *          port resources in register file module.
     */
    QWRegFile(RiscCPU *cpu, int num_res, int r_port, int w_port);
    
    ~QWRegFile(void) {}
    
public:
    /**
     * Register file reading interfaces.
     * 
     * @param (reg_idx) : Physical index of the register to be read.
     * 
     * @return : Value in the register.
     */
    RegWidth read(RegIndex reg_idx);
    
    /**
     * Register file partly reading interfaces.
     * 
     * @param (reg_idx) : Physical index of the register to be read.
     * 
     * @return : Part value in the register.
     */
    HalfRegWidth read_h3h2(RegIndex reg_idx);
    HalfRegWidth read_h1h0(RegIndex reg_idx);
    QuarRegWidth read_h0(RegIndex reg_idx);
    QuarRegWidth read_h1(RegIndex reg_idx);
    QuarRegWidth read_h2(RegIndex reg_idx);
    QuarRegWidth read_h3(RegIndex reg_idx);
    
    /**
     * Register file writing interfaces.
     * 
     * @param (reg_idx) : Physical index of the register to be written.
     * @param (reg_val) : Value to be written into the register.
     */
    void write(RegIndex reg_idx, RegWidth reg_val);
    
    /**
     * Register file partly writing interfaces.
     * 
     * @param (reg_idx) : Physical index of the register to be written.
     * @param (reg_val) : Part value to be written into the register.
     */
    void write_h3h2(RegIndex reg_idx, HalfRegWidth reg_val);
    void write_h1h0(RegIndex reg_idx, HalfRegWidth reg_val);
    void write_h0(RegIndex reg_idx, QuarRegWidth reg_val);
    void write_h1(RegIndex reg_idx, QuarRegWidth reg_val);
    void write_h2(RegIndex reg_idx, QuarRegWidth reg_val);
    void write_h3(RegIndex reg_idx, QuarRegWidth reg_val);
    
    /**
     * Clear the register file.
     */
    void clear(void);
    
    /**
     * Commit the cached register value.
     */
    void commit(void);
    
    /**
     * Cache the register value.
     */
    void cache(RegIndex reg_idx, RegWidth reg_val, Tick slot);
    void cache_h3h2(RegIndex reg_idx, HalfRegWidth reg_val, Tick slot);
    void cache_h1h0(RegIndex reg_idx, HalfRegWidth reg_val, Tick slot);
    void cache_h0(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot);
    void cache_h1(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot);
    void cache_h2(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot);
    void cache_h3(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot);
    void cache_h0_hi(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot);
    void cache_h0_lo(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot);
    
/* ********************************************************************
 * *************************** DEBUG CODE *****************************
 * *******************************************************************/
public:
    void __DEBUG(void)
    {
		FOR(i,0,N) {
			DPF("[%02d] = 0x%08x, %08x, %08x, %08x\n", i, _reg[i]._h3, _reg[i]._h2, _reg[i]._h1, _reg[i]._h0);
		}
    }
};

template <int N>
QWRegFile<N>::QWRegFile(RiscCPU *cpu, int num_res, \
                          int r_port, int w_port)
    : Resource(cpu, num_res, r_port, w_port)
{
	/* Regfile size checking. */
	AST(N>0);
	
	/* *
	 * To make sure that the register file is all-zero-state at 
	 * the very beginning. 
	 * */
	clear();
}

template <int N>
typename QWRegFile<N>::RegWidth
QWRegFile<N>::read(RegIndex reg_idx)
{
	/* Index range checking. */
	ASSERT_GTE(reg_idx, 0);
	ASSERT_LT(reg_idx, N);
	
	return _reg[reg_idx];
}

template <int N>
typename QWRegFile<N>::HalfRegWidth
QWRegFile<N>::read_h3h2(RegIndex reg_idx)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	return (static_cast<HalfRegWidth>(_reg[reg_idx]._h3)<<32) \
	    | static_cast<HalfRegWidth>(_reg[reg_idx]._h2);
}

template <int N>
typename QWRegFile<N>::HalfRegWidth
QWRegFile<N>::read_h1h0(RegIndex reg_idx)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	return (static_cast<HalfRegWidth>(_reg[reg_idx]._h1)<<32) \
	    | static_cast<HalfRegWidth>(_reg[reg_idx]._h0);
}

template <int N>
typename QWRegFile<N>::QuarRegWidth
QWRegFile<N>::read_h0(RegIndex reg_idx)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	return _reg[reg_idx]._h0;
}

template <int N>
typename QWRegFile<N>::QuarRegWidth
QWRegFile<N>::read_h1(RegIndex reg_idx)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	return _reg[reg_idx]._h1;
}

template <int N>
typename QWRegFile<N>::QuarRegWidth
QWRegFile<N>::read_h2(RegIndex reg_idx)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	return _reg[reg_idx]._h2;
}

template <int N>
typename QWRegFile<N>::QuarRegWidth
QWRegFile<N>::read_h3(RegIndex reg_idx)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	return _reg[reg_idx]._h3;
}

template <int N>
void
QWRegFile<N>::write(RegIndex reg_idx, RegWidth reg_val)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	_reg[reg_idx] = reg_val;
}

template <int N>
void
QWRegFile<N>::write_h3h2(RegIndex reg_idx, HalfRegWidth reg_val)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	_reg[reg_idx]._h3 = static_cast<WORD>(reg_val>>32);
	_reg[reg_idx]._h2 = static_cast<WORD>(reg_val);
}

template <int N>
void
QWRegFile<N>::write_h1h0(RegIndex reg_idx, HalfRegWidth reg_val)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	_reg[reg_idx]._h1 = static_cast<WORD>(reg_val>>32);
	_reg[reg_idx]._h0 = static_cast<WORD>(reg_val);
}

template <int N>
void
QWRegFile<N>::write_h0(RegIndex reg_idx, QuarRegWidth reg_val)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	_reg[reg_idx]._h0 = reg_val;
}

template <int N>
void
QWRegFile<N>::write_h1(RegIndex reg_idx, QuarRegWidth reg_val)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	_reg[reg_idx]._h1 = reg_val;
}

template <int N>
void
QWRegFile<N>::write_h2(RegIndex reg_idx, QuarRegWidth reg_val)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	_reg[reg_idx]._h2 = reg_val;
}

template <int N>
void
QWRegFile<N>::write_h3(RegIndex reg_idx, QuarRegWidth reg_val)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);
	
	_reg[reg_idx]._h3 = reg_val;
}

template <int N>
void
QWRegFile<N>::clear(void)
{
	CLR(_reg, N * sizeof(RegWidth));
	CLR(_mask, N*C*sizeof(RegWidth));
	CLR(_dirty, N*C*sizeof(bool));
	CLR(_slot, N*C*sizeof(Tick));
}

template <int N>
void
QWRegFile<N>::commit(void)
{
	FOR(i,0,N) FOR(j,0,C) {
		if(_dirty[i][j]) {
			if(_slot[i][j]) _slot[i][j]--;
			else {
				_reg[i]._h0 = (_cache[i][j]._h0 & _mask[i][j]._h0) \
				    | (_reg[i]._h0 & ~_mask[i][j]._h0);
				_reg[i]._h1 = (_cache[i][j]._h1 & _mask[i][j]._h1) \
				    | (_reg[i]._h1 & ~_mask[i][j]._h1);
				_reg[i]._h2 = (_cache[i][j]._h2 & _mask[i][j]._h2) \
				    | (_reg[i]._h2 & ~_mask[i][j]._h2);
				_reg[i]._h3 = (_cache[i][j]._h3 & _mask[i][j]._h3) \
				    | (_reg[i]._h3 & ~_mask[i][j]._h3);
				_dirty[i][j] = false;
			}
		}
	}
}

template <int N>
void
QWRegFile<N>::cache(RegIndex reg_idx, RegWidth reg_val, Tick slot)
{
	/* Index range checking. */
	ERR(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i] = reg_val;
		_mask [reg_idx][i] = Mask_h3h2h1h0;
		_slot [reg_idx][i] = slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}

template <int N>
void
QWRegFile<N>::cache_h3h2(RegIndex reg_idx, HalfRegWidth reg_val, Tick slot)
{
	/* Index range checking. */
	AST(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i]._h3 = static_cast<WORD>(reg_val>>32);
		_cache[reg_idx][i]._h2 = static_cast<WORD>(reg_val);
		_mask [reg_idx][i] = Mask_h3h2;
		_slot [reg_idx][i] = slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}

template <int N>
void
QWRegFile<N>::cache_h1h0(RegIndex reg_idx, HalfRegWidth reg_val, Tick slot)
{
	/* Index range checking. */
	ERR(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i]._h1 = static_cast<WORD>(reg_val>>32);
		_cache[reg_idx][i]._h0 = static_cast<WORD>(reg_val);
		_mask [reg_idx][i] = Mask_h1h0;
		_slot [reg_idx][i] = slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}

template <int N>
void
QWRegFile<N>::cache_h0(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot)
{
	/* Index range checking. */
	ERR(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i]._h0 =reg_val;
		_mask [reg_idx][i] = Mask_h0;
		_slot [reg_idx][i] = slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}

template <int N>
void
QWRegFile<N>::cache_h1(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot)
{
	/* Index range checking. */
	ERR(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i]._h1 =reg_val;
		_mask [reg_idx][i] = Mask_h1;
		_slot [reg_idx][i] = slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}

template <int N>
void
QWRegFile<N>::cache_h2(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot)
{
	/* Index range checking. */
	ERR(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i]._h2 =reg_val;
		_mask [reg_idx][i] = Mask_h2;
		_slot [reg_idx][i] = slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}

template <int N>
void
QWRegFile<N>::cache_h3(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot)
{
	/* Index range checking. */
	ERR(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i]._h3 =reg_val;
		_mask [reg_idx][i] = Mask_h3;
		_slot [reg_idx][i] = slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}

template <int N>
void
QWRegFile<N>::cache_h0_hi(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot)
{
	/* Index range checking. */
	ERR(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i]._h0 =reg_val<<16;
		_mask [reg_idx][i] = Mask_h0_hi;
		_slot [reg_idx][i] = slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}

template <int N>
void
QWRegFile<N>::cache_h0_lo(RegIndex reg_idx, QuarRegWidth reg_val, Tick slot)
{
	/* Index range checking. */
	ERR(reg_idx>=0 && reg_idx<N);

	bool ast_flag = false;
	FOR(i,0,C) if(!_dirty[reg_idx][i]) {
		_cache[reg_idx][i]._h0 =reg_val;
		_mask [reg_idx][i] = Mask_h0_lo;
		_slot [reg_idx][i] = slot;
		_dirty[reg_idx][i] = true;
		ast_flag = true;
		break;
	}
	
	/* Dirty bit checking. */
	ERR(ast_flag);
}
	
}

#endif // __RISC_RESOURCES_REG_FILE_HH__
