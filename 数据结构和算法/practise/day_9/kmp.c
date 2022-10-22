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
//模式匹配KMP算法
int indexKMP(SqString* s, SqString* t, int start, int next[])
{
	for (int i = start - 1, j = 0; i < s->length; i++) {
		if (s->data[i] == t->data[j]) {
			j++;
        }else if (next[j]) {
			j = next[j];
			i--;
        }else {
            j = next[j];
		}

		if (!t->data[j]) {
			return i - j + 2;
        }
    }
	return -1;
}
//求取模式串next值
void getNext(SqString* t, int next[])
{
	next[0] = 0;
	for (int i = 1; i < t->length; i++) {
		if (t->data[i] == t->data[next[i - 1]]) {
			next[i] = next[i - 1] + 1;
        }else {
			int j = next[i - 1] - 1;
			while (j >= 0 && t->data[j] != t->data[i]) {
                j--;
			}
			next[i] = j + 1;
        }
	}
}

int main()
{
	//使用KMP算法完成串的模式匹配
	SqString s,t;
    int pos, next[INITSIZE],start;
    char str[INITSIZE];
    initString(&s);
	initString(&t);
	scanf("%s", str);
	strAssign(&s, str);
	scanf("%s", str);
	strAssign(&t, str);
	scanf("%d", &pos);
	getNext(&t, next);
	for (int i = 0; i < t.length; i++) {
        printf("%d ",next[i]);
	}
	printf("\n");
	if ((start = indexKMP(&s, &t, pos, next)) == -1) {
		printf("0\n");
    }else {
        printf("%d\n",start);
    }
	return 0;
}
