# Copyright (C) 2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    la x30, word

    li x31, 0x77777777
    sw x31, 0(x30)
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lw x29, 0(x30)

    li x31, 0x66666666
    sw x31, 0(x30)
    nop
    nop
    nop
    nop
    nop
    nop
    lw x29, 0(x30)

    li x31, 0x55555555
    sw x31, 0(x30)
    nop
    nop
    nop
    nop
    nop
    lw x29, 0(x30)

    li x31, 0x44444444
    sw x31, 0(x30)
    nop
    nop
    nop
    nop
    lw x29, 0(x30)

    li x31, 0x33333333
    sw x31, 0(x30)
    nop
    nop
    nop
    lw x29, 0(x30)

    li x31, 0x22222222
    sw x31, 0(x30)
    nop
    nop
    lw x29, 0(x30)

    li x31, 0x11111111
    sw x31, 0(x30)
    nop
    lw x29, 0(x30)

    li x31, 0x00000000
    sw x31, 0(x30)
    lw x29, 0(x30)

    RVSW_EXIT_ASM

word:
    .word 0xDEADBEEF
