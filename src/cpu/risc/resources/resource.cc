/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 22 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "resource.hh"

namespace LILY2_NS
{
	
Resource::Resource(void)
    : _num_res(0), _max_res(NULL), _cpu(NULL),
      _num_res_used_tick(0),
      _num_res_used_total(0)
{
    /**
     * @todo : Maybe should do something here for detection.
     */
}

Resource::Resource(int num_res, ...)
    : _num_res(num_res), _max_res(NULL), _cpu(NULL),
      _num_res_used_tick(0),
      _num_res_used_total(0)
{
    AST(_max_res = new int[_num_res]);
    va_list vl;
    va_start(vl,num_res);
    FOR(i,0,_num_res) _max_res[i] = va_arg(vl,int);
    va_end(vl); 
    AST(_num_res_used_tick = new int[_num_res]);
    AST(_num_res_used_total = new int[_num_res]);	
}

Resource::Resource(RiscCPU *cpu)
    : _num_res(0), _max_res(NULL), _cpu(cpu),
      _num_res_used_tick(0),
      _num_res_used_total(0)
{
    /**
     * @todo : Maybe should do something here for detection.
     */	
}

Resource::Resource(RiscCPU *cpu, int num_res, ...)
    : _num_res(num_res), _max_res(NULL), _cpu(cpu),
      _num_res_used_tick(0),
      _num_res_used_total(0)
{
    AST(_max_res = new int[_num_res]);
    va_list vl;
    va_start(vl,num_res);
    FOR(i,0,_num_res) _max_res[i] = va_arg(vl,int);
    va_end(vl); 
    AST(_num_res_used_tick = new int[_num_res]);
    AST(_num_res_used_total = new int[_num_res]);		
}

Resource::~Resource(void)
{
	if(_max_res) {
		delete []_max_res;
		delete []_num_res_used_tick;
		delete []_num_res_used_total;
		_max_res = NULL;
		_num_res_used_tick = NULL;
		_num_res_used_total = NULL;
	}
}

bool
Resource::no_res(int res_idx, int delta)
{
	if(_num_res_used_tick[res_idx]+delta<=_max_res[res_idx])
	    return false;
	else
	    return true;
}

void
Resource::incr_res(int res_idx, int delta)
{
	_num_res_used_tick[res_idx] += delta;
	_num_res_used_total[res_idx] += delta;
}

void
Resource::clr_res(void)
{
	CLR(_num_res_used_tick, _num_res * sizeof(int));
}
	
} // namespace LILY2_NS
