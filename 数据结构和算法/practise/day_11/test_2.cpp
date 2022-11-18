#include <stack>
#include <iostream>

typedef struct Tree{
	char val;
	Tree* left;
	Tree* right;
}Tree;

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
			std::cout << tree->val; // 存储数据
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
			std::cout << tree->val; // 存储数据
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
			std::cout << tree->val; // 存储数据
			sk.pop(); // 处理完数据直接弹出
		}
	}
	std::cout << "\n";
}

int main(int argc, const char *argv[])
{
	Tree *tree;
	createTree(&tree);
	preorderTraversal(tree);
	inorderTraversal(tree);
	postorderTraversal(tree);
    return 0;
}