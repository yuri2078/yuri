#include <algorithm>
#include <iostream>
#include <queue>
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

void lecvelOrder(Tree* tree)
{
	if (tree == nullptr) {
		return;
	}
	std::queue<Tree*> queue;
	queue.push(tree); // 先将根节点入队
	while (!queue.empty()) {
		int size = queue.size(); // 队列里有几个成员 就说明 当前层有 多少个节点
		for (int i = 0; i < size; i++) {
			Tree* t = queue.front();    // 获取 队头
			std::cout << t->val << " "; // 打印数据
			queue.pop();                // 将打印的数据弹出

			// 将队头的左 右 子节点放入队列中
			if (t->left) {
				queue.push(t->left);
			}
			if (t->right) {
				queue.push(t->right);
			}
		}
		std::cout << std::endl;
	}
}

int main(int argc, const char* argv[])
{
	Tree tree;
	int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	tree.val = array[0];
	createTree(&tree, array, 4, 0);
	lecvelOrder(&tree);
	return 0;
}