#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define MAXQSIZE 1000
typedef int ElemType;
typedef struct 
{
	ElemType data[MAXQSIZE];
	int top;
}SqQueue;
int EnQueue(SqQueue *s,ElemType e)
{
	if(s->top>MAXQSIZE) return ERROR;
	s->data[s->top++]=e;
	return OK;
}
int DeQueue(SqQueue *s,ElemType *e)
{
	if(s->top<0) return ERROR;
	s->top--;
	*e=s->data[s->top];
	return OK;
}
int main()
{
	SqQueue s;
	int i,n;
	ElemType e;
	scanf("%d",&n);
	s.top=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		EnQueue(&s,e);
	}
	while(s.top>0)
	{
		DeQueue(&s,&e);
		printf("%d ",e);
	}
	printf("\n");
	return 0;
}
