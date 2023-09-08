cmake_minimum_required(VERSION 3.20)
project(learn)

set(CMAKE_CXX_STANDARD 20)
set(SRC_FILES ${CMAKE_SOURCE_DIR}/src)

set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib/") 

find_package( OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(tool SHARED ${SRC_FILES}/tool.cc)

add_executable(hello hello.cpp)
add_executable(cvt cvt.cc)
add_executable(main main.cc)

target_link_libraries(hello ${OpenCV_LIBS})

target_link_libraries(cvt ${OpenCV_LIBS} tool)
target_link_libraries(main ${OpenCV_LIBS} tool)