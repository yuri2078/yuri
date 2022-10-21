cmake_minimum_required(VERSION 3.0)
project(test_1 C)

set(CMAKE_C_STANDARD 17)

add_executable(test_1 main.c mytool.c mytool.h)
