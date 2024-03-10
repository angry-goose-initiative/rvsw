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
    switch(r_type->funct7){
        case 0b0000001: //m-type extensions
            switch(r_type->funct3){
                case 0b101: //divu
                    //rd <- rs1 / rs2
                    uint32_t result = registers[r_type->rs1 - 1] / registers[r_type->rs2 - 1];
                    dprintf("result of division is %lu", result);
                    registers[r_type->rd - 1] = result;
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
    RVSW_CSRW(mepc, RVSW_CSRR(mepc) + 4);
}
