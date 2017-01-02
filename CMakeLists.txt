cmake_minimum_required(VERSION 3.6)
project(stime)

set(CMAKE_C_COMPILER m68k-atari-mint-gcc)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c main.h)
add_executable(stime.prg ${SOURCE_FILES})

target_link_libraries(stime.prg gem)
