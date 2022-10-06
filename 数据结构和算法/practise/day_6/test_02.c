#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

LinkList initList();
int insertList(LinkList head, int pos, ElemType e);
int GetIndex(LinkList head, ElemType e);
//初始化
LinkList initList() {
  LinkList head = (LinkList)malloc(sizeof(LNode));
  head->data = 0;
  head->next = NULL;
  return head;
}
//插入
int insertList(LinkList head, int pos, ElemType e) {
  if (pos - 1 > head->data || pos < 1) {
    return 0;
  }

  LinkList p = head;
  for (int i = 1; i < pos; i++) {
    p = p->next;
  }

  LinkList temp = (LinkList)malloc(sizeof(LNode));
  temp->data = e;
  temp->next = p->next;
  p->next = temp;
  head->data++;

  return pos;
}
//补充查找算法：若找到返回e在链表中位置，未找到返回0
int getIndex(LinkList head, ElemType e) {
  int pos = 1;
  LinkList p = head->next;
  while (p && e != p->data) {
    p = p->next;
    pos++;
  }
  if (p == NULL) {
    pos = 0;
  }
  return pos;
}
int main() {
  LinkList head;
  ElemType e;
  int i, n;
  scanf("%d", &n);
  head = initList();
  for (i = 0; i < n; i++) {
    scanf("%d", &e);
    insertList(head, i + 1, e);
  }
  //补充代码，实现若干个关键字值得查找
  int pos, flag;
  flag = scanf("%d", &e);
  while (flag && flag != EOF) {
    if ((pos = getIndex(head, e))) {
      printf("%d\n", pos);
    } else {
      printf("no\n");
    }
    flag = scanf("%d", &e);
  }
  return 0;
}