# 基于vscode 和camek的c++开发

## 开发环境搭建

1. ubantu 22.04

2. sudo apt update 先更新

3. 安装gcc sudo apt install gcc

4. 安装g++ sudo apt install g++

5. 安装gdb sudo apt install build-essential gdb

6. 安装cmake sudo apt install cmake

7. 查看版本 gcc --version

## 开始编译

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

6. gdb调试器 编译时需要加 -g

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

        4. 
