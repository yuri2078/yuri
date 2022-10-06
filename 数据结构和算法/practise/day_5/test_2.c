#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 5
#define INCREM 3
typedef int ElemType;
typedef struct Sqlist
{
    ElemType *slist;
    int length;
    int listsize;
} Sqlist;
//初始化
int initSq(Sqlist *L)
{
    L->slist = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
    if (L->slist == NULL)
    {
        return 0;
    }
    L->length = 0;
    L->listsize = INIT_SIZE;
    return 1;
}
//插入元素
int insertSq(Sqlist *L, ElemType e, int i)
{
    if (i < 1 || i > L->length + 1)
    {
        return 0;
    }
    if (L->length >= L->listsize)
    {
        L->slist = (ElemType *)realloc(L->slist, (L->listsize + INCREM) * sizeof(ElemType));
        if (L->slist == NULL)
            return 0;
        L->listsize += INCREM;
    }
    int j;
    for (j = L->length - 1; j >= i - 1; j--)
    {
        L->slist[j + 1] = L->slist[j];
    }
    L->slist[i - 1] = e;
    L->length++;
    return 1;
}
//输出顺序表
void printSq(Sqlist *L)
{
    int i;
    for (i = 0; i < L->length; i++)
    {
        printf("%d ", L->slist[i]);
    }
    printf("\n");
}
//查找最大值:返回最大值在顺序表中的位序,若为空表，返回0
int searchMax(Sqlist *L)
{
    if(L->length == 0){
        return 0;
    }
    int p = 0;
    for (int i = 1; i < L->length;i++){
        if(L->slist[p] < L->slist[i]){
            p = i;
        }
    }
    return p + 1;
}
int main()
{
    Sqlist sq;
    ElemType e;
    if (initSq(&sq))
    {
        while (scanf("%d", &e) == 1)
        {
            insertSq(&sq, e, sq.length + 1);
        }
        //以下补充输出结果代码
        int p = searchMax(&sq);
        if (p == 0)
        {
            printf("no\n");
        }
        else
        {
            printf("%d %d\n",sq.slist[p - 1], p);
        }
    }
    return 0;
}