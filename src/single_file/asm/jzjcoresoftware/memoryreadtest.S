# Copyright (C) 2020-2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    lw x31, 8(x0)
    RVSW_EXIT_ASM
    .word 2863311530
