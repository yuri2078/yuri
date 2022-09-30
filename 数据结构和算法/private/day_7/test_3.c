#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define ERROR 0
#define OK 1
#define STACK_INT_SIZE 10 /*存储空间初始分配量*/
#define STACKINCREMENT 5  /*存储空间分配增量*/
typedef int ElemType;     /*定义元素的类型*/
typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize; /*当前已分配的存储空间*/
} SqStack;

int InitStack(SqStack* S);           /*构造空栈*/
int Push(SqStack* S, ElemType e);    /*入栈*/
int Pop(SqStack* S, ElemType* e);    /*出栈*/
int GetTop(SqStack* S, ElemType* e); /*获取栈顶元素*/
int ClearStack(SqStack* S);          /*清空栈*/
int StackEmpty(SqStack* S);          /*判断栈是否为空*/
int StackLength(SqStack* S);         /*求栈的长度*/

void conversion(int m); /*十进制转换为二进制*/
int InitStack(SqStack* S) {
	S->base = (ElemType*)malloc(STACK_INT_SIZE * sizeof(ElemType));
	if (!S->base)
		return ERROR;
	S->top = S->base;
	S->stacksize = STACK_INT_SIZE;
	return OK;
} /*InitStack*/

int Push(SqStack* S, ElemType e) {
	if (S->top - S->base >= S->stacksize) {
		S->base = (ElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) *
		                                          sizeof(ElemType));
		if (!S->base)
			return ERROR;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
} /*Push*/

int Pop(SqStack* S, ElemType* e) {
	if (S->top == S->base)
		return ERROR;
	*e = *--S->top;
	return OK;
} /*Pop*/

int GetTop(SqStack* S, ElemType* e) {
	if (S->top == S->base)
		return ERROR;
	*e = *(S->top - 1);
	return OK;
} /*GetTop*/

int ClearStack(SqStack* S) {
	S->top = S->base;
	return OK;
} /*ClearStack*/

int StackEmpty(SqStack* S) {
	if (S->top == S->base)
		return OK;
	else
		return ERROR;
} /*StackEmpty*/

int StackLength(SqStack* S) {
	return S->top - S->base;
} /*StackLength*/

void Conversion(int m) {
	SqStack cs;
	InitStack(&cs);
	while (m) {
		Push(&cs, m % 2);
		m = m / 2;
	}

	while (!StackEmpty(&cs)) {
		ElemType e = 0;
		Pop(&cs, &e);
		printf("%d", e);
	}
	printf("\n");
	
} /*Conversion*/

int main() {
	int n;
	scanf("%d", &n);
	Conversion(n);
	return 0;
}