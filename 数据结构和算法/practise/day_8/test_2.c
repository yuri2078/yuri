#include <malloc.h>
#include <stdio.h>
#define ERROR 0
#define OK 1
#define MAXQSIZE 20
typedef int QElemType; /*队列元素类型*/
typedef struct {
	QElemType* base;
	int front;
	int rear;
} SqQueue;

/*初始化队列*/
int InitQueue(SqQueue* Q) {
	Q->base = (QElemType*)calloc(MAXQSIZE, sizeof(QElemType));
	if (!Q->base) {
		return  ERROR;
	}
	Q->rear = Q->front = 0;
	return  OK;
} /*InitQueue*/

/*求队长*/
int QueueLength(SqQueue* Q) {
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
} /*QueueLentgh*/

/*入队*/
int EnQueue(SqQueue* Q, QElemType e) {
	if (QueueLength(Q) == MAXQSIZE) {
		return ERROR;
	}
	Q->base[(Q->rear++) % MAXQSIZE] = e;
	return OK;
} /*EnQuese*/

/*出队*/
int DeQueue(SqQueue* Q, QElemType* e) {
	if (Q->front == Q->rear) {
		return ERROR;
	}
	*e = Q->base[(Q->front++) % MAXQSIZE];
	return  OK;
} /*DeQueue*/

/*判队空*/
int QueueEmpty(SqQueue* Q) {
	if (Q->rear == Q->front) {
		return 1;
	}
	return  0;
} /*QueueEmpty*/

/*取队头*/
int GetHead(SqQueue* Q, QElemType* e) {
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->base[Q->front];
	return OK;
} /*GetHead*/

/*销毁队列*/
int DestroyQueue(SqQueue* Q) {
	if (Q->base) {
		Q->rear = Q->front = 0;
		free(Q->base);
	}
	return OK;
} /*DestroyQueue*/

int main() {
	SqQueue q;
	int e;
	InitQueue(&q);
	/*使用队列基本操作完成程序功能*/
	while (scanf("%d", &e) == 1) {
		if (e) {
			EnQueue(&q, e);
		} else {
			if (QueueEmpty(&q)) {
				printf("error");
				return 0;
			} else {
				DeQueue(&q, &e);
			}
		}
	}
	if (QueueLength(&q)) {
		while (!QueueEmpty(&q)) {
			DeQueue(&q, &e);
			printf("%d ", e);
		}
	} else {
		printf("empty");
	}
	return 0;
}
