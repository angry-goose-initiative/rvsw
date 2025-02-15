# Copyright (C) 2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    la  x30, halfword

    lh  x31, 0(x30)
    lhu x31, 0(x30)

    lh  x31, 2(x30)
    lhu x31, 2(x30)

    lh  x31, 4(x30)
    lhu x31, 4(x30)

    lh  x31, 6(x30)
    lhu x31, 6(x30)
    
    RVSW_EXIT_ASM
    
halfword:
    .half 0xABCD
    .half 0x1234
    .half 0xEF56
    .half 0x7890
