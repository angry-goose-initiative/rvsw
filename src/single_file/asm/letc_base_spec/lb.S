# Copyright (C) 2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    la  x30, byte

    lb  x31, 0(x30)
    lbu x31, 0(x30)

    lb  x31, 1(x30)
    lbu x31, 1(x30)

    lb  x31, 2(x30)
    lbu x31, 2(x30)

    lb  x31, 3(x30)
    lbu x31, 3(x30)
    
    RVSW_EXIT_ASM
    
byte:
    .byte 0xAB
    .byte 0xCD
    .byte 0x12
    .byte 0x34
