#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define STACK_INT_SIZE 10
#define STACKINCREMENT 5
typedef int ElemType;
typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;
} SqStack;

int initStack(SqStack* s);
int emptyStack(SqStack* s);
int pushStack(SqStack* s, ElemType e);
int popStack(SqStack* s, ElemType* e);

/*初始化顺序栈*/
int initStack(SqStack* S) {
	S->base = (ElemType*)(malloc(STACK_INT_SIZE * sizeof(ElemType)));
	if (!S->base) {
		return ERROR;
	}
	S->stacksize = STACK_INT_SIZE;
	S->top = S->base;

	return OK;
}
/*判栈空*/
int emptyStack(SqStack* S) {
	if (S->base == S->top) {
		return 1;
	}

	return 0;
}
/*入栈*/
int pushStack(SqStack* S, ElemType e) {
	if (S->top - S->base >= S->stacksize) {
		S->base = (ElemType*)realloc(S->base, (STACKINCREMENT + S->stacksize) *
		                                          sizeof(ElemType));
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}

	*S->top = e;
	S->top++;
	return 1;
}
/*出栈*/
int popStack(SqStack* S, ElemType* e) {

	if (emptyStack(S)) {
		return ERROR;
	}

	S->top--;
	*e = *S->top;
	return OK;
}

int main() {
	SqStack s;
	ElemType e;
	if (initStack(&s)) {
		//补充代码：实现读入数据入栈和出栈
		while (scanf("%d",&e) == 1) {
			pushStack(&s,e);
		}

		while (!emptyStack(&s)) {
			popStack(&s,&e);
			printf("%d ",e);
		}
		printf("\n");
	}
	return 0;
}
