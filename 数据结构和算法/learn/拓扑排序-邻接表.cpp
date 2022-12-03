#include <queue>
#include <yuri.h>
#include <queue>
using namespace std;

typedef struct EdgeNode {
	int adjvex; // 结点序号
	int weight; // 起点结点 到该结点的权重
	struct EdgeNode* next = nullptr;
} EdgeNode;

typedef struct VNode {
	char data; // 结点信息
	int in; // 结点入度
	EdgeNode* link = nullptr; // 邻接表
} VNode;

class Graph
{
private:
	int vexnum;          // 节点个数
	int arcnum;          // 边的个数
	vector<int> topSort; // 拓扑排序结果
	vector<int> visited; // 用来报错是否访问过节点
	vector<VNode> graph; //存储邻接表
	vector<vector<int>> arcInfo; // 用来保存 边的信息 0 ： 起点 1 ： 终点 2 ： 权重
	yuri::Yuri yuri; // 读取文件对象

public:
	Graph()
	{
		vexnum = 9; // 设置节点数

		// 初始化数组
		visited = vector<int>(vexnum);
		graph = vector<VNode>(vexnum);
		arcInfo = yuri.getData(); // 读取边的信息
		arcnum = arcInfo.size();  // 设置边的数量
		createGraph(); // 构造邻接表
		yuri.outData(true);       // 打印边的信息
	}

	// 创建邻接表
	void createGraph()
	{
		int x, y, weight;
		// 遍历每条边 建立邻接表
		for (int i = 0; i < arcnum; i++) {
			x = arcInfo[i][0];
			y = arcInfo[i][1];
			weight = arcInfo[i][2];

			EdgeNode* node = new EdgeNode;
			node->next = graph[x].link;
			node->adjvex = y;
			node->weight = weight;
			graph[x].link = node;

			graph[y].in++; // 入度加一
		}
	}

	// 打印图
	void printGraph()
	{
		cout << "\n打印邻接表 --- \n\n";
		for (int i = 0; i < vexnum; i++) {
			cout << endl << i << " 结点入度 : " << graph[i].in << " --- \n";
			EdgeNode* head = graph[i].link;
			while (head) {
				cout << "( " << i << " -> " << head->adjvex << " ) -> 权重  " << head->weight << endl;
				head = head->next;
			}
		}
		cout << "\n邻接表打印结束 --- \n\n";
	}

	void GetTopSort()
	{
		queue<int> que;
		// 先将所有入度为 0 的结点添加进去
		for (int i = 0; i < vexnum; i++) {
			if (graph[i].in == 0) {
				que.push(i);
			}
		}

		while (!que.empty()) {
			int k = que.front(); // 获取队头
			que.pop(); // 弹出队头
			topSort.push_back(k); // 将队头添加进拓扑排序数组

			// 删除以该节点为起点的弧
			EdgeNode* head = graph[k].link;
			while (head) {
				graph[head->adjvex].in--; // 将所有以该节点为弧的结点入度减一

				// 如果入度为 0 就添加进去
				if (graph[head->adjvex].in == 0) {
					que.push(head->adjvex);
				}
				head = head->next;
			}
		}

		cout << "拓扑排序 --- \n\n";
		for (int x: topSort) {
			cout << "节点 -> " << x << "  ";
		}
		cout << "\n\n拓扑排序结束 --- \n";
	}

	~Graph()
	{
		for (int i = 0; i < vexnum; i++) {
			EdgeNode* head = graph[i].link;
			while (head) {
				EdgeNode* temp = head;
				head = head->next;
				delete temp;
			}
		}
	}
};

int main()
{
	Graph graph;
	graph.printGraph();
	graph.GetTopSort();
	return 0;
}