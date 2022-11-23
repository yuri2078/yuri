#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Huffman树的节点类
typedef struct Node {
	char value;            //结点的字符值
	int weight;            //结点字符出现的频度
	Node *lchild, *rchild; //结点的左右孩子
} Node;

//自定义排序规则，即以vector中node结点weight值升序排序
bool ComNode(Node* p, Node* q) { return p->weight < q->weight; }

//构造Huffman树，返回根结点指针
Node* BuildHuffmanTree(vector<Node*> vctNode)
{
	while (vctNode.size() > 1)
	// vctNode森林中树个数大于1时循环进行合并
	{
		sort(vctNode.begin(), vctNode.end(), ComNode);
		// //依频度高低对森林中的树进行升序排序
		Node* first = vctNode[0];
		// //取排完序后vctNode森林中频度最小的树根
		Node* second = vctNode[1];
		// //取排完序后vctNode森林中频度第二小的树根
		Node* merge = new Node;
		//合并上面两个树
		merge->weight = first->weight + second->weight;
		merge->lchild = first;
		merge->rchild = second;
		vector<Node*>::iterator iter;
		iter = vctNode.erase(vctNode.begin(), vctNode.begin() + 2);
		// //从vctNode森林中删除上诉频度最小的两个节点first和second
		vctNode.push_back(merge); //向vctNode森林中添加合并后的merge树
	}
	return vctNode[0]; //返回构造好的根节点
}

//用回溯法来打印编码
void PrintHuffman(Node* node, vector<int> vctchar)
{
	if (node->lchild == NULL &&
	    node->rchild == NULL) { //若走到叶子节点，则迭代打印vctchar中存的编码
		cout << node->value << ": ";
		for (vector<int>::iterator iter = vctchar.begin();
		     iter != vctchar.end(); iter++)
			cout << *iter;
		cout << endl;
		return;
	} else {
		vctchar.push_back(1); //遇到左子树时给vctchar中加一个1
		PrintHuffman(node->lchild, vctchar);
		vctchar.pop_back();
		//回溯，删除刚刚加进去的1
		vctchar.push_back(0);
		////遇到左子树时给vctchar中加一个0
		PrintHuffman(node->rchild, vctchar);
		vctchar.pop_back();
		////回溯，删除刚刚加进去的0
	}
}

int main()
{
	cout << "************ Huffman编码问题 ***************" << endl;
	cout << "请输入要编码的字符,并以空格隔开（个数任意）：" << endl;
	vector<Node*> vctNode; //存放Node结点的vector容器vctNode
	char ch;
	////临时存放控制台输入的字符
	while ((ch = getchar()) != '\n') {
		if (ch == ' ')
			continue;
		////遇到空格时跳过，即没输入一个字符空一格空格
		Node* temp = new Node;
		temp->value = ch;
		temp->lchild = temp->rchild = NULL;
		vctNode.push_back(temp);
		////将新的节点插入到容器vctNode中 }
		cout << endl << "请输入每个字符对应的频度，并以空格隔开：" << endl;
		for (int i = 0; i < vctNode.size(); i++)
			cin >> vctNode[i]->weight;
		Node* root = BuildHuffmanTree(vctNode);
		////构造Huffman树，将返回的树根赋给 root
		vector<int> vctchar;
		cout << endl << "对应的Huffman编码如下：" << endl;
		PrintHuffman(root, vctchar);
	}
}