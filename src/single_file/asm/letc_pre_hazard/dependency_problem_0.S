# Copyright (C) 2020-2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    addi x31, x0, 1000
    addi x30, x0, 500
    addi x29, x0, 5
    
    sub x31, x31, x29

    #Nops just to see what happens in the pipeline before the sim finishes
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    
    RVSW_EXIT_ASM
