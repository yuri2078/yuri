#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define INIT_SIZE 100
#define INCREMENT 20

typedef int ElemType;
typedef struct SqStack {
	ElemType *base, *top;
	int stacksize;
} SqStack;
/*初始化顺序栈*/
int InitStack(SqStack* S) {
	S->base = (ElemType*)(malloc(INIT_SIZE * sizeof(ElemType)));
	if (!S->base) {
		return ERROR;
	}
	S->stacksize = INIT_SIZE;
	S->top = S->base;

	return OK;
}
/*判栈空*/
int Empty(SqStack* S) {
	if (S->base == S->top) {
		return 1;
	}

	return 0;
}
/*入栈*/
int Push(SqStack* S, ElemType e) {
	if (S->top - S->base >= S->stacksize) {
		S->base = (ElemType*)realloc(S->base, (INCREMENT + S->stacksize) *
		                                          sizeof(ElemType));
		S->top = S->base + S->stacksize;
	}

	*S->top = e;
	S->top++;
	return 1;
}
/*出栈*/
int Pop(SqStack* S, ElemType* e) {

	if (Empty(S)) {
		return ERROR;
	}

	S->top--;
	*e = *S->top;
	return OK;
}
/*取栈顶元素*/
int GetTop(SqStack* S, ElemType* e) {
	if (Empty(S)) {
		return ERROR;
	}

	*e = *(S->top - 1);
	return OK;
}

int main() {
	SqStack s;
	ElemType e;
	InitStack(&s);
	int in[100];  //输入序列
	int out[100]; // 输出序列

	/*此处填充代码，利用堆栈基本操作判断序列是否为正确的出栈序列*/
	int x;
	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		scanf("%d", in + i);
	}

	for (int i = 0; i < x; i++) {
		scanf("%d", out + i);
	}

	int i = 0, j = 0;
	e = 0;
	while (i < x) {
		Push(&s, in[i++]);
		while (j < i) {
			GetTop(&s, &e);
			if (out[j] == e) {
				Pop(&s, &e);
				j++;
			} else {
				break;
			}
		}
	}

	if (Empty(&s)) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	return 0;
}