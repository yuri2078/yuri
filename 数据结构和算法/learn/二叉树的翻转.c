#include <stdio.h>
#include <stdlib.h>

// typedef struct Tree Tree;
typedef struct Tree{
	int val;
	struct Tree* left;
	struct Tree* right;
}Tree;

// 顺序存储二叉树 转 链式存储 满二叉树

void createTree(Tree* tree, int* array, int size, int k)
{
	tree->left = (Tree*)calloc(1, sizeof(Tree));
	tree->right = (Tree*)calloc(1, sizeof(Tree));

	tree->left->val = array[k * 2 + 1];
	tree->right->val = array[k * 2 + 2];
	// printf("size : %d k : %d head : %d left : %d right : %d\n",6 - size,
	// k,array[k],  array[k * 2 + 1], array[k * 2 + 2]);
	if (size > 2) {
		createTree(tree->left, array, size - 1, k * 2 + 1);
		createTree(tree->right, array, size - 1, k * 2 + 2);
	}
}

// 二叉树前序遍历
// 遍历顺序 中 左 右
void preorderTraversal(Tree* tree)
{
	if (tree) {
		printf("%d ", tree->val); // 上来直接处理根节点数据
		preorderTraversal(tree->left); // 递归处理左子树 数据，
		// 只有当左边数据遍历完成才会进行右边数据处理
		preorderTraversal(tree->right); // 递归处理右子树 数据
	}
}

void inverseTree(Tree* tree)
{
	if (tree) {
		
    }
}

int main(int argc, const char* argv[])
{
	Tree tree;
	int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	tree.val = array[0];
	createTree(&tree, array, 4, 0);
	preorderTraversal(&tree);

	return 0;
}