#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
} * BiTree;

void createBiTree(BiTree* t)
{
	//此处补充代码，输入二叉树的先序遍历序列建立二叉树
	char ch = getchar();
	getchar();
	if (ch == '#') {
		*t = NULL;
		return;
	} else {
		*t = (BiTree)calloc(1, sizeof(struct BTNode));
		(*t)->data = ch;
		createBiTree(&(*t)->lchild);
	}

	createBiTree(&(*t)->rchild);
}

//此处补充代码，定义函数，交换二叉树结点的左右孩子
void swapChildren(BiTree tree)
{
	if (tree) {
		BiTree node;
		node = tree->lchild;
		tree->lchild = tree->rchild;
		tree->rchild = node;
		swapChildren(tree->lchild);
		swapChildren(tree->rchild);
	}
}

void PreOrder(BiTree p)
{
	//此处补充代码完成二叉树的先序遍历
	if (p) {
		printf("%c", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}

void InOrder(BiTree p)
{
	//此处补充代码完成二叉树的中序遍历
	if (p) {
		InOrder(p->lchild);
		printf("%c", p->data);
		InOrder(p->rchild);
	}
}

void PostOrder(BiTree p)
{
	//此处补充代码完成二叉树的后序遍历
	if (p) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%c", p->data);
	}
}

int main()
{
	//此处补充代码，调用函数完成原二叉树的三种遍历序列及交换左右孩子后的三种遍历序列
	BiTree tree;
	createBiTree(&tree);
	printf("preorder:");
	PreOrder(tree);
	printf("\ninorder:");
	InOrder(tree);
	printf("\npostorder:");
	PostOrder(tree);
	printf("\nAfter swap:");
	swapChildren(tree);
	printf("\npreorder:");
	PreOrder(tree);
	printf("\ninorder:");
	InOrder(tree);
	printf("\npostorder:");
	PostOrder(tree);
	return 0;
}
