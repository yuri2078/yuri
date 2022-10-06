#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct QNode {
	ElemType data;
	struct QNode* next;
} QNode;
/*初始化队列*/
int InitQueue(QNode** rear) {
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (!p)
		return 0;
	p->next = p;
	*rear = p;
	return 1;
}
/*入队*/
int EnQueue(QNode** rear, ElemType e) {
	(*rear)->data =e;
	QNode* p = (QNode*)calloc(1, sizeof(QNode));
	if (!p) {
		return 0;
	}
	p->next = (*rear)->next;
	(*rear)->next = p;
	(*rear) = p;
	return 1;
}

/*判断队列是否为空*/
int QueueEmpty(QNode* rear) {
	if (rear->next == rear) {
		return 1;
	}
	return  0;
}
/*出队*/
int DeQueue(QNode** rear, ElemType* e) {
	if (QueueEmpty(*rear)) {
		return 0;
	}
	*e = (*rear)->next->data;
	QNode *temp = (*rear)->next;
	(*rear)->next = (*rear)->next->next;
	free(temp);
	return 1;
}

int main() {
	QNode* q;
	ElemType e;
	InitQueue(&q);
	while (scanf("%d", &e) == 1) {
		if (e) {
			EnQueue(&q, e);
		} else {
			if (QueueEmpty(q)) {
				printf("error");
				return 0;
			} else {
				DeQueue(&q, &e);
			}
		}
	}
	if (QueueEmpty(q))
		printf("empty");
	else {
		while (!QueueEmpty(q)) {
			DeQueue(&q, &e);
			printf("%d ", e);
		}
	}
	return 1;
}