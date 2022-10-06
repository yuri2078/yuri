#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct QNode {
	ElemType data;
	struct QNode* next;
} QNode;

typedef struct LinkQueue {
	QNode* rear;
	QNode* front;
} LinkQueue;

int InitQueue(LinkQueue* Q) {
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (!p)
		return 0;
	Q->front = Q->rear = p;
	p->next = NULL;
	return 1;
}

int EnQueue(LinkQueue* Q, ElemType e) {
	QNode* p = (QNode*)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return 1;
}

int QueueEmpty(LinkQueue* Q) {
	if (Q->front == Q->rear) {
		return 1;
	}
	return 0;
}

int DeQueue(LinkQueue* Q, ElemType* e) {
	if (QueueEmpty(Q)) {
		return 0;
	}
	*e = Q->front->next->data;
	QNode* temp = Q->front;
	Q->front = Q->front->next;
	free(temp);
	return 1;
}

int main() {
	LinkQueue q;
	int i = 4;
	ElemType x;
	InitQueue(&q);
	while (scanf("%d",&i) == 1)  {
		if (i) {
			EnQueue(&q,i);
		} else if (!DeQueue(&q, &x)) {
			printf("error\n");
			return 0;
		}
	}
	if (QueueEmpty(&q)) {
		printf("empty\n");
	} else {
		while (!QueueEmpty(&q)) {
			DeQueue(&q,&x);
			printf("%d ",x);
		}
	}
	printf("\n");
	return 0;
}