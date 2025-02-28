# Copyright (C) 2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    #This is just setup so we don't overwrite instructions for this test
    #It does not affect things; add a bunch of nops to clear the pipeline
    la      a4,data
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

    #An arithmetic operation that ACTUALLY MODIFIES THE ADDRESS must be present right before the jump
    addi    a4,a4,1
    j problem

    #nop#If this nop is added, then the test passes, otherwise we mismatch IRVE

    #The nops don't matter, but the stores must be present as so for the failure to occur
    sb      x0,14(a4)
    sb      x0,13(a4)
    nop
    sb      x0,11(a4)
    nop
    nop
problem:
    #The address stored to by this store is wrong
    sb      x0,8(a4)

    RVSW_EXIT_ASM

.data
data:
    .word 0x12345678
    .word 0xABCDABCD
    .word 0x01010101
