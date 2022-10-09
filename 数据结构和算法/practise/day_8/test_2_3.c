#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define MAXQSIZE 20
#define INCREASESIZE 5
typedef int ElemType;
typedef struct {
	ElemType* base;
	int front;
	int rear;
	int queuesize;
} SqQueue;
int InitQueue(SqQueue* Q) {
	Q->base = (ElemType*)malloc(MAXQSIZE * sizeof(ElemType));
	if (!Q->base)
		return ERROR;
	Q->front = Q->rear = 0;
	Q->queuesize = MAXQSIZE;
	return OK;
}
int EnQueue(SqQueue* Q, ElemType e) {
	if ((Q->rear + 1) % Q->queuesize == Q->front) {
		Q->base = (ElemType*)realloc(Q->base, (Q->queuesize + INCREASESIZE) *
		                                          sizeof(ElemType));
		if (!Q->base)
			return ERROR;
		Q->queuesize += INCREASESIZE;
	}
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % Q->queuesize;
	return OK;
}
int DeQueue(SqQueue* Q, ElemType* e) {
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % Q->queuesize;
	return OK;
}
int QueueEmpty(SqQueue* Q) {
	if (Q->front == Q->rear)
		return OK;
	else
		return ERROR;
}
typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;
} SqStack;
int InitStack(SqStack* s) {
	s->base = (ElemType*)malloc(MAXQSIZE * sizeof(ElemType));
	if (!s->base)
		return ERROR;
	s->top = s->base;
	s->stacksize = MAXQSIZE;
	return OK;
}
int PushSqStack(SqStack* s, ElemType e) {
	if (s->top - s->base >= s->stacksize) {
		s->base = (ElemType*)realloc(s->base, (s->stacksize + INCREASESIZE) *
		                                          sizeof(ElemType));
		if (!s->base)
			return ERROR;
		s->top = s->base + s->stacksize;
		s->stacksize += INCREASESIZE;
	}
	*(s->top) = e;
	s->top++;
	return OK;
}
int PopSqStack(SqStack* s, ElemType* y) {
	if (s->top == s->base)
		return ERROR;
	s->top--;
	*y = *(s->top);
	return OK;
}
int main() {
	SqQueue Q;
	SqStack s;
	int i, n;
	ElemType e, y;
	scanf("%d", &n);
	InitQueue(&Q);
	InitStack(&s);
	for (i = 0; i < n; i++) {
		scanf("%d", &e);
		EnQueue(&Q, e);
	}
	while (!QueueEmpty(&Q)) {
		DeQueue(&Q, &e);
		PushSqStack(&s, e);
	}
	while (PopSqStack(&s, &y)) {
		printf("%d ", y);
	}
	return 0;
}