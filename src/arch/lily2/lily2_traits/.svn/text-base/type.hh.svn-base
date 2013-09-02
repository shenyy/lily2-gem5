/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 19 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#ifndef __LILY2_TRAITS_TYPE_HH__
#define __LILY2_TRAITS_TYPE_HH__

#include <cstddef>
#include "base/types.hh"
 
namespace LILY2_NS 
{

typedef uint64_t Tick;
typedef uint32_t Addr;
typedef int RegIndex;

typedef uint16_t MachInst;
typedef uint32_t ExtMachInst;

/* Type of operands. */
typedef uint32_t WORD;
typedef int32_t S_WORD;
typedef uint64_t DWORD;
typedef int64_t S_DWORD;
typedef struct {
	WORD _h0;
	WORD _h1;
	WORD _h2;
	WORD _h3;
} QWORD;
typedef float SP;
typedef double DP;

enum Unit {
	No_Unit,
	A,
	M,
	D,
	XA,
	XM,
	XD,
	YA,
	YM,
	YD,
	
	Num_Units
};

enum Mode {
	Risc,
	Vliw
};

} // namespace LILY2_NS 

#endif // __LILY2_TRAITS_TYPE_HH__
