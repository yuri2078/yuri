cmake_minimum_required(VERSION 3.20)

project(yuri)

link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(main main.cpp)

target_link_libraries(main person_2)
