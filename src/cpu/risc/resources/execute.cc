/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 09 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "execute.hh"

namespace LILY2_NS
{
	
Execute::Execute(RiscCPU *cpu, int num_res, int num_unit)
    : Resource(cpu, num_res, num_unit),
      cnt(0)
{
}

void
Execute::execute_inst(const StaticInst *s_ptr)
{
	_S_PTR = s_ptr;
	s_ptr->execute(_cpu);
}
	
} // namespace LILY2_NS
