/**
 * Copyright (C) Tsinghua University 2013
 *
 * Version : 1.0
 * Date    : 22 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#ifndef __RISC_RESOURCES_RESOURCE_HH__
#define __RISC_RESOURCES_RESOURCE_HH__

#include "base/my_base/my_macro.hh"
#include "arch/lily2/lily2_traits/type.hh"

// Forward Declaration
class RiscCPU;

namespace LILY2_NS
{

class Resource
{
protected:
    /**
     * _NUM_RES specifies how many kinds of resources does one module
     * own(e.g. A register file has two kinds of resources: register
     * reading ports and register writing ports.)
     */
    const int _num_res;

    /**
     * _MAX_RES is an array of the maximum numbers of the resources.
     *
     * @todo : Static memory allocation or dynamic?
     */
    int *_max_res;

    /**
     * _CPU is the pointer to the top module cpu. If you want to access
     * other modules in the cpu, this pointer is exactly what you need.
     */
    RiscCPU *_cpu;

    /**
     * Resource statistic variables.
     */
    int *_num_res_used_tick;
    int *_num_res_used_total;

public:
    /**
     * No-args constructor.
     * Strongly recommended no to use it because this means you need not
     * any resources and pointer to cpu in your derived class which i
     * think is impossible and nonsense.
     */
    Resource(void);

    /**
     * Constructor.
     * You can use this constructor if your derived class need not
     * pointer to the cpu.
     *
     * @param (num_res) : kinds of resources.
     * @param (...)     : Variable parameters, maximum of resorces.
     */
    Resource(int num_res, ...);

    /**
     * Constructor.
     * You can use this constructor if your derived class need not any
     * resources.
     *
     * @param (cpu) : Pointer to cpu.
     */
    Resource(RiscCPU *cpu);

    /**
     * Recommended constructors!
     * The design philosophy of Lily2 emulator is every module should
     * have their own resources and a pointer to the top module. A
     * uniform ABI is clear and comfortable.
     *
     * @param (cpu)     : Pointer to cpu.
     * @param (num_res) : kinds of resources.
     * @param (...)     : Variable parameters, maximum of resorces.
     */
    Resource(RiscCPU *cpu, int num_res, ...);

    /**
     * Abstract class must have a virtual destructor.
     */
    virtual ~Resource(void);

public:
    /**
     * Get the number of resource kinds.
     */
    virtual int get_num_res(void) { return _num_res; }

    /**
     * Check whether there is no resources.
     *
     * @param (res_idx) : Index of the resources.
     * @param (delta)   : Increment, default value is 1.
     *
     * @return : No resources or not.
     */
    virtual bool no_res(int res_idx, int delta = 1);

    /**
     * Increase tick-used and total-used resources.
     *
     * @param (res_idx) : Index of the resources.
     * @param (delta)   : Increment, default value is 1.
     */
    virtual void incr_res(int res_idx, int delta = 1);

    /**
     * Clear the tick-used resources.
     */
    virtual void clr_res(void);
};

} // namespace LILY2_NS

#endif // __RISC_RESOURCES_RESOURCE_HH__
