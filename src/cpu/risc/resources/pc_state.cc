/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 19 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#include "pc_state.hh"

namespace LILY2_NS
{
	
PCState::PCState(RiscCPU *cpu)
    : Resource(cpu),
      _init_flag(false)
{
}

void
PCState::init(Addr entry_point)
{
	set_entry_point(entry_point);
	set_fetch_addr(entry_point);
	set_inst_addr(entry_point);
	_init_flag = true;
}

}
