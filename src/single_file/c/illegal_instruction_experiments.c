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
    puts("forcing a mulh instruction");
    __asm__ volatile (
        "li a7, -100\n"
        "li a6, 10\n"
        "mulh a5, a6, a7"
    );
    puts("forcing a mulhu instruction");
    __asm__ volatile (
        "li a7, 100\n"
        "li a6, 55\n"
        "mulhu a5, a6, a7"
    );
    puts("forcing a mulhsu instruction");
    __asm__ volatile (
        "li a7, -10\n"
        "li a6, 100\n"
        "mulhsu a5, a6, a7"
    );
    puts("Trying an unsigned divide (udiv)");
    uint32_t a = 100;
    uint32_t b = 10;
    uint32_t c = a / b;
    char str[100];
    sprintf(str, "the result of the division in smode is %lu", c);
    puts(str);
    puts("trying a signed divide (div)");
    int d = 100;
    int e = -10;
    int f = d / e;
    sprintf(str, "the result of the signed division in smode is %d", f);
    puts(str);
    puts("trying an unsigned modulo (remu)");
    a = 7;
    b = 5;
    c = a % b;
    sprintf(str, "the result of the modulo in smode is %lu", c);
    puts(str);
    puts("trying a signed modulo (rem)");
    d = -7;
    e = 5;
    f = d % e;
    sprintf(str, "the result of the signed modulo in smode is %d", f);
    puts(str);
    puts("trying a signed multiply");
    d = 3;
    e = -6;
    f = d*e;
    sprintf(str, "the result of the signed multiply in smode is %d", f);
    puts(str);
    puts("trying an unsigned 64-bit multiply"); //why does this emit a billion instructions?
    //this should emit mul and mulhu
    uint64_t g = 0x10000002;
    uint64_t h = 0x1002;
    uint64_t i = g*h; //should be 0x10020002004
    sprintf(str, "the result of the unsigned 64-bit multiply in smode is 0x%llx", i);
    puts(str);
    return 0;
}
