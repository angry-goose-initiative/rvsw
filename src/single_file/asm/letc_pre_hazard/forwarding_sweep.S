# Copyright (C) 2025 Nick Chan
# Copyright (C) 2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    addi x1, x0, 1

    addi x1, x1, 2
    addi x1, x1, 4

    nop
    addi x1, x1, 8
    nop
    addi x1, x1, 16

    nop
    nop
    addi x1, x1, 32
    nop
    nop
    addi x1, x1, 64

    nop
    nop
    nop
    addi x1, x1, 128
    nop
    nop
    nop
    addi x1, x1, 256

    nop
    nop
    nop
    nop
    addi x1, x1, 512
    nop
    nop
    nop
    nop
    addi x1, x1, 1024
    
    RVSW_EXIT_ASM
