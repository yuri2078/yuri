#include <cstdint>
#include <yuri.h>
#include <queue>
#include <algorithm>
using namespace std;

class Graph
{
private:
	int vexnum; // 节点个数
	int arcnum; // 边的个数
	vector<int> visited; // 用来报错是否访问过节点
	vector<int> parent; // 用来保存各节点的下一个节点
	vector<vector<int>> G; // 邻接矩阵
	vector<vector<int>> arcInfo; // 用来保存 边的信息
	// 0 ： 起点 1 ： 终点 2 ： 权重
	yuri::Yuri yuri; // 读取文件对象

public:
	Graph()
	{
		vexnum = 9; // 设置节点数

		// 初始化数组
		G = vector<vector<int>>(vexnum, vector<int>(vexnum));
		visited = vector<int>(vexnum);
		parent = vector<int>(vexnum);

		arcInfo = yuri.getData(); // 读取边的信息
		arcnum = arcInfo.size(); // 设置边的数量

		createGraph(); // 构造邻接矩阵
		yuri.outData(true); // 打印边的信息
	}

	// 创建邻接矩阵
	void createGraph()
	{
		int x, y, weight;
		// 遍历每条边 建立邻接矩阵
		for (int i = 0; i < arcnum; i++) {
			x = arcInfo[i][0];
			y = arcInfo[i][1];
			weight = arcInfo[i][2];
			G[x][y] = G[y][x] = weight;
        }
	}

	// 深度优先算法
	// 从一个节点开始，找到和他相连的节点 进行遍历
	// 将找到的节点作为新的节点 重复操作
	void dfs(int v)
	{
		// 将起始节点设置为已经访问
		visited[v] = 1;
        printf("%d 节点 -> ", v);
		for (int i = 0; i < vexnum; i++) {
			// 如果这个节点与根节点相连且没有被访问过就进行访问
            if (G[v][i] && visited[i] == 0) {
                visited[i] = 1;
                dfs(i);  // 递归调用函数进行访问
            }
        }
	}

	// 初始化visited数组
	void initVisited()
	{
		const int size = visited.size();
		for (int i = 0; i < size; i++) {
			visited[i] = 0;
		}
	}

	// 广度优先算法
	// 从初始节点开始遍历 将初始节点添加进队列当中
	// 然后遍历队列里仅有的元素，不算后续添加的元素
	// 将他们未遍历且相连的节点添加进去
	void bfs()
	{
		cout << "\n\nbfs 开始:\n\n";
		initVisited();
		queue<int> que;
		que.push(0); // 先把初始节点添加进去
		visited[0] = 1; // 将初始节点设置为已经访问过了
		while (!que.empty()) {
			const int size = que.size();
			// 循环添加数据
			for (int i = 0; i < size; i++) {
				int k = que.front(); // 获取队头
				que.pop(); // 弹出队头
				cout << "节点 " << k << " -> ";
				// 循环添加未访问的元素
				for (int i = 0; i < vexnum; i++) {
					if (G[k][i] && visited[i] == 0) {
						que.push(i);
						visited[i] = 1; // 已经添加就设置为1
					}
				}
			}
			// 打印回车更加的美观
			cout << "\n";
		}
		cout << "\nbfs 结束:\n\n";
	}

	// 克鲁斯卡尔算法
	// 按权值进行排序，如果这两个节点不能构成回路就添加进去，直到所有节点添加完毕
	void MiniSpanTree_Kruskal()
	{
		cout << "\n\n克鲁斯卡尔算法 ---\n\n";
		// 获取数据并按权值排序
		vector<vector<int>> &arcInfo = yuri.getData();
		sort(arcInfo.begin(), arcInfo.end(), [](vector<int> &x, vector<int> &y) {
			return x[2] < y[2];
		});

		// 循环每条边
		for (int i = 0; i < arcnum; ++i) {
			int x = find(arcInfo[i][0]);
			int y = find(arcInfo[i][1]);
			// 当x y 终点不是同一个时表示他们不是环形
			if (x != y) {
				// 打印节点信息
				cout << "节点 " << arcInfo[i][0] << " ->  节点 "
				     << arcInfo[i][1] << endl;
				// 更新 x 的终点信息
				parent[x] = y;
			}
		}
		cout << "\n克鲁斯卡尔算法结束 ---\n";
	}

	// 普鲁米算法， 先添加一个节点，然后在与这个节点相连的点中找到权值最小的点
	// 再把这个点添加进去，然后遍历原点和添加的点 ， 遍历他们相连的边重复这个操作
	void MiniSpanTree_Prim()
	{
		
		cout << "\n\n普鲁米算法 ---- \n\n";
		vector<int> closest(vexnum); // 保存各个顶点的最小权值的起点
		vector<int> lowcost(vexnum); // 保存各个边的最小权值
		// 保存从 0 出发各点的权值，如果为 0 就先保存为无限大，用于后续更新
		for (int i = 0; i < vexnum; i++) {
			if (G[0][i]) {
				lowcost[i] = G[0][i];
			} else {
				lowcost[i] = INT32_MAX;
			}
			closest[i] = 0; // 一开始他们的起点都是0
		}
		lowcost[0] = 0;
		cout << "找到的点是 : " << 0 << endl; // 先打印一个0
		// 查找最小的权值点
		for (int i = 1; i < vexnum; i++) {
			int min_weight = INT32_MAX, k;
			for (int j = 0; j < vexnum; j++) {
				if (lowcost[j] && lowcost[j] < min_weight) {
					min_weight = lowcost[j];
					k = j;
				}
			}
			lowcost[k] = 0; // 将已经遍历过的点的权值设置为0
			cout << "节点 " << k << " ( " << closest[k] << " -> " << k << " ) \n"; // 打印信息
			// 循环更新最小权值信息
			for (int j = 0; j < vexnum; j++) {
				if (G[k][j] && G[k][j] < lowcost[j]) {
					lowcost[j] = G[k][j]; // 更新权值信息
					closest[j] = k; // 保存产生小权值的 起点信息
				}
			}
		}
		cout << "\n克鲁姆算法结束---\n\n";
	}

	// 查找x 节点的终点
	int find(int x)
	{
		while (parent[x]) {
			x = parent[x];
		}
		// 返回他的终点
		return x;
	}

	// 打印图
	void printGraph()
	{
		cout << "\n打印矩阵 --- \n\n";
		for (int i = 0; i < vexnum; i++) {
			for (int j = 0; j < vexnum; j++) {
				cout.width(4);
				cout << G[i][j];
			}
			cout << endl;
        }
    }
};



int main()
{
	Graph graph;
	graph.printGraph();
	graph.MiniSpanTree_Kruskal();
	graph.MiniSpanTree_Prim();
	graph.dfs(0);
	graph.bfs();
    return 0;
}