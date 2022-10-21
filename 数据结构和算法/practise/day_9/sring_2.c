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
int initString(SqString *S){
    S->data = (char *)calloc(INITSIZE,sizeof(char));
    if(!S->data){
        return 0;
    }
    S->length = 0;
    S->stringsize = INITSIZE;
    return 1;
}

//串赋值
int strAssign(SqString *s, char *str ){
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
//基本模式匹配算法
int index_bf(SqString *s,SqString *t,int start)
{
    int flag = 0;
    for(int i = start; i < s->length; i++)
    {
        int j = 0, k = i;
        while(t->data[j] && s->data[k] == t->data[j])
        {
            j++;
            k++;
        }
        if(!t->data[j]){
            flag = 1;
            printf("%d ",i + 1);
        }
    }
    return flag;
}
int main(){
    //利用模式匹配算法完成子串查找
    SqString s_1,s_2;
    initString(&s_1);
    initString(&s_2);
    char *str = (char *)calloc(INITSIZE, sizeof(char));
    scanf("%s",str);
    strAssign(&s_1, str);
    scanf("%s", str);
    strAssign(&s_2, str);
    if(!index_bf(&s_1, &s_2, 0)){
        printf("0");
    }
    printf("\n");
    return 0;
}
