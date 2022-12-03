#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Tree{
	int val;
	Tree* left;
	Tree* right;
	Tree(int x)
	{
		val = x;
		left = nullptr;
		right = nullptr;
	}
	Tree()
	{
		val = 0;
		left = nullptr;
		right = nullptr;
    }
} Tree;

Tree* createTree(vector<Tree*>& v)
{
	if (v.size() == 0) {
		return nullptr;
    }
	// 当只有一个节点时，这就是根节点
	while (v.size() != 1) {
		// 先将权值进行排序 （从大到小）
		sort(v.begin(), v.end(), [](Tree* tree_1, Tree* tree_2) {
			return tree_1->val > tree_2->val;
		});

		Tree* tree = new Tree; // 新建根节点
		tree->left = v.back(); // 设置左节点为权值最小的
		v.pop_back(); // 弹出权值最小的节点
		tree->right = v.back(); // 设置右节点是权值最小的 （ 上一个最小的已经被弹出）
		tree->val = tree->left->val + tree->right->val; // 设置节点的val 为左右节点的和
		v.pop_back(); // 弹出最小节点
		v.push_back(tree); // 将生成的新节点重新插入容器
    }
	
	return v.back(); // 返回他的根节点。
}


int depth(Tree* tree)
{
	if (tree == nullptr) {
		return 0;
	}
	return 1 + max(depth(tree->left), depth(tree->right));
}

// 层序遍历结果
void lecvelOrder(Tree* tree)
{
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

// 打印哈夫曼树编码
void house(Tree* tree, vector<int> val)
{
	if (tree == nullptr) {
		return;
	}
	// 当遇到叶子节点开始打印数据
	if (tree->left == tree->right && tree->right == nullptr) {
		cout << tree->val << "  :  ";
		// 遍历存储好的编码
		for (int x : val) {
			cout << x << " ";
		}
		cout << endl;
	} else {
		// 先给左子数的容器传入一个 0
		val.push_back(0);
		house(tree->left, val); // 带着有 0 的容器递归调用函数
		val.pop_back(); // 弹出出刚刚传入的0
		
		// 先给右子数的容器传入一个 1
		val.push_back(1);
		house(tree->right, val); // 带着有 1 的容器递归调用函数
		val.pop_back();// 弹出出刚刚传入的1
	}
}

        
int main()
{
	vector<Tree*> v;
	vector<int> val;
	v.push_back(new Tree(2));
	v.push_back(new Tree(3));
	v.push_back(new Tree(6));
	v.push_back(new Tree(8));
	v.push_back(new Tree(9));
	Tree * tree = createTree(v);
	lecvelOrder(tree);
	house(tree,val);
    return 0;
}