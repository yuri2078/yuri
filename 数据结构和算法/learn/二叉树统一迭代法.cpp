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
	tree->left = new Tree;
	tree->right = new Tree;

	tree->left->e = array[k * 2 + 1];
	tree->right->e = array[k * 2 + 2];
	// printf("size : %d k : %d head : %d left : %d right : %d\n",6 - size, k,array[k],  array[k * 2 + 1], array[k * 2 + 2]);
	if (size > 2) {
		createTree(tree->left, array, size - 1, k * 2 + 1);
		createTree(tree->right, array, size - 1, k * 2 + 2);
	}
}

// 二叉树前序遍历
// 遍历顺序 中 左 右
// 入栈顺序 右 左 中
void preorderTraversal(Tree* tree)
{
	std::stack<Tree *> sk;
	sk.push(tree); // 先存入根节点
	while (!sk.empty()) {
		tree = sk.top(); // 先获取栈顶数据
		if (tree) { // 如果不为null，说明还没到需要处理的地方
			sk.pop(); // 弹出数据，重新入栈

			// 插入右节点
			if (tree->right) {
				sk.push(tree->right);
			}

			// 插入左节点
			if (tree->left) {
				sk.push(tree->left);
			}

			sk.push(tree); // 插入根节点
			sk.push(nullptr); // 插入需要处理标识符 null

		} else {
			// 如果获取到了 就说明遇到需要处理的节点了
			sk.pop(); // 先弹出null
			tree = sk.top(); // 获取null前面需要处理的数据
			std::cout << tree->e << " "; // 存储数据
			sk.pop(); // 处理完数据直接弹出
		}
	}
	std::cout << "\n";
}

// 二叉树中序遍历
// 遍历顺序 左 中 右
// 入栈顺序 右 中 左
void inorderTraversal(Tree* tree)
{
	std::stack<Tree *> sk;
	sk.push(tree); // 先存入根节点
	while (!sk.empty()) {
		tree = sk.top(); // 先获取栈顶数据
		if (tree) { // 如果不为null，说明还没到需要处理的地方
			sk.pop(); // 弹出数据，重新入栈

			// 插入右节点
			if (tree->right) {
				sk.push(tree->right);
			}

			sk.push(tree); // 插入根节点
			sk.push(nullptr); // 插入需要处理标识符 null

			// 插入左节点
			if (tree->left) {
				sk.push(tree->left);
			}
		} else {
			// 如果获取到了 就说明遇到需要处理的节点了
			sk.pop(); // 先弹出null
			tree = sk.top(); // 获取null前面需要处理的数据
			std::cout << tree->e << " "; // 存储数据
			sk.pop(); // 处理完数据直接弹出
		}
	}
	std::cout << "\n";
}

// 二叉树后序遍历
// 遍历顺序 左 右 中
// 入栈顺序 中 右 左
void postorderTraversal(Tree* tree)
{
	std::stack<Tree *> sk;
	sk.push(tree); // 先存入根节点
	while (!sk.empty()) {
		tree = sk.top(); // 先获取栈顶数据
		if (tree) { // 如果不为null，说明还没到需要处理的地方
			sk.pop(); // 弹出数据，重新入栈

			sk.push(tree); // 插入根节点
			sk.push(nullptr); // 插入需要处理标识符 null

			// 插入右节点
			if (tree->right) {
				sk.push(tree->right);
			}

			// 插入左节点
			if (tree->left) {
				sk.push(tree->left);
			}
		} else {
			// 如果获取到了 就说明遇到需要处理的节点了
			sk.pop(); // 先弹出null
			tree = sk.top(); // 获取null前面需要处理的数据
			std::cout << tree->e << " "; // 存储数据
			sk.pop(); // 处理完数据直接弹出
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