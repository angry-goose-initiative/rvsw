# Copyright (C) 2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    la x30, word 
    lw x31,  0(x30)
    lw x31,  4(x30)
    lw x31,  8(x30)
    lw x31, 12(x30)
    
    RVSW_EXIT_ASM
    
word:
    .word 0xABCD1234
    .word 0xEF567890
    .word 0x12481632
    .word 0x31415926
