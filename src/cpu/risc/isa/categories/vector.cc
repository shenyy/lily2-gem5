/**
 * copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 06 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */

#include "vector.hh"
#include "cpu/risc/cpu.hh"
#include "cpu/risc/isa/utility.hh"

namespace LILY2_NS
{

/* *********************************************************************
 * *************************** ADDV_A  ********************************
 * ********************************************************************/
ADDV_A::ADDV_A(ExtMachInst mach_inst)
    : StaticInst("ADD.V", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(A);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
        init_dst_regs(1, REG, RD_A, 0);
}

void
ADDV_A::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QWORD op_0 = cpu->read_src_qw_operand(this, 0);
                QWORD op_1 = cpu->read_src_qw_operand(this, 1);

                /* Execution. */
                QWORD final = add(op_0, op_1);

                /* Writing registers. */
                cpu->cache_dst_qw_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
ADDV_A::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** SUBV_A  ********************************
 * ********************************************************************/
SUBV_A::SUBV_A(ExtMachInst mach_inst)
    : StaticInst("SUB.V", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(A);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(2, REG, RS_1_A, REG, RS_2_A);
        init_dst_regs(1, REG, RD_A, 0);
}

void
SUBV_A::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QWORD op_0 = cpu->read_src_qw_operand(this, 0);
                QWORD op_1 = cpu->read_src_qw_operand(this, 1);

                /* Execution. */
                QWORD final = sub(op_0, op_1);

                /* Writing registers. */
                cpu->cache_dst_qw_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
SUBV_A::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** ABSV_A  ********************************
 * ********************************************************************/
ABSV_A::ABSV_A(ExtMachInst mach_inst)
    : StaticInst("ABS.V", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(A);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(1, REG, RS_1_A);
        init_dst_regs(1, REG, RD_A, 0);
}

void
ABSV_A::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QWORD op_0 = cpu->read_src_qw_operand(this, 0);

                /* Execution. */
                QWORD final = absv(op_0);

                /* Writing registers. */
                cpu->cache_dst_qw_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
ABSV_A::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** NEGV_A  ********************************
 * ********************************************************************/
NEGV_A::NEGV_A(ExtMachInst mach_inst)
    : StaticInst("NEG.V", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(A);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(1, REG, RS_1_A);
        init_dst_regs(1, REG, RD_A, 0);
}

void
NEGV_A::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QWORD op_0 = cpu->read_src_qw_operand(this, 0);

                /* Execution. */
                QWORD final = negv(op_0);

                /* Writing registers. */
                cpu->cache_dst_qw_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
NEGV_A::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** QADD_SP_M  ********************************
 * ********************************************************************/
QADD_SP_M::QADD_SP_M(ExtMachInst mach_inst)
    : StaticInst("QADD.SP", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(M);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(2, REG, RS_1_A, REG, RS_2_A );
        init_dst_regs(1, REG, RD_A, 2);
}

void
QADD_SP_M::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QSP op_0 = cpu->read_src_qsp_operand(this, 0);
                QSP op_1 = cpu->read_src_qsp_operand(this, 1);

                /* Execution. */
                QSP final = add(op_0, op_1);

                /* Writing registers. */
                cpu->cache_dst_qsp_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
QADD_SP_M::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** QSUB_SP_M  ********************************
 * ********************************************************************/
QSUB_SP_M::QSUB_SP_M(ExtMachInst mach_inst)
    : StaticInst("QSUB.SP", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(M);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(2, REG, RS_1_A, REG, RS_2_A );
        init_dst_regs(1, REG, RD_A, 2);
}

void
QSUB_SP_M::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QSP op_0 = cpu->read_src_qsp_operand(this, 0);
                QSP op_1 = cpu->read_src_qsp_operand(this, 1);

                /* Execution. */
                QSP final = sub(op_0, op_1);

                /* Writing registers. */
                cpu->cache_dst_qsp_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
QSUB_SP_M::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** QMPY_SP_M  ********************************
 * ********************************************************************/
QMPY_SP_M::QMPY_SP_M(ExtMachInst mach_inst)
    : StaticInst("QMPY.SP", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(M);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(2, REG, RS_1_A, REG, RS_2_A );
        init_dst_regs(1, REG, RD_A, 2);
}

void
QMPY_SP_M::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QSP op_0 = cpu->read_src_qsp_operand(this, 0);
                QSP op_1 = cpu->read_src_qsp_operand(this, 1);

                /* Execution. */
                QSP final = mul(op_0, op_1);

                /* Writing registers. */
                cpu->cache_dst_qsp_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
QMPY_SP_M::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** QDIV_SP_M  ********************************
 * ********************************************************************/
QDIV_SP_M::QDIV_SP_M(ExtMachInst mach_inst)
    : StaticInst("QDIV.SP", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(M);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(2, REG, RS_1_A, REG, RS_2_A );
        init_dst_regs(1, REG, RD_A, 0);
}

void
QDIV_SP_M::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QSP op_0 = cpu->read_src_qsp_operand(this, 0);
                QSP op_1 = cpu->read_src_qsp_operand(this, 1);

                /* Execution. */
                QSP final = div(op_0, op_1);

                /* Writing registers. */
                cpu->cache_dst_qsp_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
QDIV_SP_M::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** QMPYADD_SP_M  ***************************
 * ********************************************************************/
QMPYADD_SP_M::QMPYADD_SP_M(ExtMachInst mach_inst)
    : StaticInst("QMPYADD.SP", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(M);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(3, REG, RS_1_A, REG, RS_2_A, REG, RD_A);
        init_dst_regs(1, REG, RD_A, 2);
}

void
QMPYADD_SP_M::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QSP op_0 = cpu->read_src_qsp_operand(this, 0);
                QSP op_1 = cpu->read_src_qsp_operand(this, 1);
                QSP op_2 = cpu->read_src_qsp_operand(this, 2);

		printf("op0 = 0x%x\n", *(int*)&op_0._h1);
		printf("op1 = 0x%x\n", *(int*)&op_1._h1);
		printf("op2 = 0x%x\n", *(int*)&op_2._h1);

                /* Execution. */
                QSP final = mac(op_0, op_1, op_2);
		//int op0 = 0xbecf817b;
		//int op1 = 0x401de9e7;
		//int op2 = 0x3f800000;
		//float finall = *(float*)&op2 + *(float*)&op1 * *(float*)&op0;
		//float finalll = (float)op_2._h1 + (float)op_1._h1* (float)op_0._h1;
		//std::cout << "finall = 0x" << std::hex << *(int *)(&finall) << ";  val = " << std::dec << finall <<std::endl;
		//printf("final = 0x%x\n", *(int*)&finall);

                /* Writing registers. */
                cpu->cache_dst_qsp_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
QMPYADD_SP_M::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** QNMPYADD_SP_M  ***************************
 * ********************************************************************/
QNMPYADD_SP_M::QNMPYADD_SP_M(ExtMachInst mach_inst)
    : StaticInst("QNMPYADD.SP", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(M);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(2, REG, RS_1_A, REG, RS_2_A );
        init_dst_regs(1, REG, RD_A, 2);
}

void
QNMPYADD_SP_M::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QSP op_0 = cpu->read_src_qsp_operand(this, 0);
                QSP op_1 = cpu->read_src_qsp_operand(this, 1);
                QSP op_2 = cpu->read_src_qsp_operand(this, 2);

                /* Execution. */
                QSP final = nmac(op_0, op_1, op_2);

                /* Writing registers. */
                cpu->cache_dst_qsp_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
QNMPYADD_SP_M::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** QMPYSUB_SP_M  ***************************
 * ********************************************************************/
QMPYSUB_SP_M::QMPYSUB_SP_M(ExtMachInst mach_inst)
    : StaticInst("QMPYSUB.SP", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(M);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(2, REG, RS_1_A, REG, RS_2_A );
        init_dst_regs(1, REG, RD_A, 2);
}

void
QMPYSUB_SP_M::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QSP op_0 = cpu->read_src_qsp_operand(this, 0);
                QSP op_1 = cpu->read_src_qsp_operand(this, 1);
                QSP op_2 = cpu->read_src_qsp_operand(this, 2);

                /* Execution. */
                QSP final = msu(op_0, op_1, op_2);

                /* Writing registers. */
                cpu->cache_dst_qsp_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
QMPYSUB_SP_M::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** QNMPYSUB_SP_M  ***************************
 * ********************************************************************/
QNMPYSUB_SP_M::QNMPYSUB_SP_M(ExtMachInst mach_inst)
    : StaticInst("QNMPYSUB.SP", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(M);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(2, REG, RS_1_A, REG, RS_2_A );
        init_dst_regs(1, REG, RD_A, 2);
}

void
QNMPYSUB_SP_M::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QSP op_0 = cpu->read_src_qsp_operand(this, 0);
                QSP op_1 = cpu->read_src_qsp_operand(this, 1);
                QSP op_2 = cpu->read_src_qsp_operand(this, 2);

                /* Execution. */
                QSP final = nmsu(op_0, op_1, op_2);

                /* Writing registers. */
                cpu->cache_dst_qsp_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
QNMPYSUB_SP_M::generate_disassembly() const
{
        return print_inst();
}

/* *********************************************************************
 * *************************** QSQRT_SP_M  ***************************
 * ********************************************************************/
QSQRT_SP_M::QSQRT_SP_M(ExtMachInst mach_inst)
    : StaticInst("QSQRT.SP", mach_inst)
{
        /* Flags. */
        _flags[Is_32_Bit ]  = true;
        _flags[Is_Cond   ]  = true;

        /* Unit. */
        /* Parameters: A/M/D. */
        init_unit(M);

        /* Immediate. */
        /* Parameters: imm, imm_len. */
        
        /* Registers. */
        /* Parameters: num_src_regs, num_dst_regs, ... */
        init_src_regs(1, REG, RS_1_A);
        init_dst_regs(1, REG, RD_A, 0);
}

void
QSQRT_SP_M::execute(RiscCPU *cpu) const
{
        if(cond_execute(cpu)) {
                /* Reading registers. */
                QSP op_0 = cpu->read_src_qsp_operand(this, 0);

                /* Execution. */
                QSP final = qsqrt(op_0);

                /* Writing registers. */
                cpu->cache_dst_qsp_operand(this, 0, final);
        }
        else {
                _d_ptr->set_op2nop();
        }
}

std::string
QSQRT_SP_M::generate_disassembly() const
{
        return print_inst();
}


} // namespace LILY2_NS

