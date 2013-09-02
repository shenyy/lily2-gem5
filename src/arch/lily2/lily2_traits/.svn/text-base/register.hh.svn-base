/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 19 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#ifndef __LILY2_TRAITS_REGISTER_HH__
#define __LILY2_TRAITS_REGISTER_HH__
 
#include <cstddef>
#include "base/types.hh"
 
namespace LILY2_NS
{
	
const int Num_X_Regs = 24;
const int Num_Y_Regs = 24;
const int Num_G_Regs = 8;
const int Num_C_Regs = 32;

const int X_Base_DepTag = 0;
const int Y_Base_DepTag = Num_X_Regs;
const int G_Base_DepTag = Y_Base_DepTag + Num_Y_Regs;
const int C_Base_DepTag = G_Base_DepTag + Num_G_Regs;
const int O_Base_DepTag = C_Base_DepTag + Num_C_Regs;

const WORD Mask_1 = 0xffffffff;
const WORD Mask_0 = 0xffffffff;
const WORD Mask_hi = 0xffff0000;
const WORD Mask_lo = 0x0000ffff;
const QWORD Mask_h3h2h1h0 = { Mask_1, Mask_1, Mask_1, Mask_1 };
const QWORD Mask_h1h0 = { Mask_1, Mask_1, Mask_0, Mask_0 };
const QWORD Mask_h3h2 = { Mask_0, Mask_0, Mask_1, Mask_1 };
const QWORD Mask_h0 = { Mask_1, Mask_0, Mask_0, Mask_0 };
const QWORD Mask_h1 = { Mask_0, Mask_1, Mask_0, Mask_0 };
const QWORD Mask_h2 = { Mask_0, Mask_0, Mask_1, Mask_0 };
const QWORD Mask_h3 = { Mask_0, Mask_0, Mask_0, Mask_1 };
const QWORD Mask_h0_hi = { Mask_hi, Mask_0, Mask_0, Mask_0 };
const QWORD Mask_h0_lo = { Mask_lo, Mask_0, Mask_0, Mask_0 };

const int Max_Src_Regs = 4;
const int Max_Dst_Regs = 1;

/**
 * @todo
 */
enum RegType {
	REG = 1,  /* 32-bit.   */
	REG_PAIR, /* 2*32-bit. */
	DREG,     /* 64-bit.   */
	QREG      /* 128-bit.  */
};

} // namespace LILY2_NS
 
#endif // __LILY2_TRAITS_REGISTER_HH__
