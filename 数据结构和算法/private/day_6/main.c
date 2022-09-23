#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void CreateListTail(LinkList *L)
{
    LinkList p, q;
    ElemType e;
    p = *L = (LinkList)malloc(sizeof(LNode));
    while (scanf("%d", &e) == 1)
    {
        q = (LNode *)malloc(sizeof(LNode));
        q->data = e;
        p->next = q;
        p = q;
    }
    p->next = NULL;
}

void PrintList(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void MaxLastSwap(LinkList L)
{
    LinkList p = L, max = L->next, temp = L;
    while (p->next)
    {
        if (max->data < p->next->data){
            max = p;
        }
        temp = p;
        p = p->next;
    }
    p->next = max->next->next;
    temp->next = max->next;
    
    max->next = p;
    temp->next->next = NULL;
}

int main()
{
    LinkList L;
    CreateListTail(&L);
    MaxLastSwap(L);
    PrintList(L);
    return 0;
}
