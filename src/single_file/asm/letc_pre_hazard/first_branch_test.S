# Copyright (C) 2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    li x1, 100
    nop
    nop
    nop
    
subtraction_loop:
    addi x1, x1, -1
    nop
    nop
    nop
    bne x1, x0, subtraction_loop
    nop
    nop
    nop

    RVSW_EXIT_ASM
