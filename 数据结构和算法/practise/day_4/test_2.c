#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 5
#define INCREM 3
typedef int ElemType;
/*顺序表结构*/
typedef struct Sqlist
{
    ElemType *slist;
    int length;
    int listsize;
} Sqlist;
/*初始化顺序表：创建成功返回1，不成功返回0*/
int initSq(Sqlist *L)
{
    L->listsize = INIT_SIZE;
    L->length = 0;
    L->slist = (ElemType *)malloc(L->listsize * sizeof(ElemType));
    if(L->slist){
        return 1;
    }
    return 0;
}
/*在i位置插入元素：插入成功返回1，不成功返回0*/
int insertSq(Sqlist *L, ElemType e, int i)
{
    if(i > L->length){
        return 0;
    }
    
    if (i == L->length)
    {
        L->slist = (ElemType *)realloc(L->slist, sizeof(ElemType));
        L->listsize++;
    }

    int j = L->length;
    while(j != i)
    {
        L->slist[j] = L->slist[j - 1];
        j--;
    }
    L->slist[i] = e;
    L->length++;
    return 1;
}
/*输出顺序表元素*/
void printSq(Sqlist *L)
{
    int i;
    for (i = 0; i < L->length; i++)
    {
        printf("%d ", L->slist[i]);
    }
    printf("\n");
}
int main()
{
    Sqlist sq;
    ElemType e;
    int n;
    if (initSq(&sq))
    {
        scanf("%d", &n);
        /*补充代码，实现n个元素顺序表的创建*/
        for (int i = 0; i < n;i++)
        {
            scanf("%d", &e);
            insertSq(&sq, e, i);
        }
        printSq(&sq);
    }
    return 0;
}
