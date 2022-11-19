#include <iostream>
#include <queue>
#include <stack>
#include <vector>

typedef struct Tree {
	int val;
	Tree* left;
	Tree* right;
} Tree;

// 顺序存储二叉树 转 链式存储 满二叉树

void createTree(Tree* tree, int* array, int size, int k)
{
	tree->left = new Tree;
	tree->right = new Tree;

	tree->left->val = array[k * 2 + 1];
	tree->right->val = array[k * 2 + 2];
	// printf("size : %d k : %d head : %d left : %d right : %d\n",6 - size,
	// k,array[k],  array[k * 2 + 1], array[k * 2 + 2]);
	if (size > 2) {
		createTree(tree->left, array, size - 1, k * 2 + 1);
		createTree(tree->right, array, size - 1, k * 2 + 2);
	}
}

// 递归方法
Tree* invertTree(Tree* root)
{
	// 如果节点为null 则不处理
	if (root == nullptr) {
		return nullptr;
	}

	// 交换左右节点
	Tree* node = root->left;
	root->left = root->right;
	root->right = node;

	// 递归处理左右节点
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

// 迭代方法
Tree* invertTree_stack(Tree* root)
{
	// 如果节点为null 则不处理
	if (root == nullptr) {
		return nullptr;
	}

	std::stack<Tree*> stack;
	stack.push(root);
	while (!stack.empty()) {
		Tree* top = stack.top();
		stack.pop();
		Tree* node = top->left;
		top->left = top->right;
		top->right = node;

		if (top->left) {
			stack.push(top->left);
		}

		if (top->right) {
			stack.push(top->right);
		}
	}

	return root;
}

int main(int argc, const char* argv[])
{
	Tree tree;
	int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	tree.val = array[0];
	createTree(&tree, array, 4, 0);
	invertTree(&tree);
	return 0;
}