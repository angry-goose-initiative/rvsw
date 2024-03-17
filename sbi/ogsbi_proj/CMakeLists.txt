cmake_minimum_required(VERSION 3.16.3)
project(sbi__ogsbi VERSION 0.0.0 LANGUAGES CXX C ASM)

set(CMAKE_C_COMPILER riscv32-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER riscv32-unknown-elf-gcc)
set(OBJCOPY riscv32-unknown-elf-objcopy)

include("irve_rvsw_config.cmake")

set(IRVE_RVSW_NEWLIB_SYSCALLS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/irve_mmode_newlib.c
    ${CMAKE_CURRENT_SOURCE_DIR}/irve_mmode.h
)
add_library(irve_rvsw_newlib_syscalls OBJECT ${IRVE_RVSW_NEWLIB_SYSCALLS_SOURCES})

#Add options specified by other RVSW config options to the build command line
set(RVSW_MMODE_COMMON_FLAGS "${RVSW_MMODE_COMMON_FLAGS} -march=${RVSW_MARCH} -mabi=${RVSW_MABI} -T ${RVSW_MMODE_LD_SCRIPT} -DRVSW_MMODE")
set(RVSW_SMODE_COMMON_FLAGS "${RVSW_SMODE_COMMON_FLAGS} -march=${RVSW_SMODE_MARCH} -mabi=${RVSW_SMODE_MABI} -T ${RVSW_SMODE_LD_SCRIPT} -DRVSW_SMODE")
string(REPLACE " " ";" RVSW_MMODE_COMMON_FLAGS "${RVSW_MMODE_COMMON_FLAGS}")#Convert to list
string(REPLACE " " ";" RVSW_SMODE_COMMON_FLAGS "${RVSW_SMODE_COMMON_FLAGS}")#Convert to list

set(CMAKE_ASM_FLAGS "${RVSW_COMMON_FLAGS}")
set(CMAKE_C_FLAGS "${RVSW_COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS "${RVSW_COMMON_FLAGS} -std=gnu++20 -fno-use-cxa-atexit")

add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(ogsbi)