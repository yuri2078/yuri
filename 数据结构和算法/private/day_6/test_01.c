#include<stdio.h>
#include<stdlib.h>
typedef  int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList initList();
int insertList(LinkList head, int pos, ElemType e);
int deleteList(LinkList head, int pos ,ElemType *e);
void printList(LinkList head);
//初始化
LinkList initList()
{
    LinkList head = (LinkList)malloc(sizeof(LNode));
    head->data = 0;
    head->next = NULL;
    return head;
}
//插入
int insertList(LinkList head, int pos, ElemType e)
{
    if(pos - 1 > head->data || pos < 1){
        return 0;
    }

    LinkList p = head;
    for (int i = 1; i < pos; i++){
        p = p->next;
    }

    LinkList temp = (LinkList)malloc(sizeof(LNode));
    temp->data = e;
    temp->next = p->next;
    p->next = temp;
    head->data++;

    return pos;
}
//删除
int deleteList(LinkList head, int pos ,ElemType *e)
{
    if(pos > head->data || pos < 1){
        return 0;
    }

    LinkList p = head;
    for (int i = 1; i < pos; i++){
        p = p->next;
    }

    LinkList temp = p->next->next;
    *e = p->next->data;
    free(p->next);
    p->next = temp;
    head->data--;
    return pos;
}
//输出
void printList(LinkList head)
{
    LinkList p = head->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}
int main()
{
    LinkList head;
    ElemType e;
    int i,n,m,pos;
    scanf("%d%d",&n,&m);
    head=initList();
    for(i=0;i<n;i++)
    {
        scanf("%d",&e);
        insertList(head,i+1,e);
    }
    //补充代码：执行M次删除，并输出删除后的链表
    for (int i = 0; i < m;i++)
    {
        scanf("%d", &pos);
        if(deleteList(head, pos, &e) == 0){
            printf("error\n");
        }else{
            printf("%d\n", e);
        }
    }
    printList(head);
    return 0;
}