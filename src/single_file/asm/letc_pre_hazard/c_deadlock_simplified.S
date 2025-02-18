# Copyright (C) 2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    la      x31, data

    #Two back to back ALIASING stores are the problem
    sw      x0, 0(x31)
    sw      x0, 0(x31)

    #Aliasing within a word of memory that is, so these are also problematic
    sh      x0, 0(x31)
    sh      x0, 2(x31)

    #These too
    sb      x0, 0(x31)
    sb      x0, 3(x31)

    RVSW_EXIT_ASM

data:
    .word 0xABCD1234
