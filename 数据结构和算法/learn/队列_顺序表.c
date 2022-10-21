#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Queue {
    ElemType* base;
    int rear, front, maxSize;
} Queue;

//这是顺序表循环队列,并且是可以扩容的

//初始队列
int initQueue(Queue *q) {
    q->base = (ElemType*)calloc(20, sizeof(ElemType));
    if (!q->base) {
        printf("数据初始化失败捏\n");
        return 0;
    }
    q->rear = 0; //设置将要存储的位置
    q->front = 0; //设置出列的位置
    q->maxSize = 20; //设置最大容量
    return 1;
}

int enQueue(Queue* q, ElemType e) {
	if ((q->rear + 1) % q->maxSize == q->front) {
		printf("容量不足，已经自动扩容了捏!\n");
        q->base =realloc(q->base,(q->maxSize + 10) * sizeof(ElemType));
        if(!q->base){
            printf("扩容失败！\n");
        }
        
        q->maxSize += 10; //更改最大存储容量
    }
    q->base[(q->rear++) % q->maxSize] = e; //将数据存放进去，并且位置 + 1
    return 1;
}


ElemType deQueue(Queue* q) {
    if (q->front == q->rear) {
        return 0;
    }
    return q->base[(q->front++) % q->maxSize]; //返回出列的值
}

int isEmpty(Queue* q) {
    //当即将出列的位置等于即将插入的位置的时候 表示队列为空
    if (q->rear == q->front) {
        return 1;
    }
    return 0;
}

int main(void) {
    Queue* q = (Queue*)calloc(1, sizeof(Queue)); //为普通队列申请内存
    initQueue(q); //初始化队列

    for (int i=0; i<40; i++) {
        enQueue(q,i);
	}
	int n;

    while (!isEmpty(q)) {
        printf("%d ",deQueue(q));
    }
    printf("\n");
    free(q); //释放内存
    return 0;
}

