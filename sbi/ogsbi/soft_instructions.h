/**
 * @file    soft_instructions.h
 * @brief   Code to emulate unsupported instructions caused by illegal instruction exceptions
 * 
 * @copyright
 *  Copyright (C) 2024 Eric Jessee\n
 *  See the LICENSE file at the root of the project for licensing info.
 *
*/

#include <stdint.h>

//taken from irve/lib/decode.h
//these correspond to bits [6:2] in the instruction (since [1:0] are always 1)
typedef enum {
    LOAD = 0b00000      , LOAD_FP = 0b00001   , CUSTOM_0 = 0b00010  , MISC_MEM = 0b00011  ,
    OP_IMM = 0b00100    , AUIPC = 0b00101     , OP_IMM_32 = 0b00110 , B48_0 = 0b00111     ,
    STORE = 0b01000     , STORE_FP = 0b01001  , CUSTOM_1 = 0b01010  , AMO = 0b01011       ,
    OP = 0b01100        , LUI = 0b01101       , OP_32 = 0b01110     , B64 = 0b01111       ,
    MADD = 0b10000      , MSUB = 0b10001      , NMSUB = 0b10010     , NMADD = 0b10011     ,
    OP_FP = 0b10100     , RESERVED_0 = 0b10101, CUSTOM_2 = 0b10110  , B48_1 = 0b10111     ,
    BRANCH = 0b11000    , JALR = 0b11001      , RESERVED_1 = 0b11010, JAL = 0b11011       ,
    SYSTEM = 0b11100    , RESERVED_3 = 0b11101, CUSTOM_3 = 0b11110  , BGE80 = 0b11111,
} rv32_opcode_e;

//referenced from irve/lib/execute.cpp
typedef enum {
    MUL = 0b000         ,
    MULH = 0b001        ,
    MULHSU = 0b010      ,
    MULHU = 0b011       ,
    DIV = 0b100         ,
    DIVU = 0b101        ,
    REM = 0b110         ,
    REMU = 0b111        ,
} rv32_funct3_e;

//the compiler should pack these values into a 32-bit word based on the given bit fields
//Empirically with GCC on RISC-V bitfield structs seem to always be ordered from lsb->msb
typedef struct __attribute__ ((packed)) {
    rv32_opcode_e  opcode : 7;
    uint32_t       rd     : 5;
    rv32_funct3_e  funct3 : 3;
    uint32_t       rs1    : 5;
    uint32_t       rs2    : 5;
    uint32_t       funct7 : 7;
} inst_r_t;

typedef struct __attribute__ ((packed)) {
    rv32_opcode_e opcode : 7; //first 7 bits are always the opcode
    uint32_t      rem    : 25;
} inst_primitive_t;

//based on the opcode, we can decide which member of
//this union we can access for the proper bit fields
typedef union {
    uint32_t raw; //ensure the compiler knows this data should be 32 bits wide
    inst_primitive_t primitive; //don't assume instruction type before checking opcode
    inst_r_t r_type;
    //TODO: other types?
} decoded_inst_t;

void handle_r_type(inst_r_t *r_type, uint32_t *registers);
void soft_instruction_handler(uint32_t mepc, uint32_t *registers);
void misaligned_instruction_handler(uint32_t mepc);
void misaligned_load_handler(uint32_t mepc);
void misaligned_store_handler(uint32_t mepc);
