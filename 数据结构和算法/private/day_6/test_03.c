#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList initList();
int insertList(LinkList head, int pos, ElemType e);
int deleteList(LinkList head, int pos, ElemType *e);
void printList(LinkList head);
//初始化
LinkList initList()
{
    LinkList H;
    H = (LinkList)malloc(sizeof(LNode)); //申请一个头节点
    if (!H)
        return 0;   //申请失败
    H->next = NULL; //头节点的指针域置空
    return H;
}
//插入
int insertList(LinkList head, int pos, ElemType e)
{
    LinkList pre, q;
    int i = 1;
    pre = head;
    while (pre != NULL && i < pos)
    {
        pre = pre->next;
        i++;
    }
    if (pre == NULL || i > pos)
        return 0;
    q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    q->next = pre->next;
    pre->next = q;
    return 1;
}
//删除
int deleteList(LinkList head, int pos, ElemType *e)
{
    LinkList pre, q;
    pre = head;
    int j = 1;
    while (pre->next != NULL && j < pos) //找到待删除的位置
    {
        pre = pre->next;
        j++;
    }
    if (pre->next == NULL || j > pos)
        return 0;
    q = pre->next;
    *e = q->data;
    pre->next = q->next; //进行删除
    free(q);             //释放内存空间
    return 1;
}
//输出
void printList(LinkList head)
{

    head = head->next;
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    LinkList head;
    ElemType e;
    int i, n, m, pos;
    scanf("%d%d", &n, &m);
    head = initList();
    for (i = 0; i < n; i++)
    {
        scanf("%d", &e);
        insertList(head, i + 1, e);
    }
    //补充代码：执行M次删除，并输出删除后的链表
    for (i = 0; i < m; i++)
    {
        scanf("%d", &pos);
        if (deleteList(head, pos, &e) == 0)
            printf("error\n");
        else
            printf("%d\n", e);
    }
    printList(head);
    return 0;
}
