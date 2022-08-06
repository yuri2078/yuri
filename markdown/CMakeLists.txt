cmake_minimum_required(VERSION 3.5) #设置最低版本
project(TEST cpp) #定义工程名字 支持语言
include_directories(/usr/include/) #向工程添加多个特定的头文件搜索 相当于c++ 的-i参数
set(SRC hello.cpp main.cpp) #显式的定义变量
link_directories() #添加多个特定的库文件搜索
add_library(hello SHARED ${SRC}) #生成库文件
add_compile_options(-Wall -std=c++17 -o2) #添加编译参数
add_executable(main main.cpp) #编译main.cpp 生成可执行文件main
target_link_libraries(main hello) #为他添加需要连接的共享库 相当于-L
add_subdirectory(SRC) #向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置
aux_source_directory(. src)#发现一个目录下所有的源代码文件并将列表存储在一个变量中
set(CMAKE_BUILD_TYPE Debug) #设置构造类型