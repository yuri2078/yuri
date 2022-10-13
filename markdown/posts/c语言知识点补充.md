---
title: c语言知识点补充
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: c语言
comments: true
description: 我的爱宛如孤岛之花，不为人知的绽放，不为人知的凋零！
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/8.png'
date: 2021-12-14 14:34:01.293
updated: 2021-12-23 20:03:45.787
tags:
    - c/c++
keywords:
---


## scanf 输入是 用 %*d 会吞掉一个输入

    ```c
    #include<stdio.h>
    int main()
    {
        int x, y;
        scanf("%d %*d %d", &x, &y);
        //输入11 22 33 
        printf("x = %d y = %d \n",x,y);
        //打印结果是 x = 11 y = 33 中间输入的22被吞掉
        return 0;
    } 
    ```

## print 输出时 %09d 前面不足9位的时候会用0补充

    ```c
    #include<stdio.h>
    int main()
    {
        int x = 666;
        printf("%09d", x);
        //打印结果000000666
        return 0;
    } 
    ```
而用-09d则会提示错误

## 用scanf接收数据的时候可以指定接收的长度，浮点数也可以指定长度，但是不能指定小数点 如 %6.2f这种就是错误的用法

    ```c
    #include<stdio.h>
    int main()
    {
        float x, y;
        scanf("%6f%f", &x, &y);
        //输入 ： 3.123456 2.5
        printf("x = %f y = %f \n", x, y);
        //打印结果 x = 3.123400 y = 56.000000
        return 0;
    } 

    ```
指定输入长度后，未获取的数据会给下一个变量

高级宏定义

宏定义只定义不进行运算
    1. 不带参数 #define PI 3.14
    2. 带参数的

    ```c
    #include<stdio.h>
    #define SUM(x,y) x+y
    int main()
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("sum(x,y) = %d \n", SUM(x, y));
        //用x+y替换SUN(x,y)
        return 0;
    } 

    ```
tip: 在某些场景可以用宏定义替代函数，可以提高效率

内联函数
形如 以下程序 打印1-30的平方

    ```c
    #include<stdio.h>
    int main()
    {
        int pingFang(int x);
        for (int i = 1; i < 30;i++)
        {
            printf("%d 的平方是: %d \n", i, pingFang(i));
        }
        return 0;
    } 
    int pingFang(int x)
    {
        return x * x;
    }
    ```
这里函数需要重估的调用，但是因为c语言函数调用是借助于堆栈的这样会严重影响运行效率。  所以我们可以使用内联函数。相当于宏定义，在编译的时候用函数的内容替代函数名，从而实现提高效率，减少开支

方法 ： 在函数名前加 `inline`

    ```c
    #include<stdio.h>
    inline int pingFang(int x);
    //在函数名前添加inline 
    //需要在main前声明
    int main()
    {
        for (int i = 1; i < 30;i++)
        {
            printf("%d 的平方是: %d \n", i, pingFang(i));
        }
        return 0;
    } 
    int pingFang(int x)
    {
        return x * x;
    }
    ```

## 加号链接运算符,记号黏贴运算符

形如 #define STR(s) #s 将输入的数据转换成字符串
形如 #define TOGETHER(x,y) x ## y 连接x和y

    ```c
    #include <stdio.h>
    #define TOGETHER(x,y) x ## y
    //连接x和y
    int main(void)
    {
        printf(" TOGETHER = %d ",TOGETHER(2,50));
        return 0;
    }
    //输出250
    ```
可变参数

形如 #define PRINTF(...) printf(# __VA_ARGS__)

    ```c
    #include <stdio.h>
    #define PRINTF(...) printf(# __VA_ARGS__)
    //
    //...表示需要传入参数，va-args-- 固定写法，表示接收任何的参数
    //# 表示将参数转化成字符串
    int main(void)
    {
        PRINTF(hello python);
        //成功打印hello python
        return 0;
    }
    ```

可变参数支持空参数

    ```c
    #include <stdio.h>
    #define PRINTF(str,...) printf(# str,## __VA_ARGS__)
    //将hello python 传入给str ，...为空参数
    int main(void)
    {
        PRINTF(hello python);
        //成功打印hello python
        return 0;
    }

    ```

\b   //使光标回退一格 需要后面跟着替换的字符不然既不会回退

    ```c
    #include <stdio.h>
    int main(void)
    {
        printf("hello python*\b \n");
        // \b后面有替换的空格 打印结果hello python
        printf("hello*\b");
        // \b后没有替换的空格 打印结果hello*
        return 0;
    }

    ```

\r   //使光标回退到开头
注意 只是回退，本质上并不是清除。往下如果不完全覆盖，还是可以打印出来的

    ```c
    #include <stdio.h>
    int main(void)
    {
        printf("hello python 我是多的数据");
        printf("\r");
        //使光标移动到开头
        printf("hello java c ");
        //重新打印比刚才多的数据
        //打印结果 hello java c 我是多的数据
        return 0;
    }
    ```
