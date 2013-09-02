/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#ifndef __RISC_STATIC_INST_HH__
#define __RISC_STATIC_INST_HH__

#include <bitset>
#include "bitfields.hh"
#include "dyn_inst.hh"
#include "base/refcnt.hh"
#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/includes.hh"

class RiscCPU;

namespace LILY2_NS
{
	
class StaticInst : public RefCounted
{
public:
    typedef RefCountingPtr<StaticInst> StaticInstPtr;
	
public:
    /**
     * Instruction traits flags.
     * @todo
     */
    enum Flags {
		Is_16_Bit,
		Is_32_Bit,
		Is_Mode,
		Is_Cond,
		Is_Nop,
		Is_Unknown,
		Is_Mem_Ref,
		Is_Load,
		Is_Store,
		Is_Control,
		Is_Call,
		Is_Return,
		Is_Eoc,
		
		Num_Flags
	};
	
protected:
	/**
	 * Number of source and destination registers.
	 * 
	 * @attention : Register pair contributes only one register.
	 */
	int _num_src_regs;
	int _num_dst_regs;
	
	/**
	 * Register index of source and destination registers.
	 * 
	 * @attention : Register pair records only the first register.
	 */
	RegIndex _src_reg_idx[Max_Src_Regs];
	RegIndex _dst_reg_idx[Max_Dst_Regs];
	
	/**
	 * Register type of source and destination registers.
	 * 
	 * @todo
	 */
	RegType _src_reg_type[Max_Src_Regs];
	RegType _dst_reg_type[Max_Dst_Regs];
	
	/**
	 * Delay slot of destination registers.
	 * Maybe you only heard about branch instruction delay slot before,
	 * but actually every instruction has a delay slot and this concept
	 * is rather important in Vliw dsp if you are a Vliw dsp programmer.
	 * Actually in Risc dsp delay slot is also important but it will be
	 * done by the compiler and hardware and it won't be exposed to the
	 * programmer(Lucky Risc programmer?).
	 */
	Tick _delay_slot[Max_Dst_Regs];
	
	/**
	 * Execution unit of instructions.
	 * Now it is classified into the static information and maybe be 
	 * moved to dynamic information some day.
	 */
	Unit _unit;
	
	/**
	 * Immediate of instructions.
	 */
	uint32_t _imm;
	int _imm_len;
	
	/**
	 * Register index of condition register.
	 */
	RegIndex _cond_reg_idx;
	
	/**
	 * Machine code of an instruction.
	 * @attention : 16-bit instruction is put into the 16 Msb.
	 */
	const ExtMachInst _mach_inst;
	
	/**
	 * Static instruction information flags container.
	 */ 
	std::bitset<Num_Flags> _flags;
	
	/**
	 * Mnemonic of an instruction.
	 * It is used when generating the disassembly language.
	 */
	const char* _mnemonic;
	
	/**
	 * Dynamic instruction information
	 */
	DynInst *_d_ptr;
	
public:
    /**
     * Constructor.
     */
    StaticInst(const char *mnemonic, ExtMachInst mach_inst);
    
    /**
     * Destructor.
     */
    ~StaticInst(void);
    
public:
    /**
     * Static information flags accessing functions.
     */
    bool is_16_bit  (void) const { return _flags[Is_16_Bit];  }
    bool is_32_bit  (void) const { return _flags[Is_32_Bit];  }
    bool is_mode    (void) const { return _flags[Is_Mode];    }
    bool is_cond    (void) const { return _flags[Is_Cond];    }
    bool is_nop     (void) const { return _flags[Is_Nop];     }
    bool is_unknown (void) const { return _flags[Is_Unknown]; }
    bool is_mem_ref (void) const { return _flags[Is_Mem_Ref]; }
    bool is_load    (void) const { return _flags[Is_Load];    }
    bool is_store   (void) const { return _flags[Is_Store];   }
    bool is_control (void) const { return _flags[Is_Control]; }
    bool is_call    (void) const { return _flags[Is_Call];    }
    bool is_return  (void) const { return _flags[Is_Return];  }
    bool is_eoc     (void) const { return _flags[Is_Eoc];     }
    
    /**
     * Get the number of source and destination registers.
     */
    int get_num_src_regs(void) const { return _num_src_regs; }
    int get_num_dst_regs(void) const { return _num_dst_regs; }
    
    /**
     * Get the index of source and destination registers.
     */
    RegIndex get_src_reg_idx(int i) const { return _src_reg_idx[i]; }
    RegIndex get_dst_reg_idx(int i) const { return _dst_reg_idx[i]; }
    
    /**
     * Get the register type of source and destination registers.
     */
    RegType get_src_reg_type(int i) const { return _src_reg_type[i]; }
    RegType get_dst_reg_type(int i) const { return _dst_reg_type[i]; }
    
    /**
     * Get total number of the source and destiantion registers.
     * 
     * @return : Total number of the source and destination registers.
     * 
     * @attention : Register pair contributes two registers.
     */
    int get_total_num_src_regs(void);
    int get_total_num_dst_regs(void);
    
     /**
     * Get number of X,Y,G,C source and destination registers.
     * 
     * @return : Number of the source and destination registers.
     * 
     * @attention : Register pair contributes one registers.
     */
    int get_num_src_x_regs(void);
    int get_num_dst_x_regs(void);
    int get_num_src_y_regs(void);
    int get_num_dst_y_regs(void);
    int get_num_src_g_regs(void);
    int get_num_dst_g_regs(void);
    int get_num_src_c_regs(void);
    int get_num_dst_c_regs(void);
    
    /**
     * Get total number of X,Y,G,C source and destination registers.
     * 
     * @return : Total number of the source and destination registers.
     * 
     * @attention : Register pair contributes two registers.
     */
    int get_total_num_src_x_regs(void);
    int get_total_num_dst_x_regs(void);
    int get_total_num_src_y_regs(void);
    int get_total_num_dst_y_regs(void);
    int get_total_num_src_g_regs(void);
    int get_total_num_dst_g_regs(void);
    int get_total_num_src_c_regs(void);
    int get_total_num_dst_c_regs(void);
    
    /**
     * Get the delay slot of destination registers.
     */
    Tick get_delay_slot(int i) const { return _delay_slot[i]; }
    
    /**
     * Get the unit.
     */
    Unit get_unit(void) const { return _unit; }
    
    /**
     * Get the immediate and immediate length.
     */
    uint32_t get_imm(void) const { return _imm; }
    int get_imm_len(void) const { return _imm_len; }
    
    RegIndex get_cond_reg_idx(void) const { return _cond_reg_idx; }
    
    DynInst *get_dyn_inst(void) const { return _d_ptr; }
    
public:
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     */
    virtual void execute(RiscCPU *cpu) const = 0;
    
    /**
     * Pure virtual function.
     * 
     * @return : Return the disassembly language of an instruction.
     */
    virtual std::string generate_disassembly(void) const = 0;
    
protected:
    /**
     * Initialize information of the source registers.
     * 
     * @param (num_src_regs) : Number of the source registers.
     * @param (...)          : Variable args, giving the register type
     *                          and index one by one.
     * 
     * @attention : Register pair contributes only one register.
     * 
     * @example : ADD [R2:R3] [R4:R5] R1
     *             init_src_regs(2, Reg_Pair, R4, Reg, R1).
     */
    void init_src_regs(int num_src_regs, ...);
    
    /**
     * Initialize information of the destination registers.
     * 
     * @param (num_dst_regs) : Number of the destination registers.
     * @param (...)          : Variable args, giving the register type,
     *                          index and delay slot one by one.
     * 
     * @attention : Register pair contributes only one register.
     * 
     * @example : ADD [R2:R3] [R4:R5] R1
     *             init_dst_regs(1, Reg_Pair, R2, 0).
     */
    void init_dst_regs(int num_dst_regs, ...);
    
    /**
     * Initialize information of the condition registers.
     * 
     * @param (cond_reg_idx) : Register index of the condition register.
     */
    void init_cond_regs(RegIndex cond_reg_idx);
    
    /**
     * Initialize information of the immediate.
     * 
     * @param (imm)     : Immediate of the instruction.
     * @param (imm_len) : Binary length of the immediate.
     */
    void init_imm(uint32_t imm, int imm_len); 
    
    /**
     * Initialize information of the unit.
     * 
     * @param (unit) : Static unit of the instruction, regardless of
     *                  the cluster.
     */
    void init_unit(Unit unit);
    
protected:
    /**
     * Check whether the instruction should be conditional executed.
     * 
     * @param (cpu) : Pointer to cpu.
     * 
     * @return : Conditional execute or not.
     */
    bool cond_execute(RiscCPU *cpu) const;
    
    /**
     * Convertion of virtual register index and physical register index.
     * 
     * @attention : Virtual and physical register index conversion table.
     *                Physical <--->  Virtual
     *                X(0~23)  <--->    0~23
     *                Y(0~23)  <--->   24~47
     *                G(0~ 7)  <--->   48~55
     * 
     * @param (field) : Physical register index.
     * 
     * @return : Virtual register index.
     */
    RegIndex gen_p2v(ExtMachInst field) const;
    RegIndex cond_p2v(ExtMachInst field) const;
    
public:
    /**
     * Output the physical register index.
     * 
     * @param (os)      : Terminal of the output.
     * @param (reg_idx) : Virtual register index.
     */
    void print_reg(std::ostream &os, RegIndex reg_idx) const;

    /**
     * Output the mnemonic of the instruction.
     * 
     * @param (os) : Terminal of the output.
     */
    virtual void print_mnemonic(std::ostream &os) const;

    /**
     * Output the condition of the instruction.
     * 
     * @param (os) : Terminal of the output.
     */
    void print_cond(std::ostream &os) const;

    /**
     * Output the length of the instruction.
     * 
     * @param (os) : Terminal of the output.
     */
    void print_len(std::ostream &os) const;

    /**
     * Output the unit of the instruction.
     * 
     * @param (os) : Terminal of the output.
     */
    void print_unit(std::ostream &os) const;
    
    /**
     * Output the source registers.
     * 
     * @param (os)  : Terminal of the output.
     */
    void print_src_reg(std::ostream &os) const;
    
    /**
     * Output the destination registers.
     * 
     * @param (os)  : Terminal of the output.
     */
    void print_dst_reg(std::ostream &os) const;

    /**
     * Output the immediate of the instruction.
     * 
     * @param (os) : Terminal of the output.
     */
    void print_imm(std::ostream &os) const;
    
    std::string print_inst(void) const;
    
    std::string print_inst_imm(void) const;
    
    std::string print_inst_mem_no_offset(void) const;
    
    std::string print_inst_mem_offset(void) const;
    
    std::string print_inst_mem_offset_imm(void) const;
};
	
} // namespace LILY2_NS

#endif // _RISC_STATIC_INST_HH__
