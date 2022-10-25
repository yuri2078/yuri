#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define INITSIZE 1000
#define INCRE 20
#define OK 1
#define ERROR 0

typedef struct{
  char* data;
  int length,stringsize;
}SqString;

//串初始化
int initString(SqString* S)
{
	S->data = (char *)calloc(INITSIZE,sizeof(char));
    if(!S->data){
        return ERROR;
    }
    S->length = 0;
    S->stringsize = INITSIZE;
    return OK;
}

//串赋值
int strAssign(SqString* s, char* str)
{
	int i = 0;
    for(i = 0; *str; i++)
    {
        if(i > s->stringsize - 2){
            return ERROR;
        }
        s->data[i] = *str;
        str++;
    }
    s->data[i] = 0;
    s->length = i;
    return OK;
}

int index_bf(SqString *s,SqString *t,int start)
{
    for(int i = start - 1; i < s->length; i++)
    {
        int j = 0, k = i;
        while(t->data[j] && (s->data[k] == t->data[j] || t->data[j] == '?') ) 
        {
            j++;
            k++;
        }
        if(!t->data[j]){
            return i + 1;
        }
    }
    return 0;
}


int main()
{
	//使用KMP算法完成串的模式匹配
	SqString s,t;
    int pos;
    char str[INITSIZE];
    initString(&s);
	initString(&t);
	gets(str);
	strAssign(&s, str);
	gets(str);
	strAssign(&t, str);
	scanf("%d", &pos);
	if (index_bf(&s, &t, pos)) {
		printf("%d\n", index_bf(&s, &t, pos));
	} else {
		printf("0\n");
    }
	return 0;
}
