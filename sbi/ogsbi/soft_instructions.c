/**
 * @file    soft_instructions.c
 * @brief   Code to emulate unsupported instructions caused by illegal instruction exceptions
 * 
 * @copyright
 *  Copyright (C) 2024 Eric Jessee\n
 *  See the LICENSE file at the root of the project for licensing info.
 *
*/

#include "asm_c_interface.h"
#include "common.h"
#include "soft_instructions.h"
#include "rvsw.h"

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

void handle_r_type(inst_r_t *r_type, uint32_t *registers){
    dputs("handling r-type instruction");
    int32_t result;
    uint32_t u_result;
    int64_t llresult;
    uint64_t u_llresult;
    //decrement rd, rs1, rs2 for convenience(index is off by 1)
    r_type->rd--;
    r_type->rs1--;
    r_type->rs2--;
    switch(r_type->funct7){
        case 0b0000001: //m-type extensions
            switch(r_type->funct3){
                case MUL:
                    result = (int32_t)registers[r_type->rs1] * (int32_t)registers[r_type->rs2];
                    registers[r_type->rd] = (uint32_t)result;
                    break;
                case MULH: //upper 32 bits of signed*signed -- double cast is necessary for sign extension
                    llresult = (int64_t)((int32_t)registers[r_type->rs1]) * (int64_t)((int32_t)registers[r_type->rs2]);
                    registers[r_type->rd] = (uint32_t)(llresult>>32);
                    break;
                case MULHU: //upper 32 bits of unsigned*unsigned
                    u_llresult = (uint64_t)registers[r_type->rs1] * (uint64_t)registers[r_type->rs2];
                    registers[r_type->rd] = (uint32_t)(u_llresult>>32);
                    break;
                case MULHSU: //upper 32 bits of signed*unsigned
                    llresult = (int64_t)((int32_t)registers[r_type->rs1]) * (int64_t)((uint64_t)registers[r_type->rs2]);
                    registers[r_type->rd] = (uint32_t)(llresult>>32);
                    break;
                case DIV:
                    if (!registers[r_type->rs2]){ //divide by 0
                        result = 0xffffffff;
                    } else if ((registers[r_type->rs1] == 0x80000000) && registers[r_type->rs2] == 0xffffffff) { //overflow
                        result = 0x80000000;
                    } else {
                        result = (int32_t)registers[r_type->rs1] / (int32_t)registers[r_type->rs2];
                    }
                    registers[r_type->rd] = (uint32_t)result;
                    break;
                case DIVU:
                    if (!registers[r_type->rs2]){
                        u_result = 0xffffffff;
                    } else {
                        u_result = registers[r_type->rs1] / registers[r_type->rs2];
                    }
                    registers[r_type->rd] = u_result;
                    break;
                case REM:
                    if (!registers[r_type->rs2]){
                        result = registers[r_type->rs1];
                    } else if ((registers[r_type->rs1] == 0x80000000) && registers[r_type->rs2] == 0xffffffff) { //overflow
                        result = 0;                                                                                           
                    } else {
                        result = (int32_t)registers[r_type->rs1] % (int32_t)registers[r_type->rs2];
                    }
                    registers[r_type->rd] = (uint32_t)result;
                    break;
                case REMU:
                    if (!registers[r_type->rs2]){
                        u_result = registers[r_type->rs1];
                    } else {                
                        u_result = registers[r_type->rs1] % registers[r_type->rs2];
                    }
                    registers[r_type->rd] = u_result;
                    break;
                default: 
                    assert(false && "unimplemented m-type instruction!");
                    break;
            }
            break;
        default:
            assert(false && "unsupported instruction!");
            break;
    }
}

void soft_instruction_handler(uint32_t mepc, uint32_t *registers){
    dputs("entered the soft exception handler\n");
    decoded_inst_t inst = (decoded_inst_t)virtual_read_word((uint32_t*)mepc);
    assert(((inst.primitive.opcode & 0b11) == 0b11) && "fetched instruction is invalid!");
    //opcodes in decode.h are assumed to be inst[6:2]
    inst.primitive.opcode >>= 2;
    switch (inst.primitive.opcode){
        case OP:
            handle_r_type(&inst.r_type, registers);
            break;
        default:
            assert(false && "unsupported opcode!!");
            break;
    }
    //need to increment the pc after handling the instruction
    dputs("finished handling instruction, returning...");
    RVSW_CSRW(mepc, RVSW_CSRR(mepc) + 4);
}

void misaligned_instruction_handler([[maybe_unused]]uint32_t mepc){
    dprintf("mepc value is 0x%lx", mepc);
    assert(false && "TODO implement misaligned instructions");
}

void misaligned_load_handler([[maybe_unused]]uint32_t mepc){
    dprintf("mepc value is 0x%lx", mepc);
    assert(false && "TODO implement misaligned loads");
}

void misaligned_store_handler([[maybe_unused]]uint32_t mepc){
    dprintf("mepc value is 0x%lx", mepc);
    assert(false && "TODO implement misaligned stores (no amo)");
}
