//
// Created by yuri on 22-10-21.
//

#include "mytool.h"

//堆栈


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
        sq->base = realloc(sq->base, (sq->maxSize + 10) * sizeof(ElemType));
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

//出栈函数
int popSqStack(SqStack* sq, ElemType *e) {
    if (sq->top != sq->base) {
        *e =  *(--sq->top); //如果不是空栈就存储数据
        return  1;
    }

    return 0;
}

int getTop(SqStack* sq, ElemType *e)
{
    if(isSqStackEmpty(sq)){
        return 0;
    }
    *e = *(sq->top - 1);
    return 1;
}

//当栈底指针等于栈顶指针时，堆栈为空
int isSqStackEmpty(SqStack* sq) {
    if (sq->base == sq->top) {
        return 1;
    }
    return 0;
}

//队列

//初始队列
int initQueue(Queue *q) {
    q->base = (ElemType*)calloc(20, sizeof(ElemType));
    if (!q->base) {
        return 0;
    }
    q->rear = 0; //设置将要存储的位置
    q->front = 0; //设置出列的位置
    q->maxSize = 20; //设置最大容量
    return 1;
}


//入队
int enQueue(Queue* q, ElemType e) {
    if ((q->rear + 1) % q->maxSize == q->front) {
        q->base =realloc(q->base,(q->maxSize + 10) * sizeof(ElemType));
        if(!q->base){
        }

        q->maxSize += 10; //更改最大存储容量
    }
    q->base[(q->rear++) % q->maxSize] = e; //将数据存放进去，并且位置 + 1
    return 1;
}

//出队
int deQueue(Queue* q, ElemType *e) {
    if (q->front == q->rear) {
        return 0;
    }
    *e =  q->base[(q->front++) % q->maxSize];
    return 1;
}

int isQueueEmpty(Queue* q) {
    //当即将出列的位置等于即将插入的位置的时候 表示队列为空
    if (q->rear == q->front) {
        return 1;
    }
    return 0;
}
