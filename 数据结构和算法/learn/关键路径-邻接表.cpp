#include <queue>
#include <yuri.h>
using namespace std;

typedef struct EdgeNode {
	int adjvex; // 结点序号
	int weight; // 起点结点 到该结点的权重
	struct EdgeNode* next;
	EdgeNode()
	{
		adjvex = 0;
		weight = 0;
		next = nullptr;
	}

} EdgeNode;

typedef struct VNode {
	int weight;
	char data;      // 结点信息
	int in;         // 结点入度
	EdgeNode* link; // 邻接表
	VNode()
	{
		weight = 0;
		data = 'a';
		in = 0;
		link = nullptr;
	}
} VNode;

class Graph
{
private:
	int vexnum;          // 节点个数
	int arcnum;          // 边的个数
	vector<int> topSort; // 拓扑排序结果
	vector<VNode> graph; //存储邻接表
	vector<VNode> path;  //存储路径
	vector<vector<int>>
	    arcInfo; // 用来保存 边的信息 0 ： 起点 1 ： 终点 2 ： 权重
	yuri::Yuri yuri; // 读取文件对象

public:
	Graph()
	{
		vexnum = 9; // 设置节点数

		// 初始化数组
		graph = vector<VNode>(vexnum);
		path = vector<VNode>(vexnum);
		arcInfo = yuri.getData(); // 读取边的信息
		arcnum = arcInfo.size();  // 设置边的数量
		createGraph();            // 构造邻接表
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
			node->next = nullptr;
			node->adjvex = y;
			node->weight = weight;
			if (graph[x].link == nullptr) {
				graph[x].link = node;
			} else {
				EdgeNode* head = graph[x].link;
				while (head->next) {
					head = head->next;
				}
				head->next = node;
			}
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
				cout << "( " << i << " -> " << head->adjvex << " ) -> 权重  "
				     << head->weight << endl;
				head = head->next;
			}
		}
		cout << "\n邻接表打印结束 --- \n\n";
	}

	// 获取拓扑排序
	void GetTopSort()
	{
		if (topSort.size()) {
			return;
		}
		queue<int> que;
		// 先将所有入度为 0 的结点添加进去
		for (int i = 0; i < vexnum; i++) {
			if (graph[i].in == 0) {
				que.push(i);
			}
		}

		while (!que.empty()) {
			int k = que.front();  // 获取队头
			que.pop();            // 弹出队头
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

	// 求出路径然后求出各条路径的权值总和，在根据总和最大输出关键路近
	// 一条路径权值最大的路径就是关键路径
	void Critical_path()
	{
		int max_weight = 0;
		GetTopSort(); // 先获取拓扑排序结果

		// 先建立第一条路近，该路径只有最后一个结点
		EdgeNode* node = new EdgeNode;
		node->adjvex = topSort[vexnum - 1];
		node->weight = 0;
		path[0].link = node;

		int len = 1; // 路径个数
		// 一共需要循环添加所有结点
		for (int i = vexnum - 2; i >= 0; i--) {
			// 倒序获取拓扑排序结果
			// 后续插入的而结点都是以这个点为起点
			int k = topSort[i]; 
		
			EdgeNode* head = graph[k].link;
			// 查找与该结点相连的另一个结点
			while (head) {
				// 遍历所有路径 因为后续len 会变化，所以需要提前保存len 的值
				int size = len;
				for (int j = 0; j < size; j++) {
					// 如果以k 为 起点的弧 的 终点等于 该路径的起点，直接添加就行了
					if (head->adjvex == path[j].link->adjvex) {
						// 直接添加该结点为 当前路径的新 head
						// 因为是倒序添加，所有每次添加都是添加的头结点
						EdgeNode* node = new EdgeNode;
						node->adjvex = k;
						node->weight = head->weight;
						node->next = path[j].link; // 将新结点的next 指向 原来的head
						path[j].link = node; // 将head 指向 新结点
					} else {
						// 如果他的终点不等于当前路径的起点
						// 就从当前路径的下一个结点开始查找
						// 如果找到相等的，就新建一个路径，该路径的头就是新的结点
						// 新结点的next 要指向找到该结点的位置
						EdgeNode* begin = path[j].link->next;
						while (begin) {
							if (begin->adjvex == head->adjvex) {
								EdgeNode* node = new EdgeNode;
								node->adjvex = k;
								node->weight = head->weight; // head 保存的才是真正的权值
								path[len++].link = node;
								// 将后续结点全部添加到新路径头后面
								while (begin) {
									EdgeNode* back = new EdgeNode;
									back->adjvex = begin->adjvex;
									back->weight = begin->weight;
									node->next = back;
									node = node->next;
									begin = begin->next;
								}
								break;
							}
							begin = begin->next;
						}
					}
				}
				head = head->next;
			}
		}
		// 遍历所有路径
		cout << "\n所有路径 : ---- \n\n";
		for (int i = 0; i < len; i++) {
			EdgeNode* head = path[i].link;
			while (head) {
				path[i].weight += head->weight; // 计算所有路径权重和
				cout << "结点 -> " << head->adjvex << "  ";
				head = head->next;
			}
			max_weight = max(max_weight, path[i].weight); // 查找最大权值
			cout << "   weight  :  " << path[i].weight << endl;
		}

		cout << "\n关键路径 : ---- " << "  weigth : " <<  max_weight << "\n\n";
		for (int i = 0; i < len; i++) {
			// 打印权值和最大权值相等的路径
			if (max_weight != path[i].weight) {
				continue;
			}
			EdgeNode* head = path[i].link;
			while (head) {
				cout << "结点 -> " << head->adjvex << "  ";
				head = head->next;
			}
			cout << "   weight  :  " << path[i].weight << endl;
		}
	}

	// 析构函数，释放申请的内存
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

		for (int i = 0; i < vexnum; i++) {
			EdgeNode* head = path[i].link;
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
	graph.Critical_path();
	return 0;
}