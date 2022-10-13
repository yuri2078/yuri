---
title: c语言链表
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: c语言
comments: true
description: 我的爱宛如孤岛之花，不为人知的绽放，不为人知的凋零！
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/6.png'
date: 2021-12-20 18:32:01.587
updated: 2021-12-23 20:01:39.846
tags:
    - c/c++
keywords:
---

## 单链表

组成：   |信息域|指针域|    单链表一般由 信息域 和 指针域 构成

链表的增加 删除

链表练习题 均使用头插法

1 制作同学数据录入表

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    struct Name
    {
        int age;
        char name[80];
        struct Name *next;
    };
    //定义结构体
    void show(struct Name *p)
    {
        while (p)
        {
            printf("该同学是:%-15s 今年   %-3d  岁 \n", p->name, p->age);
            p = p->next;
        }
    }
    //定义输出函数
    struct Name *add(struct Name *head)
    {
        char name[80];
        int age;
        struct Name *p = head;
        printf("请输入需要添加的同学姓名 年龄: ");
        scanf("%s%d", name, &age);
        if (head == NULL)
        {
            head = (struct Name *)malloc(sizeof(struct Name));
            strcpy(head->name, name);
            head->age = age;
            return head;
        }
        else
        {
            while (head->next != NULL)
            {
                head = head->next;
            }
            head->next = (struct Name *)malloc(sizeof(struct Name));
            strcpy(head->next->name, name);
            head->next->age = age;
        }
        return p;
    }
    //定义添加成员函数
    struct Name *del(struct Name *head)
    {
        struct Name *p = head, *t = NULL;
        char s[80];
        printf("请输入你想要删除的同学的名字");
        scanf("%s", s);
        while (p != NULL)
        {
            if (strcmp(p->name, s) == 0)
            {
                break;
            }
            t = p;
            p = p->next;
        }
        if (t == NULL)
        {
            t = head;
            free(t);
            head = head->next;
        }
        else
        {
            t->next = p->next;
            free(p);
        }
        return head;
    }
    //定义删除成员函数
    void relass(struct Name *p)
    {
        struct Name *t = p;
        while (p)
        {
            free(t);
            p = p->next;
            t = p;
        }
    }
    //定义释放内存呢函数
    int main(void)
    {
        struct Name *head = NULL;
        int x;
        printf("欢饮来到同学信息录入删除系统--------版本2.0\n");
        printf("请按照序号选择操作\n");
        while(1)
        {
            printf(" 1 添加n个同学\n 2 删除一个同学 \n 3 查看当然数据库\n 4 打印成员并且退出系统\n\n请输入数据:");
            scanf("%d", &x);
            switch(x)
            {
                case 1 : {
                    head = add(head);
                    break;
                }
                case 2 : {
                    head = del(head);
                    break;
                }
                case 3 : {
                    show(head);
                    break;
                }
                case 4 : {
                    show(head);
                    relass(head);
                    return 0;
                }
            }
        }
    }

    ```
2  多项式相加

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    typedef struct Node
    {
        int coef;  //系数
        int expn;  //指数
        struct Node *next;
    }Node;

    Node* create()
    {
            Node *head=NULL,*p=NULL;
            int x,i;
            scanf("%d",&x);
            for(i=0;i<x/2;i++) 
            {
                if(head == NULL)
                {
                    head=(Node *)malloc(sizeof(Node));
                    scanf("%d%d",&head->coef,&head->expn);
                    p=head;
                }
                else
                {
                    p->next=(Node *)malloc(sizeof(Node));
                    p=p->next;
                    scanf("%d%d",&p->coef,&p->expn);
                }
            } 
            p->next = NULL;
            return head; 
    }
    Node* add(Node *a,Node *b)
    {
        Node *t=NULL,*p;
        if(a->expn < b->expn)
        {
            t = a;
            a = b;
            b = t;
        }
        p = a;
        while(a != NULL && b != NULL)
        {
            while((a !=NULL) && (a->expn == b->expn))
            {
                t = a;
                a = a->next;
            }
            if(a != NULL)
            {
                if(a->expn == b->expn)
                {
                    a->coef += b->coef;
                    b = b->next;
                }
                else
                {
                    t->next = (Node *)malloc(sizeof(Node));
                    t = t->next;
                    t->coef = b->coef;
                    t->expn = b->expn;
                    t->next = a;
                }
            }
        }
        if(b != NULL)
            t->next = b;
        return p;
    }
    void print(Node *head)
    {
        while(head != NULL)
        {
            printf("%d %d ",head->coef,head->expn);
            head=head->next;
        }
    }

    int main()
    {
        Node *a,*b,*c;
        a = create();
        b = create();
        c = add(a,b);
        print(c);
        return 0;
    }

    ```
