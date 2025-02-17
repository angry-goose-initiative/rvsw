# Copyright (C) 2025 Nick Chan
# Copyright (C) 2025 John Jekel
# See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    la x1, load_data
    li x2, 0
    lw x2, 0(x1)
    addi x2, x2, 1

    RVSW_EXIT_ASM

load_data:
    .word 0x11223344
