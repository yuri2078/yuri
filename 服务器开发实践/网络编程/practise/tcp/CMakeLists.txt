cmake_minimum_required(VERSION 3.20)

project(tcp_server)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(client client.cpp)
add_executable(server server.cpp)
