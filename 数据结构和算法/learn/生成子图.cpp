#include <cstdint>
#include <iostream>
#include <yuri.h>
#include <queue>
#include <algorithm>
using namespace std;

class Graph
{
private:
	int vexnum;
	int arcnum;
	vector<int> visited;
	vector<int> parent;
	vector<vector<int>> G;
	vector<vector<int>> arcInfo;
	yuri::Yuri yuri;

public:
	Graph()
	{
		vexnum = 9; 
		G = vector<vector<int>>(vexnum, vector<int>(vexnum));
		visited = vector<int>(vexnum);
		parent = vector<int>(vexnum);
		arcInfo = yuri.getData();
		arcnum = arcInfo.size();
		yuri.outData(true);
	}

	void createGraph()
	{
		int x, y, weight;
		for (int i = 0; i < arcnum; i++) {
			x = arcInfo[i][0];
			y = arcInfo[i][1];
			weight = arcInfo[i][2];
			G[x][y] = G[y][x] = weight;
        }
	}

	void dfs(int v)
	{
		visited[v] = 1;
        printf("%d 节点 -> ", v);
        for (int i = 0; i < vexnum; i++) {
            if (G[v][i] && visited[i] == 0) {
                visited[i] = 1;
                dfs(i); 
            }
        }
	}

	void bfs()
	{
		cout << "\nbfs 开始:\n";
		visited = vector<int>(vexnum);
		queue<int> que;
		que.push(0);
		while (!que.empty()) {
			const int size = que.size();
			for (int i = 0; i < size; i++) {
				int k = que.front();
				que.pop();
				visited[k] = 1;
				cout << "节点 " << k << " -> ";
				for (int i = 0; i < vexnum; i++) {
					if (G[k][i] && visited[i] == 0) {
						que.push(i);
					}
				}
			}
			cout << "\n";
		}
		cout << "bfs 结束:\n";
	}

	// 克鲁斯卡尔算法
	void MiniSpanTree_Kruskal()
	{
		cout << "克鲁斯卡尔算法:\n";
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
	}

	void MiniSpanTree_Prim()
	{
		vector<int> adjvex;
		adjvex.push_back(0); // 先将 0 节点添加进去
		cout << "普鲁米算法 ： \n找到的点是 : " << 0 << endl;
		// 一共需要查找 n - 1个节点
		for (int i = 1; i < vexnum; i++) {
			int min_weight = INT32_MAX, min_k = 0;
			// 遍历已经添加的节点找到最小权值边
			for (int k: adjvex) {
				// 遍历每个边
				for (int j = 0; j < vexnum; j++) {
					label:
					// 如果是已经添加的节点的边 就跳过
					for (int x: adjvex) {
						if (x == j) {
							j++;
							goto label;
						}
					}
					// 保存最小权值的节点
					if (G[k][j] && G[k][j] < min_weight) {
						min_weight = G[k][j];
						min_k = j;
					}
				}
			}
			// 打印找到的最小节点
			cout << "找到的点是 : " << min_k << endl;
			adjvex.push_back(min_k);
		}
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
	graph.createGraph();
	graph.MiniSpanTree_Kruskal();
	graph.MiniSpanTree_Prim();
    return 0;
}