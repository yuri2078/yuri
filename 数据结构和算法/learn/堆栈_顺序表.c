#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct SqStack{
    ElemType* base;
    ElemType* top;
    int maxSize;
} SqStack;

//初始化堆栈
int initSqStack(SqStack* sq) {
    sq->base = (ElemType *)calloc(20, sizeof(ElemType)); //设置初始容量为20
    if (!sq->base) {
        printf("初始化失败捏\n");
        return 0; 
    }
    sq->top = sq->base; //设置堆栈顶部指针
    sq->maxSize = 20; //设置最大容量
    return 1;
}

//入栈函数，返回是否入栈成功
int pushSqStack(SqStack* sq, ElemType e) {
    if (sq->top - sq->base == sq->maxSize) {
        printf("容量不足已经自动扩容，扩容为10\n");
	    sq->base = realloc(sq->base, (sq->maxSize + 10) * sizeof(ElemType));
	    sq->top = sq->base + sq->maxSize;
	    sq->maxSize += 10; //最大元素个数自动加10
    }
    if (!sq->base) {
        printf("扩容失败捏！\n");
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
    printf("没有东西，返回错误!\n");
    return 0;
}

//当栈底指针等于栈顶指针时，堆栈为空
int isEmpty(SqStack* sq) {
    if (sq->base == sq->top) {
        return 1;
    }
    return 0;
}

int main(void) {
    SqStack* sq = (SqStack*)malloc(sizeof(SqStack));
    initSqStack(sq); //初始化堆栈
    for (int i=0; i<40; i++) {
        pushSqStack(sq,i); //入栈元素
    }

    while (!isEmpty(sq)) {
        printf("%d ",popSqStack(sq)); //不断出栈，并且打印出栈的元素
    }
    printf("\n");

    free(sq); //释放申请的内存
    return 0;
}