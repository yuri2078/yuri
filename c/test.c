#include <stdio.h>

typedef struct list {
	struct list* next;
	struct list* front;
	int val;
}list;

int main(void)
{
	// 1 2 3
	// p : 1
	// p->next 2
	// p->next->next 3
	list* p;
	p->next->next; // 被删除的节点的next
	p->next->next->front = p; // 更改被删除节点next 的前接节点为p
	p->next = p->next->next; // 将p->next 指向 被删除的next
    return 0;
}