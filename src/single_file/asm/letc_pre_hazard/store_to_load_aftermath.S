# Copyright (C) 2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    la x30, word

    li x31, 0xABCD1234
    sw x31, 0(x30)
    lw x29, 0(x30)

    addi x1, x0, 0x111
    addi x2, x0, 0x222
    addi x3, x0, 0x333
    addi x4, x0, 0x444
    addi x5, x0, 0x555
    addi x6, x0, 0x666
    addi x7, x0, 0x777

    RVSW_EXIT_ASM

word:
    .word 0xDEADBEEF
