/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 15 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "utility.hh"

namespace LILY2_NS
{
/*******************************added_by_houyumin******************************/
/**
 * calculate the exponential value of a float number, 
 * based with 2, e and 10
 *
template <class T>
T
exp(T op_1, int op_2)
{
  int select_bit = bits(op_2, 4, 0);
  float e = 2.71828
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
 *
template <class T>
T
log(T op_1, int op_2)
{
  int select_bit = bits(op_2, 4, 0);
  float e = 2.71828
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
 *
template <class T>
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
 *
template <class T>
uint
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
 *
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


/*******************************added_by_houyumin******************************/	
} // namespace LILY2_NS
