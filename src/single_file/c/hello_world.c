/**
 * @file    hello_world.c
 * @brief   Prints "Hello World!" and exits.
 * 
 * @copyright
 *  Copyright (C) 2023-2024 John Jekel\n
 *  See the LICENSE file at the root of the project for licensing info.
*/

/* ------------------------------------------------------------------------------------------------
 * Includes
 * --------------------------------------------------------------------------------------------- */

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* ------------------------------------------------------------------------------------------------
 * Function Implementations
 * --------------------------------------------------------------------------------------------- */

int main(void) {
    puts("Trying an illegal exception");
    int i=0;
    __asm__ volatile (\
    "li t0, 100\n \
     li t1, 10\n \
     divu t2, t0, t1");
    return i;
}
