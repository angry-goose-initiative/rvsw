#include "asm_c_interface.h"
#include "common.h"
#include "soft_exceptions.h"

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

void handle_r_type(inst_r_t *r_type, uint32_t *registers){
    dprintf("first reg contains 0x%lx", registers[0]);
    dprintf("funct7 is %d", r_type->funct7);
}

void soft_exception_handler(uint32_t mepc, uint32_t *registers){
    dputs("entered the soft exception handler\n");
    decoded_inst_t inst = (decoded_inst_t)virtual_read_word((uint32_t*)mepc);
    assert(((inst.primitive.opcode & 0b11) == 0b11) && "fetched instruction is invalid!");
    //opcodes in decode.h are assumed to be inst[6:2]
    inst.primitive.opcode >>= 2;
    switch (inst.primitive.opcode){
        case OP:
            dputs("found r-type instruction");
            handle_r_type(&inst.r_type, registers);
            break;
        default:
            assert(false && "unsupported opcode from emulated instruction!!");
            break;
    }
}