# Copyright (C) 2025 Nick Chan
# Copyright (C) 2025 John Jekel
# See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    jal x1, label1
    li x2, 3
    nop
    nop
    nop
    nop
label1:
    jal x3, label2
    li x4, 5
    nop
label2:
    jal x5, label3
    li x6, 7
    nop
    nop
label3:
    RVSW_EXIT_ASM
