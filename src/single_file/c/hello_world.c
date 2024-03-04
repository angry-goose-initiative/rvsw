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
    "li a4, 100\n \
     li a5, 10\n \
     div a4, a5, a4");
    return i;
}
