/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 22 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#ifndef __BASE_MY_BASE_MY_MACRO_HH__
#define __BASE_MY_BASE_MY_MACRO_HH__

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <typeinfo>

#define FOR(i,s,e) for(int i=(s); i!=(e); i++)
#define FOE(i,s,e) for(int i=(s); i<=(e); i++)
#define FOD(i,s,e) for(int i=(s-1); i>=(e); i--)
#define FON(i,s,e,n) for(int i=(s); i!=(e); i+=(n)) 
#define CLR(p,n) memset((p),0,(n))
#define SET(p,v,n) memset((p),(v),(n))
#define CPY(d,s,n) memcpy((d),(s),(n))
#define AST assert
#define DPF(s,...) fprintf(stdout,(s),##__VA_ARGS__)
#define ERR(f) if(!(f)) { fprintf(stdout, "Error occurs! File<%s> Line<%u>\n", \
    __FILE__,__LINE__); exit(0); }
#define ASSERT_EQ(a,b) if(!((a)==(b))) { \
    fprintf(stdout, "Error! File<%s> Line<%d>\n",__FILE__,__LINE__); \
    fprintf(stdout, "Answer: ("#a"=%d), Expected: ("#a"==%d).\n",(a),(b)); \
    exit(0); \
}
#define ASSERT_LT(a,b) if(!((a)<(b))) { \
    fprintf(stdout, "Error! File<%s> Line<%d>\n",__FILE__,__LINE__); \
    fprintf(stdout, "Answer: ("#a"=%d), Expected: ("#a"<%d).\n",(a),(b)); \
    exit(0); \
}
#define ASSERT_LTE(a,b) if(!((a)<=(b))) { \
    fprintf(stdout, "Error! File<%s> Line<%d>\n",__FILE__,__LINE__); \
    fprintf(stdout, "Answer: ("#a"=%d), Expected: ("#a"<=%d).\n",(a),(b)); \
    exit(0); \
}
#define ASSERT_GT(a,b) if(!((a)>(b))) { \
    fprintf(stdout, "Error! File<%s> Line<%d>\n",__FILE__,__LINE__); \
    fprintf(stdout, "Answer: ("#a"=%d), Expected: ("#a">%d).\n",(a),(b)); \
    exit(0); \
}
#define ASSERT_GTE(a,b) if(!((a)>=(b))) { \
    fprintf(stdout, "Error! File<%s> Line<%d>\n",__FILE__,__LINE__); \
    fprintf(stdout, "Answer: ("#a"=%d), Expected: ("#a">=%d).\n",(a),(b)); \
    exit(0); \
}

#endif // __BASE_MY_BASE_MY_MACRO_HH__
