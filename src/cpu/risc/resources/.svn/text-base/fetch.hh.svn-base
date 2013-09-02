/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 19 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#ifndef __RISC_RESOURCES_FETCH_HH__
#define __RISC_RESOURCES_FETCH_HH__

#include "resource.hh"
#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/type.hh"

#include "cpu/simple_thread.hh"
#include "mem/request.hh"
#include "mem/packet.hh"

namespace LILY2_NS 
{
// Forward declaration.
class PCState;
	
class Fetch : public Resource
{
private:
    // Fetch address and fetched instruction machine code.
    Addr _inst_addr;
    ExtMachInst _mach_inst;
    
    // Other modules in cpu needed.
    PCState *_pc_state;
    SimpleThread *_thread;
    ThreadContext *_tc;
    
public:
    /**
     * Recommended constructor.
     * 
     * @param (cpu) : Pointer to the cpu.
     * 
     * @todo : At this moment, resources in fetch module is unconcerned.
     */
    Fetch(RiscCPU *cpu);

    virtual ~Fetch(void);
    
private:
    /**
     * Encapsulate Gem5 instruction fetching interfaces.
     * 
     * @param (fetch_addr) : Fetch address.
     * 
     * @return : 16-bit fetched instruction machine code.
     */
    MachInst _fetch_inst(Addr fetch_addr);
    
public:
    /**
     * Fetch instructions.
     * 
     * @return : 32-bit fetched instruction machine code.
     */
    ExtMachInst fetch_inst(void);
    
public:
    /**
     * Debug functions for fetch module.
     * 
     * @todo
     */
    void __DEBUG(void)
    {
		printf("[FETCH DEBUG] Fetch Address = 0x%08x\n", _inst_addr);
		printf("[FETCH DEBUG] Machine Code = 0x%08x\n", _mach_inst);
	}
};


} // namespace LILY2_NS
 
#endif // __RISC_RESOURCES_FETCH_HH__
