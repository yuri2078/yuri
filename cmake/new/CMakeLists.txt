cmake_minimum_required(VERSION 3.20)

project(Main)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)

#file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
#file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

#include_directories(${PROJECT_SOURCE_DIR}/include)
# 搜索 src 目录下的源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

#add_executable(main main.cpp ${SRC_LIST})
#add_executable(test main.cpp ${MAIN_SRC} ${MAIN_HEAD})

add_library(person STATIC ${SRC_LIST})
add_library(person_2 SHARED ${SRC_LIST})
