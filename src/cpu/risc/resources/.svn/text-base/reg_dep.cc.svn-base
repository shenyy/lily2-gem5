/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 07 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#include "reg_dep.hh"
#include "cpu/risc/cpu.hh"

namespace LILY2_NS
{
	
RegDepTable::RegDepTable(RiscCPU *cpu)
    : Resource(cpu)
{
}

RegDepTable::~RegDepTable(void)
{
}

void
RegDepTable::push_reg(RegIndex reg_idx, Tick delay_slot)
{
    reg_dep_table.insert(std::pair<RegIndex, Tick>(reg_idx, delay_slot));
}

void
RegDepTable::push_reg_pair(RegIndex reg_idx, Tick delay_slot)
{
	reg_dep_table.insert(std::pair<RegIndex, Tick>(reg_idx, delay_slot));
	reg_dep_table.insert(std::pair<RegIndex, Tick>(reg_idx+1, delay_slot));
}

void
RegDepTable::update(void)
{
	std::map<RegIndex, Tick> tmp_table;
	std::map<RegIndex, Tick>::iterator	 iter;
	for(iter=reg_dep_table.begin(); iter!=reg_dep_table.end(); iter++) {
		if(iter->second) {
			tmp_table.insert(std::pair<RegIndex, Tick> \
			    (iter->first, iter->second - 1));
		}
	}
	
	reg_dep_table.clear();
	for(iter=tmp_table.begin(); iter!=tmp_table.end(); iter++) {
		reg_dep_table.insert(std::pair<RegIndex, Tick> \
		    (iter->first, iter->second));
	}
}

bool
RegDepTable::is_reg_dep(RegIndex reg_idx)
{
	return reg_dep_table.find(reg_idx)!=reg_dep_table.end();
}

bool
RegDepTable::is_reg_dep_pair(RegIndex reg_idx)
{
	return reg_dep_table.find(reg_idx)!=reg_dep_table.end() \
	    && reg_dep_table.find(reg_idx+1)!=reg_dep_table.end();
}

Tick
RegDepTable::get_max_slot_reg(RegIndex reg_idx)
{
	Tick max = -1;
	std::map<RegIndex, Tick>::iterator	 iter;
	for(iter=reg_dep_table.begin(); iter!=reg_dep_table.end(); iter++) {
		if(iter->first==reg_idx) {
			max = max<iter->second ? iter->second : max;
		}
	}
	return max;
}

Tick
RegDepTable::get_max_slot_reg_pair(RegIndex reg_idx)
{
	Tick max = -1;
	std::map<RegIndex, Tick>::iterator	 iter;
	for(iter=reg_dep_table.begin(); iter!=reg_dep_table.end(); iter++) {
		if(iter->first==reg_idx || iter->first==reg_idx+1) {
			max = max<iter->second ? iter->second : max;
		}
	}
	return max;
}
	
} // namespace LILY2_NS
