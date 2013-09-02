/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 23 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

/**
 * All the stacks used are defined here.
 */

#ifndef __RISC_RESOURCES_STACK_HH__
#define __RISC_RESOURCES_STACK_HH__

#include "resource.hh"
#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/includes.hh"

namespace LILY2_NS
{

class RetStack : public Resource
{
private:
    /*  */
    std::stack<Addr> _ret_stack;

public:
    RetStack(RiscCPU *cpu) : Resource(cpu) {}

public:
    void push(Addr addr)
    {
		_ret_stack.push(addr);
	}
	
	Addr pop(void)
	{
		AST(!_ret_stack.empty());
		Addr addr = _ret_stack.top();
		_ret_stack.pop();
		return addr;
	}
};

} // namespace LILY2_NS

#endif // __RISC_RESOURCES_STACK_HH__
