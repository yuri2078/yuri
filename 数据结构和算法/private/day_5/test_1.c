#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 100
#define INCREM 10
#define OK 1
#define ERROR 0
#define Swap(a, b) a ^= b, b ^= a, a ^= b;

typedef int ElemType;
typedef struct SqList
{
    ElemType *slist;
    int length;
    int listsize;
} SqList;
/*传值    传地址*/
int ListInit_sq(SqList *L)
{
    L->slist = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
    if (L->slist == NULL)
        return ERROR;
    L->length = 0;
    L->listsize = INIT_SIZE;
    return OK;
}

int ListInsert_sq(SqList *L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->length + 1)
        return ERROR;
    if (L->length >= L->listsize)
    {
        L->slist = (ElemType *)realloc(L->slist, (L->listsize + INCREM) * sizeof(ElemType));
        if (!L->slist)
            return ERROR;
        L->listsize += INCREM;
    }
    for (j = L->length; j >= i; j--)
        L->slist[j] = L->slist[j - 1];
    L->slist[j] = e;
    L->length++;
    return OK;
}

int ListCreateN_sq(SqList *L, int n)
{
    int i;
    ElemType e;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &e);
        ListInsert_sq(L, i + 1, e);
    }
    return OK;
}

void ListPrint_sq(SqList *L)
{
    int i;
    for (i = 0; i < L->length; i++)
        printf("%d  ", L->slist[i]);
    printf("\n");
    return;
}
/*程序中如果需要另外定义函数可在此处定义*/

/*将顺序表L中的元素循环左移m位*/
void LeftShift(SqList *L, int m)
{
    for (int i = 0; i < m;i++)
    {
        int x = L->slist[0];
        for (int j = 0; j < L->length - 1;j++){
            L->slist[j] = L->slist[j + 1];
        }
        L->slist[L->length - 1] = x;
    }
}
int main()
{
    SqList la;
    int n, m;
    scanf("%d  %d", &n, &m);
    ListInit_sq(&la);
    ListCreateN_sq(&la, n);
    /*调用函数将顺序表la中元素左移m位*/
    LeftShift(&la, m);

    ListPrint_sq(&la);
    return 0;
}