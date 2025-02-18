# Copyright (C) 2025 Nick Chan
# Copyright (C) 2025 John Jekel
# See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    la x1, data

    lb x2, 0(x1)
    lb x2, 1(x1)
    lb x2, 2(x1)
    lb x2, 3(x1)
    lbu x2, 0(x1)
    lbu x2, 1(x1)
    lbu x2, 2(x1)
    lbu x2, 3(x1)

    lh x2, 0(x1)
    lh x2, 2(x1)
    lhu x2, 0(x1)
    lhu x2, 2(x1)

    lw x2, 0(x1)

    sw x2, 0(x1)
    lw x2, 0(x1)

    sh x2, 0(x1)
    sh x2, 2(x1)
    lw x2, 0(x1)

    sb x2, 0(x1)
    srli x2, x2, 8
    sb x2, 1(x1)
    srli x2, x2, 8
    sb x2, 2(x1)
    srli x2, x2, 8
    sb x2, 3(x1)
    lw x2, 0(x1)

    RVSW_EXIT_ASM

data:
    .word 0x01889977
