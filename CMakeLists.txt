cmake_minimum_required(VERSION 3.27)
project(20240531 C)

set(CMAKE_C_STANDARD 11)

add_executable(20240531 main.c
        lru.c
        lru.h
)
