/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 15 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/includes.hh"

#ifndef __RISC_ISA_UTILITY_HH__
#define __RISC_ISA_UTILITY_HH__

namespace LILY2_NS
{
	
template <class T>
inline
T add(T op_0, T op_1)
{
	return op_0 + op_1;
}

template <class T>
inline
T sub(T op_0, T op_1)
{
	return op_0 - op_1;
}

template <class T>
inline
T max(T op_0, T op_1)
{
	return op_0>op_1 ? op_0 : op_1;
}

template <class T>
inline
T min(T op_0, T op_1)
{
	return op_0<op_1 ? op_0 : op_1;
}

template <class T>
inline
T abs(T op)
{
	return op>=0 ? op : -op;
}

template <class T>
inline
T neg(T op)
{
	return -op;
}

template <class T>
inline
T bit_and(T op_0, T op_1)
{
	return op_0 & op_1;
}

template <class T>
inline
T bit_or(T op_0, T op_1)
{
	return op_0 | op_1;
}

template <class T>
inline
T bit_nand(T op_0, T op_1)
{
	return ~(op_0 & op_1);
}

template <class T>
inline
T bit_nor(T op_0, T op_1)
{
	return ~(op_0 | op_1);
}

template <class T>
inline
T bit_xor(T op_0, T op_1)
{
	return op_0 ^ op_1;
}

template <class T>
inline
T bit_xnor(T op_0, T op_1)
{
	return ~(op_0 ^ op_1);
}

template <class T>
inline
T bit_not(T op)
{
	return ~op;
}

template <class T>
inline
T bit_andn(T op_0, T op_1)
{
	return op_0 & (~op_1);
}

template <class T>
inline
T bit_orn(T op_0, T op_1)
{
	return op_0 | (~op_1);
}

template <class T>
inline
T bit_xorn(T op_0, T op_1)
{
	return op_0 ^ (~op_1);
}

template <class T>
inline
T bit_xor3(T op_0, T op_1)
{
	return op_0 ^ (op_0+1) ^ op_1;
}

template <class T>
inline
T cmpeq(T op_0, T op_1)
{
    return op_0==op_1 ? 0xffffffff : 0;	
}

template <class T>
inline
T cmpneq(T op_0, T op_1)
{
    return op_0==op_1 ? 0 : 0xffffffff;	
}

template <class T>
inline
T cmpgt(T op_0, T op_1)
{
	return op_0>op_1 ? 0xffffffff : 0;
}

template <class T>
inline
T cmplt(T op_0, T op_1)
{
	return op_0<op_1 ? 0xffffffff : 0;
}

inline
WORD put_byte(WORD op_0, WORD op_1)
{
	int select_bit = bits(op_0, 25, 24);
	WORD byte = bits(op_0, 7, 0);
	WORD val = op_1;
	
	switch(select_bit)
	{
		case 0x0: {
			replaceBits(val, 7, 0, byte);
			break;
		}
		case 0x1: {
			replaceBits(val, 15, 8, byte);
			break;
		}
		case 0x2: {
			replaceBits(val, 23, 16, byte);
			break;
		}
		case 0x3: {
			replaceBits(val, 31, 24, byte);
		}
	}
	
	return val;
}

inline
WORD select_byte(WORD op_0, WORD op_1)
{
	int select_bit = bits(op_1, 1, 0);
	WORD byte;
	WORD val = op_1;
	
	switch(select_bit)
	{
		case 0x0: {
			byte = bits(op_0, 7, 0);
			break;
		}
		case 0x1: {
			byte = bits(op_0, 15, 8);
			break;
		}
		case 0x2: {
			byte = bits(op_0, 23, 16);
			break;
		}
		case 0x3: {
			byte = bits(op_0, 31, 24);
		}
	}
	
	replaceBits(val, 7, 0, byte);
	return val;
}

inline
WORD extract_sign(WORD op_0, WORD op_1)
{
	WORD lsbBit = bits(op_1, 15, 8);
	WORD bitLen = bits(op_1, 7, 0);
	WORD msbBit = lsbBit + bitLen - 1;
	WORD val;
	
	if(msbBit <= 31) {
		val = bits(op_0, msbBit, lsbBit);
		return bits(val, bitLen, bitLen) ? (val | ~mask(bitLen)) : val;
	}
	else {
		return 0xffffffff;
	}
}

inline
WORD extract_unsign(WORD op_0, WORD op_1)
{
	WORD lsbBit = bits(op_1, 15, 8);
	WORD bitLen = bits(op_1, 7, 0);
	WORD msbBit = lsbBit + bitLen - 1;
	
	if(msbBit <= 31) {
		return bits(op_0, msbBit, lsbBit);
	}
	else {
		return 0x00000000;
	}
}

inline
WORD asl(WORD op, WORD shift_amount)
{
	return op << bits(shift_amount, 4, 0);
}

inline
WORD asr(WORD op, WORD shift_amount)
{
	WORD sa = bits(shift_amount, 4, 0);
	WORD tmp = op >> sa;
	int sign_bit = bits(tmp, 31 - sa, 31 - sa);
    return sign_bit ? (tmp | ~mask(32 - sa)) : tmp;
}

inline
WORD lsr(WORD op, WORD shift_amount)
{
	return op >> bits(shift_amount, 4, 0);
}


/**
 * Float point division
 */
template <typename T>
inline 
T
div(T op_1, T op_2)
{
	return op_1 / op_2;
}

/**
 * float multiply
 */
template <class T>
inline
T
mul(T op_1, T op_2)
{
	return op_1*op_2;
}


/**
 * float accumulation after multiply 
 */
template <class T>
inline
T
mac(T op_1, T op_2, T op_3)
{
	return op_1*op_2+op_3;
}


/**
 * float negation after multi-acc 
 */
template <class T>
inline
T
nmac(T op_1, T op_2, T op_3)
{
	return -(op_1*op_2+op_3);
}


/**
 * float  subtration after multiply 
 */
template <class T>
inline
T
msu(T op_1, T op_2, T op_3)
{
	return op_1*op_2-op_3;
}


/**
 * float  negation after multi-sub 
 */
template <class T>
inline
T
nmsu(T op_1, T op_2, T op_3)
{
	return -(op_1*op_2-op_3);
}


/**
 * calculate the square root of a float number
 */
template <class T>
inline
T
sqrt(T op)
{
	return sqrt(op);
}


/**
 * calculate the reciprocal of a float number
 */
template <class T>
inline
T
rcp(T op)
{
	return 1 / op;
}


/**
 * calculate the reciprocal of the square root of a float number
 */
template <class T>
inline
T
rsqr(T op)
{
	return 1 / sqrt(op);
}


/**
 * calculate the exponential value of a float number, 
 * based with 2, e and 10
 */
template <class T>
inline
T
exp(T op_1, int op_2)
{
  int select_bit = bits(op_2, 4, 0);
  float e = 2.71828;
  T val = 0;
  switch(select_bit)
  {
    case 0x4: {
                val = pow(2 , op_1) ;    
            break;
     }
    case 0x5: {
                val = pow(e , op_1) ; 
            break;
     }
    case 0x6: {
                val = pow(10 , op_1) ;   
            break;
     }
  }
  return val;
}


/**
 * calculate the logarithm value of a float number, 
 * based with 2, e and 10
 */
template <class T>
inline
T
log(T op_1, int op_2)
{
  int select_bit = bits(op_2, 4, 0);
  float e = 2.71828;
  T val = 0;
  switch(select_bit)
  {
    case 0x4: {
                val = log(2 , op_1) ;    
            break;
     }
    case 0x5: {
                val = log(e , op_1) ; 
            break;
     }
    case 0x6: {
                val = log(10 , op_1) ;   
            break;
     }
  }
  return val;
}


/**
 * round float point numbers  ROUNDSP/DP 
 * T1:float/double T2:int/float/double
 */
template <class T1, class T2>
inline
T2
round(T1 op_1, int op_2)
{
  int select_bit = bits(op_2, 1, 0);
  T2 val;
  T2 v_up;
  T2 v_dw;

   v_up = ceil(op_1);
   v_dw = floor(op_1);

  switch(select_bit)
  {
    case 0x0: {
                val = floor(op_1 + 0.5);  
            break;
     }
    case 0x1: {
                if(op_1>=0)
                val = v_dw ;  
                else
                val = v_up ; 
            break;
     }
    case 0x2: {
                val =  v_up ;  
            break;
     }
    case 0x3: {
                val = v_dw;  
            break;
     }
  }
  return val;
}



/**
 * change float numbers to unsigned int form SP/DPINTU
 */
template <class T>
inline
uint32_t
flt_to_uint(T op_1, int op_2)
{
  int select_bit = bits(op_2, 1, 0);
  uint val;
  uint v_up;
  uint v_dw;

   v_up = ceil(abs(op_1));
   v_dw = floor(abs(op_1));

  switch(select_bit)
  {
    case 0x0: {
                val = floor(abs(op_1) + 0.5);     
            break;
     }
    case 0x2: {
                val =  v_up ;  
            break;
     }
    case 0x3: {
                val = v_dw ;  
            break;
     }
  }
  return val;
}


/**
 * change double numbers into float form  DPSP
 */
inline
float
doub_to_flt(double op_1, int op_2, int op_3)
{
  float  val;
  double temp;
  float  v_up;
  float  v_dw;  
  
  int select_bit = bits(op_2, 1, 0);
  temp = op_1 * pow(10, op_3);
  v_up = ceil(temp)/pow(10, op_3);
  v_dw = floor(temp)/pow(10, op_3);
 
  switch(select_bit)
  {
    case 0x0: {
                val = floor(temp + 0.5)/pow(10, op_3);  
            break;
     }
    case 0x1: {
                if(op_1>=0)
                val = v_dw ;  
                else
                val = v_up ; 
            break;
     }
    case 0x2: {
                val =  v_up ;  
            break;
     }
    case 0x3: {
                val = v_dw;  
            break;
     }
  }
  return val;
}
/**
 * change int/uint numbers into float/double form  INTSP
 */
template <class T1, class T2>
inline
T2
int_uint_flt(T1 op)
{
	T2 val;
	val = op;
	return val;
}


/**
 * change float numbers into double form  SPDP
 */
inline
double
flt_to_doub(float op)
{
  double val;
  val = op;
  return val;
}

/**
 * vector abs
 * added by shenyuanyi
 */
inline
QWORD
absv(QWORD op_0)
{
	QWORD val;
	if (op_0._h0 > 0)
		{
			val._h0 = op_0._h0;
		}
	else if (op_0._h0 < 0)
		{
			val._h0 = -op_0._h0;
		}
	else val._h0 = op_0._h0;
	
	if (op_0._h1 > 0)
		{
			val._h1 = op_0._h1;
		}
	else if (op_0._h1 < 0)
		{
			val._h1 = -op_0._h1;
		}
	else val._h1 = op_0._h1;

	if (op_0._h2 > 0)
		{
			val._h2 = op_0._h2;
		}
	else if (op_0._h2 < 0)
		{
			val._h2 = -op_0._h2;
		}
	else val._h2 = op_0._h2;

	if (op_0._h3 > 0)
		{
			val._h3 = op_0._h3;
		}
	else if (op_0._h3 < 0)
		{
			val._h3 = -op_0._h3;
		}
	else val._h3 = op_0._h3;

	return val;
}

/**
 * vector neg  
 * added by shenyuanyi
 */
inline
QWORD
negv(QWORD op_0)
{
	QWORD val;
	val._h0 = -op_0._h0;
	val._h1 = -op_0._h1;
	val._h2 = -op_0._h2;
	val._h3 = -op_0._h3;
	return val;
}

/**
 * select 32 bits from 128bit number using const
 * added by shenyuanyi
 */
inline
WORD
QFselect(QWORD op_0, int _imm)
{
	WORD val;
	switch (_imm){
		case 0: 
			val = op_0._h0;
			break;
		case 1:
			val = op_0._h1;
			break;
		case 2: 
			val = op_0._h2;			
			break;
		case 3:
			val = op_0._h3;
			break;
		default: 
			val = 0; 
			break;
	}
	return val;
}

/**
 * vector sqrt
 * added by shenyuanyi
 */
inline
QSP
qsqrt(QSP op_0)
{
	QSP val;
	val._h0 = sqrt(op_0._h0);
	val._h1 = sqrt(op_0._h1);
	val._h2 = sqrt(op_0._h2);
	val._h3 = sqrt(op_0._h3);
	return val;
}

} // namespace LILY2_NS

#endif // __RISC_ISA_UTILITY_HH__
