#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 50 /*初始大小*/
#define INCREM 10    /*增量大小*/
#define OK 1         /*正确返回值*/
#define ERROR 0      /*出错返回值*/

typedef int ElemType; /*元素数据类型*/
typedef struct SqList
{
    ElemType *slist;
    int length;
    int listsize;
} SqList;

int ListInit_sq(SqList *L)
{
    L->slist = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType)); /*分配初始大小内存空间*/
    if (L->slist == NULL)
        return ERROR;        /*分配失败返回错误*/
    L->listsize = INIT_SIZE; /*容量大小为初始大小*/
    L->length = 0;           /*长度为0*/
    return OK;
}

int ListInsert_sq(SqList *L, int i, ElemType e) /*在第i位序插入元素e*/
{
    int j;
    if (i < 1 || i > L->length + 1)
        return ERROR; /*判断插入位置是否合法*/
    if (L->length >= L->listsize)
    {
        L->slist = (ElemType *)realloc(L->slist, (L->listsize + INCREM) * sizeof(ElemType));
        if (!L->slist)
            return ERROR;
        L->listsize += INCREM; /*重新确定顺序表容量大小*/
    }
    for (j = L->length; j >= i; j--)
        L->slist[j] = L->slist[j - 1]; /*后续元素从后往前后移*/
    L->slist[j] = e;                   /*新元素插入*/
    L->length++;                       /*表长增1*/
    return OK;
}

int ListCreateN_sq(SqList *L, int n) /*建立n个元素的顺序表*/
{
    int i;
    ElemType e;
    if (n > L->listsize)
        L->slist = (ElemType *)realloc(L->slist, n * sizeof(ElemType)); /*容量不够重新分配空间*/
    if (L->slist == NULL)
        return ERROR;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &e);
        ListInsert_sq(L, i + 1, e);
    }
    return OK;
}


void ListPrint_sq(SqList *L) /*输出顺序表中所有元素*/
{
    for (int i = 0; i < L->length;i++){
        printf("%d ", L->slist[i]);
    }
    printf("\n");
}

void ListDeleteLessThanX(SqList *L, ElemType x)
{
    for (int i = 0; i < L->length;i++)
    {
        if(L->slist[i] < x)
        {
            for (int j = i; j < L->length - 1;j++){
                L->slist[j] = L->slist[j + 1];
            }
            L->length = L->length - 1;
            i--;
        }
    }
}

int main()
{
    SqList l;
    int n, x;
    scanf("%d", &n);
    ListInit_sq(&l);
    ListCreateN_sq(&l, n);
    scanf("%d", &x);
    ListDeleteLessThanX(&l, x);
    ListPrint_sq(&l);
    return 0;
}