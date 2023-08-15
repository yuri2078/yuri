cmake_minimum_required(VERSION 3.2)

project(SOLIDER)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_BUILD_TYPE Debug)

add_executable(main main.cpp src/Solider.cpp src/Gun.cpp)

# set(SRC src/Solider.cpp src/Gun.cpp)

# # aux_source_directory(./src SRC)#发现一个目录下所有的源代码文件并将列表存储在一个变量中

# add_executable(main )