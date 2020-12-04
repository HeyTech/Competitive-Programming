cmake_minimum_required(VERSION 3.17)

project(AoC2020)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE TASKS days/ *.h)

SET(COMMON
        common/common.h)

add_executable(AoC2020
        main.cpp
        ${COMMON}
        ${days})