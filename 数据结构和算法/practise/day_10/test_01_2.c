#include<stdio.h>
#include <stdlib.h>

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
int indexKMP(SqString* s, SqString* t,  int next[])
{
	if (t->length == 0) {
		return 0;
	}
	int i = 0, j = 0;
	while (i < s->length && j < t->length) {
		if (j == -1 || s->data[i] == t->data[j]) {
			i++;
			j++;
		}else {
            j = next[j];
        }
	}
	if (j >= t->length) {
		int k = i - j;
		while (s->data[k + t->length]) {
			s->data[k] = s->data[k + t->length];
			k++;
		}
		s->data[k] = 0;
		s->length -= t->length;
		indexKMP(s, t, next);
		return i - t->length + 1;
    }
	return 0;
}
//求取模式串next值
void getNext(SqString* t, int next[])
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i < t->length) {
		if (j == -1 || t->data[i] == t->data[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
            j = next[j];
        }
	}
	for (int i = 0; i < t->length; i++) {
		printf("%d ",next[i]);
	}
	printf("\n");
}

int my_gets(char* str)
{
	char ch;
	int i = 0;
	while ((ch = getchar()) != '\n') {
		str[i++] = ch;
	}
	str[i] = 0;
	return i;
}

int main()
{
	//使用KMP算法完成串的模式匹配
	SqString s, t;
	initString(&s);
	initString(&t);

	char* str = (char*)calloc(INITSIZE, sizeof(char));
	gets(str);
	// my_gets(str);
	strAssign(&s, str);
	gets(str);
	// my_gets(str);
	strAssign(&t, str);
	int* next = (int*)calloc(t.length, sizeof(int));
	getNext(&t, next);
	indexKMP(&s, &t, next);
	puts(s.data);
	
	return 0;
}
