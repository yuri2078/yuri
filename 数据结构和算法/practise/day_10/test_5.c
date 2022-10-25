#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 1000
typedef struct{
	char *data;
	int length;
	int stringsize;
}SqString;
//串的初始化
int initString(SqString *s)
{
    s->data=(char *)malloc(MAXSIZE*sizeof(char));
    if(!s->data)
        return 0;
    s->length=0;
    s->data[0]='\0';
    s->stringsize=MAXSIZE;
    return 1;
}
//串的复制
int strAssign(SqString *s, char *str )
{
  	int i=0;
	while(*str!='\0')
		s->data[i++]=*str++;
	s->data[i]='\0';
	s->length=i;
	return 1;
}
//串的比较
int strCompare(SqString *s,SqString *t){
  	int i;
	for(i=0;i<s->length&&i<t->length;i++)
        if(s->data[i]!=t->data[i])
            return s->data[i]-t->data[i];
	return s->length-t->length;
}
//取子串
int subString(SqString *sub,SqString *s,int pos,int len){
  	int i;
	if(pos<1||pos>s->length||len<0||len>s->length-pos+1){
        sub->data[0]='\0';
        return 0;
	}
	sub->length=0;
	for(i=0;i<len;i++){
	   sub->data[i]=s->data[i+pos-1];
	   sub->length++;
	}
	sub->data[i]='\0';
	return 1;
}
//串的连接
int strConcat(SqString *s,SqString *s1, SqString *s2){
  	int i=0,j=0;
	if(s1->length+s2->length>=s->stringsize){
	   s->data=(char*)realloc(s->data,(s->stringsize+MAXSIZE)*sizeof(char));
	   if(!s->data) return 0;
	   s->stringsize+=MAXSIZE;
	}
	while(i<s1->length){
        s->data[i]=s1->data[i];
        i++;
	}
	while(j<s2->length)
	   s->data[i++]=s2->data[j++];
	s->data[i]='\0';
	s->length=s1->length+s2->length;
	return 1;
}
int indexBF(SqString *s,SqString *t,int start)
{
    int i,j;
    i=start-1;
    j=0;
    while(j<t->length&&i<s->length)
    {
        if(s->data[i]==t->data[j])
        {
            i++;
            j++;
        }else
        {
            i=i-j+1;
            j=0;
        }
    }
    if(j>=t->length)
    {
        return i-j+1;
    }
    return 0;
}
//在串中删除从第pos字符开始长度为len的子串
int delSubPosition(SqString *s,int pos,int len)
{
	if (pos + len > s->length) {
		return 0;
    }
	while (s->data[pos + len - 1]) {
		s->data[pos] = s->data[pos + len];
		pos++;
    }
	return 1;
}
//在s串中删除所有t串
void delSub(SqString *s,SqString *t)
{
	int pos;
	while ((pos = indexBF(s, t, 1))) {
        delSubPosition(s, pos - 1, t->length);
    }
}

int main()
{
    SqString s,t;
    char str[MAXSIZE];
    initString(&s);
    initString(&t);
    gets(str);
    strAssign(&s,str);
    gets(str);
    strAssign(&t,str);
    //删除子串
    delSub(&s,&t);
    puts(s.data);
    return 0;
}
