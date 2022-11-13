#include <vector>
#include <algorithm>
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
// 入栈顺序 右 左  中间接节点直接处理就行
void preorderTraversal(Tree* tree)
{
	std::stack<Tree *> sk;
	sk.push(tree); // 先将根节点入栈
	while (!sk.empty()) { 
		Tree* t = sk.top(); // 获取堆栈顶部数据
		std::cout << t->e << " "; // 存储顶部数据
		sk.pop();                 // 弹出顶部数据

		// 先将 右子树入栈
		if (t->right) {
			sk.push(t->right);
		}

		// 将 左子树入栈
		if (t->left) {
			sk.push(t->left);
		}
	}
	std::cout << "\n";
}

// 二叉树中序遍历
// 遍历树需 左 中 右
// 入栈顺序 右 左 当遍历到左子树结束才处理右边数据
void inorderTraversal(Tree* tree)
{
	std::stack<Tree*> sk;
	sk.push(tree); // 根节点作为第一个左子树根节点入栈
	while (!sk.empty()) {
		if (tree) { // 如果没到左子树结束就一直遍历下去
			sk.push(tree);
			tree = tree->left;
		} else {
			// 当 tree 为null 时，说明左边遍历结束 可以开始处理数据
			Tree* t = sk.top(); // 先获取最后一个存入的节点
			std::cout << t->e << " "; // 获取 数据
			sk.pop(); // 将他弹出
			tree = t->right;
			// 将tree 重新指向刚获取的数据的右子树
			// 如果 t 是左子树最后一个节点 t->right 为空 会先处理 t的父节点
			// 如果 t 不是最后一个节点 t->right 就是他的兄弟节点 这样会在处理完左节点 中节点后 开始处理 右节点
		}
	}
	std::cout << "\n";
}

// 二叉树后序遍历
// 遍历顺序 左 右 中
// 后序遍历就是将先序遍历 左 右 交换位置 然后 反转数据输出的结果
void postorderTraversal(Tree* tree)
{
	std::vector<int> result;
	std::stack<Tree *> sk;
	sk.push(tree); // 先入栈根节点
	while (!sk.empty()) {
		Tree* t = sk.top(); // 获取堆栈顶部数据
		result.push_back(t->e); //存入数据
		sk.pop();               // 弹出顶部数据

		// 先处入栈左节点 后处理左节点 反转后先输出左节点
		if (t->left) {
			sk.push(t->left);
		}

		if (t->right) {
			sk.push(t->right);
		}
	}
	std::reverse(result.begin(), result.end()); //反转数据
	for (int x : result) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	
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