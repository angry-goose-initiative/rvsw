#include "asm_c_interface.h"
#include "common.h"
#include "soft_exceptions.h"

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

void soft_exception_handler(){
    dputs("entered the soft exception handler\n");
    //exit(1);
}