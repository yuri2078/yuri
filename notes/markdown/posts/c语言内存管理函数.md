---
title: c语言内存管理函数
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: c语言
comments: true
description: 我的爱宛如孤岛之花，不为人知的绽放，不为人知的凋零！
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/7.png'
date: 2021-12-20 20:04:01.96
updated: 2021-12-23 20:02:16.216
tags:
    - c/c++
keywords:
---


以下函数均包含在stdlib.h头文件中

void *malloc()  
    1. 向系统申请 个字节的空间，并返回指向该空间的指针
    2. 返回的是void空指针，需要转换类型使用。无初值
    3. 返回失败返回NULL。

void free(指针)             释放我们申请的空间。它没有返回值

因为返回的地址是void类型，所以我们需要强制类型转换

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    int main(void)
    {
        int *p;
        //定义整形指针
        p = (int *)malloc(sizeof(int));
        //分配int字节的空间并把地址返回给p
        if (p == NULL)
        {
            printf("分配失败 ! ");
            //分配失败就终止程序
            exit(1);
        }
        printf("请输入一个数: ");
        scanf("%d", p);
        printf("我们输入的数是 %d \n", *p);
        free(p);
        //释放我们申请的空间
        return 0;
    }
    ```
内存泄漏问题 很危险就对了

分配一个数组

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    int main(void)
    {
        int *p = NULL;
        p = (int *)malloc(8 * sizeof(int));
        for (int i = 0; i < 8;i++)
        {
            scanf("%d", p + i);
            printf("%d  ", *(p + i));
        }
        free(p);
        return 0;
    }

    ```
memset(p, 0, size);  //包含于string.h  中
将p指向的size大小的空间初始化为0

calloc(number,size);
申请number * size个空间并把他们初始化为0

memcpy(p1,p2,n);  将n个数据从p2中拷贝到p1中
