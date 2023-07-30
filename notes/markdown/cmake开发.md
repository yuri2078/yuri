# camek开发

## g++ 指令

1. 新建cpp文件 vi main.cpp

2. 编译过程

    + 预处理 -E 对文件进行预处理 比如头文件包含 `g++ -E main.cpp -o test.i`

    + 编译 -S 在产生汇编代码后停止编译 默认后缀s `g++ -S main.i -o main.s`

    + 汇编 -C 仅把源代码编译成机器语言的目标代码 `g++ -C main.s -o main.o`

    + 连接 -O 将产生的可执行文件指定文件名 `g++ -o main.o -o main`

3. g++重要的编译参数

    + -g 编译带条是信息的可执行文件
    + -O【n】 优化代码默认 -O1
    + -lglog 指定库文件 默认搜索 /lib/usr/lib /lib/local/lib -L 直接指定库文件路径
    + -I 指定头文件搜索目录
    + -Wall 打印警告信息
    + -w 关闭警告信息
    + -std=c++11 指定编译标准
    + -D宏定义
    + -o 指定输出文件名

4. 实战演练

    ```cpp
        //目录文件
        //main.cpp include src
        //include Person.h
        //src Person.cpp
    ```

    `g++ main.cpp src/Person.cpp -Iinclude`
    
5. 生成库文件

    + 生成静态库文件

        1. cd src

        2. `g++ -c Person.cpp -I../include -o Person.o 生成.o文件`

        3. cd ..

        4. ar rs libPerson.a Person.o 添加静态库

    + 生成动态库文件

        1. cd src

        2. `g++ Person.cpp -I../include -fPIC -shared -o libPerson.so`

        3. f

    

## gdb调试

> 编译时需要加 -g

+ 常用命令

    1. help run 帮助命令

    2. run(r) 重新开始运行文件

    3. start 单步执行

    4. list(l) 查看源代码

    5. next(n) 单步调试 跳过函数

    6. set 设置变量的值

    7. step(s) 单步执行 不跳过函数

    8. backtrace(bt) 查看函数的条用栈帧和层级关系

    9. frame(f) 切换函数栈帧

    10. info(i) 查看函数内部变量的数值

    11. finish 结束当前函数回到函数调用点

    12. continue(c) 继续运行

    13. print(p) 打印值及地址

    14. quit(q) 推出gdb
+ 开始
    1. break+num(b) 设置断点

    2. info breakpints 查看所有断点

    3. delete breakpoints num(d) 删除断点

    4. display 追踪查看具体变量值

    5. undisplay 取消追踪

    6. watch 被设置的观察点发生改变则打印值

    7. i watch 显示观察点

    8. enable breakpoints启用断点

    9. disable breadpoints禁用断点

    10. x 查看内存

    11. run argv[1] agrv[2]调用命令传参

    12. set follow-fork-mode child#Makefile项目管理

    13. 回车是上一部指令
+ 实例测试

    0. -g编译main
1. gbd main
    2. break  7在第七行设置断点
3. info break 查看断点

## 多文件

文件目录

```bash
.
├── CMakeLists.txt
├── include
│   ├── person.h
├── main.cpp
└── src
    └── person.cpp
```

CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.20)
project(Main)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #开启生成compile_commands.json
set(CMAKE_CXX_STANDARD 20) # 设置c++ 版本

# 使用file查找
file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

include_directories(${PROJECT_SOURCE_DIR}/include) # 添加头文件查找目录
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

add_executable(main main.cpp ${SRC_LIST})
add_executable(main_2 main.cpp ${MAIN_SRC} ${MAIN_HEAD})
```

## 链接

> 动态链接是在程序执行时查找对应的链接库，他不会将所有链接文件放入可执行文件中。
>
> 而静态链接是将所有链接库放入可执行文件中。所以静态链接占用较大，但是他不依赖外部链接。
>
> 动态链接占用较小只要接口不变，就可以不用重新打包。而静态链接需要重新打包。

### 动态链接动

1. 将需要使用的cpp文件生成静态链接库

   ```cmake
   add_library(person SHARED person.cpp)
   ```

2. 将生成的`libperson_2.so` 复制到新工程的`lib` 目录下 将头文件也拷贝过来

   ```
   .
   ├── CMakeLists.txt
   ├── include
   │   └── person.h
   ├── lib
   │   └── libperson_2.so
   └── main.cpp
   ```

3. cmake引用静态链接库

   ```cmake
   link_directories(${PROJECT_SOURCE_DIR}/lib) # 添加检索目录
   
   add_executable(main main.cpp) # 生成可执行文件
   
   target_link_libraries(main person_2) # 链接库文件
   # 因为动态链接是需要的时候再找所以 放在生成文件的后面
   ```

4. `main.cpp` 直接引用就行

### 静态链接库

1. 将需要使用的cpp文件生成静态链接库

   ```cmake
   add_library(person STATIC person.cpp)
   ```

2. 将生成的`libperson.a` 复制到新工程的`lib` 目录下 将头文件也拷贝过来

   ```
   ├── CMakeLists.txt
   ├── include
   │   └── person.h
   ├── lib
   │   └── libperson.a
   └── main.cpp
   ```

3. cmake引用静态链接库

   ```cmake
   link_directories(${PROJECT_SOURCE_DIR}/lib) # 添加静态库目录
   link_libraries(person) # 链接静态库
   ```

4. `main.cpp` 直接引用就行

## CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.5) 
#设置最低版本

project(TEST cpp) 
#定义工程名字 支持语言

include_directories(/usr/include/) 
#向工程添加多个特定的头文件搜索 相当于c++ 的-i参数

set(SRC hello.cpp main.cpp) 
#显式的定义变量

link_directories() 
#添加多个特定的库文件搜索

add_library(hello SHARED ${SRC}) 
#生成库文件

add_compile_options(-Wall -std=c++17 -o2) 
#添加编译参数

add_executable(main main.cpp) 
#编译main.cpp生成可执行文件main

target_link_libraries(main hello) 
#为他添加需要连接的共享库 相当于-L

add_subdirectory(SRC) 
#向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置

aux_source_directory(. src)
#发现一个目录下所有的源代码文件并将列表存储在一个变量中

set(CMAKE_BUILD_TYPE Debug) 
#设置构造类型

add_definitions(-Wall -g) 
#添加编译选项

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 开启免疫compile commands 文件

set(CMAKE_CXX_STANDARD 20)
# 设置c++标准

# 查找文件 CMAKE_CURRENT_SOURCE_DIR 表示当前cmakelist 文件
file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

# PROJECT_SOURCE_DIR 表示当前项目目录
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

# 添加可z
add_executable(main main.cpp ${SRC_LIST})
add_executable(test main.cpp ${MAIN_SRC} ${MAIN_HEAD})
```

