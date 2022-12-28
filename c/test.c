#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct BTNode {
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
} * BiTree;

void createBiTree(BiTree* t)
{
	char s;
	BiTree q;
	s = getchar();
	getchar();
	if (s == '#') {
		*t = NULL;
		return;
	}
	q = (BiTree)malloc(sizeof(struct BTNode));
	if (q == NULL) {
		return;
	}
	q->data = s;
	*t = q;
	createBiTree(&q->lchild);
	createBiTree(&q->rchild);
}
int depth(BiTree t)
{
	if (t == NULL) {
		return 0;
	} else {
		int depth_l = depth(t->lchild);
		int depth_r = depth(t->rchild);
		return 1 + (depth_l > depth_r ? depth_l : depth_r);
	}
	char answer_3[] = "head(tail(head(tail(LS))))";

}

int main()
{
	BiTree t = NULL;
	createBiTree(&t);
	printf("%d\n", depth(t));
	return 0;
}