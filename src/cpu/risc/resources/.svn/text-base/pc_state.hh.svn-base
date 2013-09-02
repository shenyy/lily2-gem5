/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 19 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#ifndef __RISC_RESOURCES_PC_STATE_HH__
#define __RISC_RESOURCES_PC_STATE_HH__

#include "resource.hh"
#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/type.hh"

namespace LILY2_NS
{

class PCState : public Resource
{
private:
    /* Initialization flag. */
    bool _init_flag;
    
    /* Entry point of the program. */
    Addr _entry_point;
    
    /* Address of the instruction executing. */
    Addr _inst_addr;
    
    /* Address of the dispatch packet. */
    Addr _dpkt_addr;
    
    /* Fetch address. */
    Addr _fetch_addr;
    
    /* Branch. */
    bool _branch_taken;
    Addr _branch_addr;
    
public:
    PCState(RiscCPU *cpu);

public:
    void init(Addr entry_point);

    void set_entry_point(Addr entry_point) { _entry_point = entry_point; }
    void set_inst_addr  (Addr inst_addr)   { _inst_addr   = inst_addr;   }
    
    /**
     * Set address of the dispatch packet.
     */
    void set_dpkt_addr(Addr dpkt_addr) { _dpkt_addr = dpkt_addr; }
    
    void set_fetch_addr (Addr fetch_addr)  { _fetch_addr  = fetch_addr;  }
    
    void set_branch_addr(Addr branch_addr) 
    {
		_branch_taken = true; 
		_branch_addr = branch_addr; 
	}

public:
    bool is_init(void) const { return _init_flag;  }
    Addr get_fetch_addr(void) const { return _fetch_addr; }
    
    /**
     * Get address of the dispatch packet.
     */
    Addr get_dpkt_addr(void) const { return _dpkt_addr; }
    
    Addr get_inst_addr(void) const { return _inst_addr; }
    
    Addr get_branch_addr(void) const { return _branch_addr; }
};

} // namespace LILY2_NS
 
#endif // __RISC_RESOURCES_PC_STATE_HH__
