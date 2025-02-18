# Copyright (C) 2025 John Jekel
#See the LICENSE file at the root of the project for licensing info
#include "rvsw_asm.h"

.section .reset, "ax"
.global ___rvsw_reset___
___rvsw_reset___:
    la      a0,data
    li      a1,0xA5
    li      a2,0x9
    addi    a0,a0,1
    call    memset
    RVSW_EXIT_ASM

memset:
    li      t1,15
    mv      a4,a0
    bgeu    t1,a2,branch_target_0
    andi    a5,a4,15
    bnez    a5,branch_target_1
branch_target_5:
    bnez    a1,branch_target_2
branch_target_4:
    andi    a3,a2,-16
    andi    a2,a2,15
    add     a3,a3,a4
branch_target_3:
    sw      a1,0(a4)
    sw      a1,4(a4)
    sw      a1,8(a4)
    sw      a1,12(a4)
    addi    a4,a4,16
    bltu    a4,a3,branch_target_3
    bnez    a2,branch_target_0
    ret
branch_target_0:
    sub     a3,t1,a2
    slli    a3,a3,0x2
    auipc   t0,0x0
    add     a3,a3,t0

    #This is the last instruction that retires before LETC deadlocks
    jr      12(a3)

    sb      a1,14(a4)
    sb      a1,13(a4)
    sb      a1,12(a4)
    sb      a1,11(a4)
    sb      a1,10(a4)
    sb      a1,9(a4)
    sb      a1,8(a4)
    sb      a1,7(a4)
    sb      a1,6(a4)
    sb      a1,5(a4)
    sb      a1,4(a4)
    sb      a1,3(a4)
    sb      a1,2(a4)
    sb      a1,1(a4)
    sb      a1,0(a4)
    ret
branch_target_2:
    zext.b  a1,a1
    slli    a3,a1,0x8
    or      a1,a1,a3
    slli    a3,a1,0x10
    or      a1,a1,a3
    j       branch_target_4
branch_target_1:
    slli    a3,a5,0x2
    auipc   t0,0x0
    add     a3,a3,t0
    mv      t0,ra
    jalr    -96(a3)
    mv      ra,t0
    addi    a5,a5,-16
    sub     a4,a4,a5
    add     a2,a2,a5
    bgeu    t1,a2,branch_target_0
    j       branch_target_5

.data
data:
    .word 0x12345678
    .word 0xABCDABCD
    .word 0x01010101
