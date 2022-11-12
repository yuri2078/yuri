#include <stdlib.h>
#include <stdio.h>

typedef struct Tree Tree;

struct Tree{
	int e;
	Tree* left;
	Tree* right;
};


// 顺序存储二叉树 转 链式存储 满二叉树

void createTree(Tree* tree, int *array, int size, int k)
{
	tree->left = (Tree *)calloc(1, sizeof(Tree));
	tree->right = (Tree*)calloc(1, sizeof(Tree));

	tree->left->e = array[k * 2 + 1];
	tree->right->e = array[k * 2 + 2];
	// printf("size : %d k : %d head : %d left : %d right : %d\n",6 - size, k,array[k],  array[k * 2 + 1], array[k * 2 + 2]);
	if (size > 2) {
		createTree(tree->left, array, size - 1, k * 2 + 1);
		createTree(tree->right, array, size - 1, k * 2 + 2);
	}
}

// 二叉树前序遍历
void preorderTraversal(Tree* tree)
{
	if (tree) {
		printf("%d ", tree->e);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}

// 二叉树中序遍历
void inorderTraversal(Tree* tree)
{
	if (tree) {
		inorderTraversal(tree->left);
		printf("%d ", tree->e);
		inorderTraversal(tree->right);
	}
}

// 二叉树后序遍历
void postorderTraversal(Tree* tree)
{
	if (tree) {
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d ", tree->e);
	}
}

int main(int argc, const char *argv[])
{
	Tree tree;
	int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	tree.e = array[0];
	createTree(&tree, array, 4, 0);
	preorderTraversal(&tree);
	putchar('\n');
	inorderTraversal(&tree);
	putchar('\n');
	postorderTraversal(&tree);
	putchar('\n');
    return 0;
}