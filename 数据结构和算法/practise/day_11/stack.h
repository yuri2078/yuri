//
// Created by yuri on 22-11-17.
//

#ifndef DAY_11_STACK_H
#define DAY_11_STACK_H

#include <stdlib.h>


typedef struct Tree {
    char val;
    struct Tree* left;
    struct Tree* right;
} Tree;

typedef Tree * ElemType;
typedef struct SqStack{
    ElemType* base;
    ElemType* top;
    int maxSize;
} SqStack;

int initSqStack(SqStack* sq);

//初始化堆栈
int initSqStack(SqStack* sq) {
    sq->base = (ElemType *)calloc(20, sizeof(ElemType)); //设置初始容量为20
    if (!sq->base) {
        return 0;
    }
    sq->top = sq->base; //设置堆栈顶部指针
    sq->maxSize = 20; //设置最大容量
    return 1;
}

//入栈函数，返回是否入栈成功
int pushSqStack(SqStack* sq, ElemType e) {
    if (sq->top - sq->base == sq->maxSize) {
        sq->base = (ElemType *)realloc(sq->base, (sq->maxSize + 10) * sizeof(ElemType));
        sq->top = sq->base + sq->maxSize;
        sq->maxSize += 10; //最大元素个数自动加10
    }
    if (!sq->base) {
        sq->maxSize = 0;
        return 0;
    }

    *sq->top = e; //赋值给栈顶
    sq->top++; //栈顶指针加1
    return 1;
}

//出栈指针，返回弹出的数据
ElemType popSqStack(SqStack* sq) {
    if (sq->top != sq->base) { 
        return *(--sq->top); //如果不是空栈就返回栈顶值
    }
    return 0;
}

//当栈底指针等于栈顶指针时，堆栈为空
int isEmpty(SqStack* sq) {
    if (sq->base == sq->top) {
        return 1;
    }
    return 0;
}


#endif //DAY_11_STACK_H
