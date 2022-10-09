#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Queue {
    ElemType* baze;
    int real, front, maxSize;
} Queue;

//这是顺序表循环队列,并且是可以扩容的

//初始队列
int initQueue(Queue *q) {
    q->baze = (ElemType*)calloc(20, sizeof(ElemType));
    if (!q->baze) {
        return 0;
    }
    q->real = 0; //设置将要存储的位置
    q->front = 0; //设置出列的位置
    q->maxSize = 20; //设置最大容量
    return 1;
}

int enQueue(Queue* q, ElemType e) {
    if ((q->real + 1) % q->maxSize == q->front) {
        q->baze =realloc(q->baze,(q->maxSize + 10) * sizeof(ElemType));
        if(!q->baze){
            printf("扩容失败！\n");
        }
        
        q->maxSize += 10; //更改最大存储容量
    }
    q->baze[(q->real++) % q->maxSize] = e; //将数据存放进去，并且位置 + 1
    return 1;
}

ElemType deQueue(Queue* q) {
    if (q->front == q->real) {
        return 0;
    }
    return q->baze[(q->front++) % q->maxSize]; //返回出列的值
}

int isEmpty_Queue(Queue* q) {
    //当即将出列的位置等于即将插入的位置的时候 表示队列为空
    if (q->real == q->front) {
        return 1;
    }
    return 0;
}

typedef struct SqStack{
    ElemType* base;
    ElemType* top;
    int maxSize;
} SqStack;

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
    return 0;
}

//当栈底指针等于栈顶指针时，堆栈为空
int isEmpty_Stack(SqStack* sq) {
    if (sq->base == sq->top) {
        return 1;
    }
    return 0;
}

int main() {
	Queue q;
	SqStack s;
	initQueue(&q);
	initSqStack(&s);
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		ElemType x;
		scanf("%d",&x);
		enQueue(&q,x);
	}

	while (!isEmpty_Queue(&q)) {
		ElemType x = deQueue(&q);
		pushSqStack(&s,x);
	}

	while (!isEmpty_Stack(&s)) {
		printf("%d ",popSqStack(&s));
	}
	printf("\n");
	return 0;
}