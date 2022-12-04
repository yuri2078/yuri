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
		vexnum = 6; // 设置节点数

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

	void dijkstra(int k)
	{
		cout << "\ndijkstra 算法 ---- \n\n";
		int set = 1 << k; // 初始化set 
		vector<int> dist(vexnum, INT32_MAX); // 初始化最短路径
		dist[k] = 0; // 将自己到 自己设置为 0 
		while (set != (1 << vexnum) - 1) {
			int max_val = INT32_MAX, pos;
			for (int i = 0; i < vexnum; i++) {
				// 更新最短路径信息
				if (G[k][i] && G[k][i] + dist[k] < dist[i]) {
					dist[i] = dist[k] + G[k][i];
				}
				// 查找除了已经添加的结点的最小值
				if ((set & (1 << i)) == 0 && dist[i] < max_val) {
					max_val = dist[i];
					pos = i;
				}
			}
			k = pos; // 更新最小结点
			set = set | (1 << k); // 将已经遍历过的结点保存
		}

		// 打印结果
		for (int i = 0; i < vexnum; i++) {
			cout << "初始结点 到 结点 " << i << " ->  " << dist[i] << endl;
		}
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
	graph.dijkstra(1);

    return 0;
}