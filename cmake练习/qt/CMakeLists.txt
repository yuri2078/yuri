cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

project(yuri)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(yuri main.cpp)
target_link_libraries(yuri PRIVATE Qt6::Widgets)
