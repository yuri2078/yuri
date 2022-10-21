//
// Created by yuri on 22-10-21.
//

#ifndef MYTOOL_H
#define MYTOOL_H

#include <stdlib.h>

typedef int ElemType;

//队列
typedef struct Queue {
    ElemType* base;
    int rear, front, maxSize;
} Queue;

//堆栈
typedef struct SqStack{
    ElemType* base;
    ElemType* top;
    int maxSize;
} SqStack;

//初始化堆栈
int initSqStack(SqStack* sq);

//入栈函数，返回是否入栈成功
int pushSqStack(SqStack* sq, ElemType e);

//出栈指针，返回是否出堆成功
int popSqStack(SqStack* sq, ElemType *e);

//获取栈顶数据
int getTop(SqStack* sq, ElemType *e);

//当栈底指针等于栈顶指针时，堆栈为空
int isSqStackEmpty(SqStack* sq);



//初始队列
int initQueue(Queue *q);

//入队函数,返回是否入队成功
int enQueue(Queue* q, ElemType e);

//出对函数，返回是否出对成功
int deQueue(Queue* q, ElemType *e);

//判断队是否为空
int isQueueEmpty(Queue* q);



#endif //MYTOOL_H
