#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
	char val;
	struct Tree* left;
	struct Tree* right;
} Tree;

void createTree(Tree** tree)
{
	char ch = getchar(); // 获取数据
	getchar(); // 吃掉多余的回车
	if (ch == '#') {
		*tree = NULL; // 当他为# 则将自己变成null
		return; // 直接返回不用申请空间
	} else {
		*tree = (Tree*)calloc(1, sizeof(Tree)); // 不是# 就要存储，需要申请空间
		(*tree)->val = ch; // 存储数据
		createTree(&(*tree)->left); // 继续存储左节点
	}
	createTree(&(*tree)->right); // 当左节点处理完毕，处理右节点
}

void preorderTraversal(Tree* tree)
{
	if (tree) {
		printf("%c ", tree->val); // 上来直接处理根节点数据
		preorderTraversal(tree->left); // 递归处理左子树 数据， 只有当左边数据遍历完成才会进行右边数据处理
		preorderTraversal(tree->right);// 递归处理右子树 数据
	}
}

int deep(Tree* tree)
{
	if (tree == NULL) {
		return 0; // 当tree 为null 时，他的深度为0
	} else {
		int left_len = deep(tree->left); // 获取左子树深度
		int right_len = deep(tree->right); // 获取右子树深度
        // 返回他们子树的最大深度 如果节点不是null 深度最小为 1 ，所以需要 + 1
		return left_len > right_len ? left_len + 1 : right_len + 1; 
	}
}

int leaves(Tree* tree)
{
	if (tree == NULL) {
        return 0;
	} else if (tree->right == NULL && tree->left == NULL) {
		return 1; // 当tree 不是null，并且没有孩子结点时他是叶子节点 返回 1
	} else {
		// 返回左子树的叶子节点和右子树的叶子节点
		return leaves(tree->left) + leaves(tree->right); // 返回左右孩子节点的个数
    }
}

int main(void)
{
	Tree *tree;
	createTree(&tree);
	preorderTraversal(tree);
	printf("\n%d\n", deep(tree));
	printf("%d\n",leaves(tree));
    return 0;
}