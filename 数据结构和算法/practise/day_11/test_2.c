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

// 二叉树前序遍历
// 遍历顺序 中 左 右

void preorderTraversal(Tree* tree)
{
	if (tree == NULL) {
		return;
    }
	Tree* stack[100] = {tree}; // 先放一个根节点
	int size = 1; // 设置堆栈容量
	while (size > 0) { //如果堆栈里有东西就一直运行
		Tree* top = stack[--size]; // 获取栈顶部内容并且弹出顶部元素
		if (top != NULL) {

			// 入栈顺序 右 左 中
			if (top->right) {
				stack[size++] = top->right;
			}
			
			if (top->left) {
				stack[size++] = top->left;
			}

			// 在根节点后插入null 标识需要处理的数据
			stack[size++] = top;
			stack[size++] = NULL;
			
		} else { // 遇到null表明这是需要进行处理的数据
			size--; // 先弹出null
			top = stack[size]; // 获取顶部数据
			printf("%c", top->val); // 输出顶部数据
        }
    }
	printf("\n");
}

// 二叉树中序遍历
// 遍历顺序 左 中 右

void inorderTraversal(Tree* tree)
{
	if (tree == NULL) {
		return;
    }
	Tree* stack[100] = {tree}; // 先放一个根节点
	int size = 1; // 设置堆栈容量
	while (size > 0) { //如果堆栈里有东西就一直运行
		Tree* top = stack[--size]; // 获取栈顶部内容并且弹出顶部元素
		if (top != NULL) {

            // 入栈顺序 右 中 左
			if (top->right) {
				stack[size++] = top->right;
			}

			// 在根节点后插入null 标识需要处理的数据
			stack[size++] = top;
			stack[size++] = NULL;
			
			if (top->left) {
				stack[size++] = top->left;
			}
			
		} else { // 遇到null表明这是需要进行处理的数据
			size--; // 先弹出null
			top = stack[size]; // 获取顶部数据
			printf("%c", top->val); // 输出顶部数据
        }
    }
	printf("\n");
}

// 二叉树后序遍历
// 遍历顺序 左 右 中

void postorderTraversal(Tree* tree)
{
	if (tree == NULL) {
		return;
    }
	Tree* stack[100] = {tree}; // 先放一个根节点
	int size = 1; // 设置堆栈容量
	while (size > 0) { //如果堆栈里有东西就一直运行
		Tree* top = stack[--size]; // 获取栈顶部内容并且弹出顶部元素
		if (top != NULL) {
			// 在根节点后插入null 标识需要处理的数据
			stack[size++] = top;
			stack[size++] = NULL;

			// 入栈顺序 中 右 左
			if (top->right) {
				stack[size++] = top->right;
			}
			
			if (top->left) {
				stack[size++] = top->left;
			}
			
		} else { // 遇到null表明这是需要进行处理的数据
			size--; // 先弹出null
			top = stack[size]; // 获取顶部数据
			printf("%c", top->val); // 输出顶部数据
        }
    }
	printf("\n");
}

int main(void)
{
	Tree *tree;
	createTree(&tree); // 建立二叉树
	preorderTraversal(tree); // 前序
	inorderTraversal(tree); // 中序
	postorderTraversal(tree); // 后序
    return 0;
}