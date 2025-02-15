# Copyright (C) 2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    la x30, word 
    lw x31, 0(x30)

    la  x30, halfword
    lh  x31, 0(x30)
    lhu x31, 0(x30)

    la  x30, byte
    lb  x31, 0(x30)
    lbu x31, 0(x30)
    
    RVSW_EXIT_ASM
    
word:
    .word 0xABCD1234
halfword:
    .byte 0xCD
    .byte 0xAB
byte:
    .word 0xAB
