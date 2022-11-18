#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
//二叉链表结点定义
typedef struct BTNode {
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
} *BiTree;

void createBiTree(BiTree* t)
{
	//此处补充代码，完成以先序遍历方式建立二叉树
	char ch = getchar(); // 获取数据
	getchar(); // 吃掉多余的回车
	if (ch == '#') {
		*t = NULL; // 当他为# 则将自己变成null
		return; // 直接返回不用申请空间
	} else {
		*t = (BiTree)calloc(1, sizeof(struct BTNode)); // 不是# 就要存储，需要申请空间
		(*t)->data = ch; // 存储数据
		createBiTree(&(*t)->lchild); // 继续存储左节点
	}
	createBiTree(&(*t)->rchild); // 当左节点处理完毕，处理右节点
}

void PreOrder(BiTree p)
{
	//此处补充代码，完成二叉树的先序遍历
	if (p) {
		printf("%c", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
    }
}

void InOrder(BiTree p)
{
	//此处补充代码，完成二叉树的中序遍历
	if (p) {
		InOrder(p->lchild);
		printf("%c", p->data);
		InOrder(p->rchild);
    }
}

void PostOrder(BiTree p)
{
	//此处补充代码，完成二叉树的后序遍历
	if (p) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%c", p->data);
    }
}

int main()
{
	//此处补充代码，调用二叉树的三种遍历函数完成遍历并按要求输出对应遍历序列
	BiTree tree;
	createBiTree(&tree);
	printf("preorder:");
	PreOrder(tree);
    printf("\ninorder:");
    InOrder(tree);
	printf("\npostorder:");
	PostOrder(tree);
	putchar('\n');
	return 0;
}