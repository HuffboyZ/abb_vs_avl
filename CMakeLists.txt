cmake_minimum_required(VERSION 3.10)
project(_abb_avl C)

set(CMAKE_C_STANDARD 99)

add_executable(_abb_avl main.c headers/abb.h headers/avl.h)