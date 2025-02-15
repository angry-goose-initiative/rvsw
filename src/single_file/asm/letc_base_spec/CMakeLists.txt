# CMakeLists.txt
# Copyright (C) 2023-2025 John Jekel
# See the LICENSE file at the root of the project for licensing info.
#
# CMake configuration file for LETC tests pre-harzard-detection
#
# Based on testfiles/CMakeLists.txt from irve
#

#Common options
cmake_minimum_required(VERSION 3.16.3)

include(${PROJECT_SOURCE_DIR}/macros.cmake)

macro(add_asm_target NAME)
    add_target(${NAME} ${ARGN})
    target_include_directories(src__single_file__asm__letc_base_spec__${NAME} PRIVATE ${PROJECT_BINARY_DIR}/include)#To get the generated rvsw_asm.h
endmacro()

#Assembly test files from jzjcoresoftware
macro(add_letc_base_spec_asm_target NAME)
    add_asm_target(${NAME} ${CMAKE_CURRENT_SOURCE_DIR}/${NAME}.S)
endmacro()

add_letc_base_spec_asm_target(first_loads)
add_letc_base_spec_asm_target(lb)
add_letc_base_spec_asm_target(lh)
add_letc_base_spec_asm_target(lw)

#TODO others
