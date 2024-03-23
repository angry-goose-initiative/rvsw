/**
 * @file    illegal_instruction_experiments.c
 * @brief   Create illegal instruction exceptions for development of emulated instructions in ogsbi.
 * 
 * @copyright
 *  Copyright (C) 2024 Eric Jessee\n
 *  See the LICENSE file at the root of the project for licensing info.
*/

/* ------------------------------------------------------------------------------------------------
 * Includes
 * --------------------------------------------------------------------------------------------- */

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

/* ------------------------------------------------------------------------------------------------
 * Function Implementations
 * --------------------------------------------------------------------------------------------- */

int main(void) {
    volatile uint32_t a = 10;
    volatile uint32_t b = -100;
    volatile uint32_t c;
    puts("forcing a mulh instruction");
    __asm__ volatile (
        "mulh %[dest], %[left_op], %[right_op]"
        : [dest] "=r" (c)
        : [left_op] "r" (a), [right_op] "r" (b)
        : /* No additional clobbered registers */
    );
    assert(c == 0xFFFFFFFF && "result should be -1");
    puts("forcing a mulhu instruction");
    a = 0x80000000;
    b = 10;
    __asm__ volatile (
        "mulhu %[dest], %[left_op], %[right_op]"
        : [dest] "=r" (c)
        : [left_op] "r" (a), [right_op] "r" (b)
        : /* No additional clobbered registers */
    );
    assert(c == 5 && "result should be 5");
    puts("forcing a mulhsu instruction");
    a = -16;
    b = 0x80000000;
    __asm__ volatile (
        "mulhsu %[dest], %[left_op], %[right_op]"
        : [dest] "=r" (c)
        : [left_op] "r" (a), [right_op] "r" (b)
        : /* No additional clobbered registers */
    );
    assert(c == 0xfffffff8 && "result should be -8");
    puts("Trying an unsigned divide (udiv)");
    a = 100;
    b = 10;
    c = a / b;
    char str[100];
    assert(c == 10 && "result should be 10");
    sprintf(str, "the result of the division in smode is %lu", c);
    puts(str);
    puts("trying a signed divide (div)");
    volatile int d = 100;
    volatile int e = -10;
    volatile int f = d / e;
    assert(f == -10 && "result should be -10");
    sprintf(str, "the result of the signed division in smode is %d", f);
    puts(str);
    puts("trying an unsigned modulo (remu)");
    a = 7;
    b = 5;
    c = a % b;
    assert(c == 2 && "result should be 2");   
    sprintf(str, "the result of the modulo in smode is %lu", c);
    puts(str);
    puts("trying a signed modulo (rem)");
    d = -7;
    e = 5;
    f = d % e;    
    assert(f == -2 && "result should be -2");   
    sprintf(str, "the result of the signed modulo in smode is %d", f);
    puts(str);
    puts("trying a signed multiply");
    d = 3;
    e = -6;
    f = d*e;
    assert(f == -18 && "result should be -18");   
    sprintf(str, "the result of the signed multiply in smode is %d", f);
    puts(str);
    puts("trying an unsigned 64-bit multiply"); //why does this emit a billion instructions?
    //this should emit mul and mulhu
    volatile uint64_t g = 0x10000002;
    volatile uint64_t h = 0x1002;
    volatile uint64_t i = g*h; //should be 0x10020002004
    assert(i == 0x10020002004 && "result should be 0x10020002004");
    sprintf(str, "the result of the unsigned 64-bit multiply in smode is 0x%llx", i);
    puts(str);
    puts("trying signed division with overflow");
    d = 0x80000000;
    e = -1;
    f = d / e;
    assert (f == d && "overflow should be handled according to spec");
    puts("trying signed remainder with overflow");
    d = 0x80000000;
    e = -1;
    f = d % e;
    assert (f == 0 && "overflow should be handled according to spec");
    return 0;
}
