cmake_minimum_required(VERSION 3.20)

project(yuri)

link_directories(${PROJECT_SOURCE_DIR}/lib)
link_libraries(person)

add_executable(main main.cpp)
