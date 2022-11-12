#include <cstdlib>
#include <stack>
#include <iostream>

typedef struct Tree{
	int e;
	Tree* left;
	Tree* right;
}Tree;


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
	std::stack<Tree *> sk;
	sk.push(tree);
	while (!sk.empty()) {
		Tree* t = sk.top();
		sk.pop();
		std::cout << t->e << " ";
		if (t->right) {
			sk.push(t->right);
		}
		if (t->left) {
			sk.push(t->left);
		}
	}
	std::cout << "\n";
}

// 二叉树中序遍历
void inorderTraversal(Tree* tree)
{
	std::stack<Tree *> sk;
	while (tree || !sk.empty()) {
		if (tree) {
			sk.push(tree);
			tree = tree->left;
		} else {
			Tree* t = sk.top();
			sk.pop();
			std::cout << t->e << " ";
			tree = t->right;
		}
	}
	std::cout << "\n";
}

// 二叉树后序遍历
void postorderTraversal(Tree* tree)
{
	std::stack<Tree *> sk;
	sk.push(tree);
	while (!sk.empty()) {
		Tree* t = sk.top();
		sk.pop();
		std::cout << t->e << " ";
		if (t->left) {
			sk.push(t->left);
		}

		if (t->right) {
			sk.push(t->right);
		}
	}
	std::cout << "\n";
}

int main(int argc, const char *argv[])
{
	Tree tree;
	int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	tree.e = array[0];
	createTree(&tree, array, 4, 0);
	preorderTraversal(&tree);
	inorderTraversal(&tree);
	postorderTraversal(&tree);
    return 0;
}