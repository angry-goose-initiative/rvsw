/**
 * @file    illegal_instruction_experiments.c
 * @brief   Create illegal instruction exceptions for development of emulated instructions in ogsbi.
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
#include <stdint.h>

/* ------------------------------------------------------------------------------------------------
 * Function Implementations
 * --------------------------------------------------------------------------------------------- */

int main(void) {
    puts("Trying an unsigned divide");
    uint32_t a = 100;
    uint32_t b = 10;
    uint32_t c = a / b;
    char str[50];
    sprintf("the result of the division in smode is %lu", c);
    puts(str);
    return 0;
}
