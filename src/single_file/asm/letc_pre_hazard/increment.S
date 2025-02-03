# Copyright (C) 2020-2024 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    #Init to 1
    addi x1, x0, 1
    nop
    nop
    nop
    addi x1, x1, 1
    nop
    nop
    nop
    addi x1, x1, 1
    nop
    nop
    nop
    addi x1, x1, 1
    nop
    nop
    nop
    RVSW_EXIT_ASM
