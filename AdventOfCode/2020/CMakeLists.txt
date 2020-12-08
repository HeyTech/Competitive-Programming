cmake_minimum_required(VERSION 3.17)

project(AoC2020)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE TASKS days/*.h)

SET(COMMON
        aoc/aoc.h
        aoc/aoc_string.h
        aoc/read_input.h
        aoc/checks.h)

add_executable(AoC2020
        main.cpp
        ${COMMON}
        ${days})