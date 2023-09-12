cmake_minimum_required(VERSION 3.20)

project(ftp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

add_executable(server server.cpp ${SRC_LIST})
add_executable(client client.cpp ${SRC_LIST})
