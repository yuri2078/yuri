#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
typedef struct{
	char *data;
	int length;
	int stringsize;
}SqString;
//初始化
int initString(SqString* s)
{
	s->data = (char *)calloc(MAXSIZE,sizeof(char));
    if(!s->data){
        return 0;
    }
    s->length = 0;
    s->stringsize = MAXSIZE;
    return 1;
}
//将字符串str赋值到串s中
int strAssign(SqString *s, char *str )
{
	int i = 0;
    for(i = 0; *str; i++)
    {
        if(i > s->stringsize - 2){
            return 0;
        }
        s->data[i] = *str;
        str++;
    }
    s->data[i] = 0;
    s->length = i;
    return 1;
}
//串比较
int strCompare(SqString* s, SqString* t)
{
	char *s1 = s->data;
    char *s2 = t->data;
    while(*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
//在s中从pos开始取len长度的子串到sub中
int subString(SqString* sub, SqString* s, int pos, int len)
{
	pos--;
    if(len  >= sub->stringsize){
        return 0;
    }
    for(int i = 0; i < len; i++){
        sub->data[i] = s->data[pos + i];
        if(pos + i >= s->length){
            return 0;
        }
	}
	sub->data[len] = 0;
    sub->length = len;
    return 1;
}
//将s1与s2连接到s中
int strConcat(SqString* s, SqString* s1, SqString* s2)
{
	int i = 0, j = 0, len = 0;
    while (len < s->length || s2->data[j])
    {
        char ch = len < s->length ? s1->data[i++] : s2->data[j++];
        s->data[len++] = ch;
        if(len > s->stringsize){
            return 0;
        }
	}
	s->data[len] = 0;
	s->length = len;
    return 1;
}
//在s1中指定位置pos插入子串s2
int strInsertSub(SqString* s1, SqString* s2, int pos)
{
	if (pos > s1->length + 1 || s1->length + s2->length > s1->stringsize) {
		return 0;
	}
	SqString s3;
	initString(&s3);
	subString(&s3, s1, pos, s1->length - pos + 1);
	strConcat(s2, s2, &s3);
	subString(s1, s1, 1, pos - 1);
	strConcat(s1, s1, s2);
	
	return 1;
}
int main(){
    SqString s1,s2;
    int pos,n,r;
    char str[MAXSIZE];
    initString(&s1);
    initString(&s2);
    scanf("%d",&n);
    while(n--){
        getchar();
        gets(str);
        strAssign(&s1,str);
        gets(str);
        strAssign(&s2,str);
        scanf("%d",&pos);
        r=strCompare(&s1,&s2);
        if(r>0)
                puts(s1.data);
        else if(r<0)
                puts(s2.data);
              else
                printf("equal\n");
        if(strInsertSub(&s1,&s2,pos))
            puts(s1.data);
        else
            printf("error\n");

	}

	
	
    return 0;
}