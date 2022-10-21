#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 100
typedef struct{
	char *data;
	int length;
	int stringsize;
}SqString;
//串的初始化
int initString(SqString *s)
{
    s->data = (char *)calloc(MAXSIZE,sizeof(char));
    if(!s->data){
        return 0;
    }
    s->length = 0;
    s->stringsize = MAXSIZE;
    return 1;
}
//串的复制
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
//串的比较
int strCompare(SqString *s,SqString *t)
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
//取子串
int subString(SqString *sub,SqString *s,int pos,int len)
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
    sub->length = len;
    return 1;
}
//串的连接
int strConcat(SqString *s,SqString *s1, SqString *s2)
{
    int i = 0, j = 0, len = 0;
    while (s1->data[i] || s2->data[j])
    {
        char ch = s1->data[i] ? s1->data[i++] : s2->data[j++];
        s->data[len++] = ch;
        if(len > s->stringsize){
            return 0;
        }
    }
    s->data[len] = 0;
    return 1;
}

int main()
{
    SqString s1,s2,t,s;
    int pos,n;
    char str[MAXSIZE];
    initString(&s1);
    initString(&s2);
    initString(&t);
    initString(&s);
    //读入一个字符串，复制给串s1
    scanf("%s",str);
    strAssign(&s1,str);
    //读入一个字符串，复制给串s1
    scanf("%s",str);
    strAssign(&s2,str);
    //比较s1和s2是否相等
    if(!strCompare(&s1,&s2))
    {
        printf("=\n");
    }else
    {
        printf("<>\n");
    }
    //输入子串位置和长度,在s1中取子串并输出，取不到输出error
    scanf("%d%d",&pos,&n);
    if(subString(&t,&s1,pos,n))
    {
        printf("%s\n",t.data);
    }else
    {
        printf("error\n");
    }
    //连接s1和s2，输出连接结果
    if(strConcat(&s,&s1,&s2))
        printf("%s",s.data);
    else
        printf("error\n");
    return 0;
}
