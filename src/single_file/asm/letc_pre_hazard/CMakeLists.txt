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
    target_include_directories(src__single_file__asm__letc_pre_hazard__${NAME} PRIVATE ${PROJECT_BINARY_DIR}/include)#To get the generated rvsw_asm.h
endmacro()

#Assembly test files from jzjcoresoftware
macro(add_letc_pre_hazard_asm_target NAME)
    add_asm_target(${NAME} ${CMAKE_CURRENT_SOURCE_DIR}/${NAME}.S)
endmacro()

add_letc_pre_hazard_asm_target(dependency_problem_0)
add_letc_pre_hazard_asm_target(first_branch_test)
add_letc_pre_hazard_asm_target(forwarding_sweep)
add_letc_pre_hazard_asm_target(increment)
add_letc_pre_hazard_asm_target(jumping_around)
add_letc_pre_hazard_asm_target(store_to_load)
add_letc_pre_hazard_asm_target(store_to_load_aftermath)
add_letc_pre_hazard_asm_target(use_after_load)
add_letc_pre_hazard_asm_target(all_loads)

#TODO others
