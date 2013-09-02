/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 06 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#ifndef __RISC_ISA_BITFIELDS_HH__
#define __RISC_ISA_BITFIELDS_HH__
 
#include "base/bitfield.hh"
 
namespace LILY2_NS {
 
#undef  CLUSTER
#define CLUSTER  bits(_mach_inst, 31, 31)
 
#undef  INST_LEN
#define INST_LEN bits(_mach_inst, 30, 29)
 
#undef  UNIT_SEL 
#define UNIT_SEL bits(_mach_inst, 28, 27)
 
#undef  OP_1     
#define OP_1     bits(_mach_inst, 26, 24)
 
#undef  OP_1_B
#define OP_1_B   bits(_mach_inst, 28, 24)
 
#undef  OP_2
#define OP_2     bits(_mach_inst, 23, 19)
 
#undef  OP_2_B
#define OP_2_B   bits(_mach_inst, 23, 21)
 
#undef  OP_3
#define OP_3     bits(_mach_inst, 18, 14)
 
#undef  OP_3_B
#define OP_3_B   bits(_mach_inst, 20, 16)
 
#undef  RS_2_A     
#define RS_2_A   bits(_mach_inst, 18, 14)
 
#undef  RS_1_A
#define RS_1_A   bits(_mach_inst, 13, 9)
 
#undef  RD_A       
#define RD_A     bits(_mach_inst, 8, 4)
 
#undef  RD_B    
#define RD_B     bits(_mach_inst, 4, 0)
 
#undef  CST20_A
#define CST20_A  bits(_mach_inst, 23, 4)
 
#undef  CST16_A
#define CST16_A  bits(_mach_inst, 24, 9)
 
#undef  CST5_A
#define CST5_A   bits(_mach_inst, 18, 14)
 
#undef  MODE
#define MODE     bits(_mach_inst, 22, 19)
 
#undef  Z
#define Z        bits(_mach_inst, 3, 3)
#undef  CREG
#define CREG     bits(_mach_inst, 2, 0)
 
/**
 * Bitfield used to judge the length of instructions
 * Suitable for 16-bit instructions.
 */
#undef  INST_LEN_16
#define INST_LEN_16 bits(_mach_inst, 14, 13)
 
} // namespace LILY2_NS
 
#endif // __RISC_ISA_BITFIELDS_HH__

