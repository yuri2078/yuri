#include <cstdint>
#include <yuri.h>
#include <queue>
#include <algorithm>
using namespace std;

// 基于关键活动识别关键路径的方法
// 我们认为事件中最早开始和最晚开始的事件是关键路径（关键活动）
// 这是基于邻接矩阵 和 关键活动 的关键路径算法
class Graph
{
private:
	int vexnum; // 节点个数
	int arcnum; // 边的个数
	vector<vector<int>> G; // 邻接矩阵
	vector<int> topSort; // 存储拓扑排序
	vector<int> vex_in; // 存储结点入度
	vector<vector<int>> arcInfo; // 用来保存 边的信息  0 ： 起点 1 ： 终点 2 ： 权重
	yuri::Yuri yuri;             // 读取文件对象

	vector<int> v_e; // ve[i] = 结点 i 最早开始时间
	vector<int> v_l; // vl[i] = 结点 i 最迟开始时间
	vector<int> a_e; // a_e[i] = 事件 i 的最早开始时间
	vector<int> a_l; // a_e[i] = 事件 i 的最早开始时间

public:
	Graph()
	{
		vexnum = 6; // 设置节点数

		// 初始化数组
		G = vector<vector<int>>(vexnum, vector<int>(vexnum));
		arcInfo = yuri.getData(); // 读取边的信息
		arcnum = arcInfo.size();  // 设置边的数量

		vex_in = vector<int>(vexnum); 
		v_e = vector<int>(vexnum);
		v_l = vector<int>(vexnum, INT32_MAX);  // 求最晚开始时间 需要初始化为 int32_max
		a_e = vector<int>(arcnum); 
		a_l = vector<int>(arcnum); 
		

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
			G[x][y] = weight;
			vex_in[y]++;
        }
	}

	// 获取拓扑排序的结果
	void GetTopSort()
	{
		if (!topSort.empty()) {
			return;
		}
		queue<int> que;
		// 先将所有入度为 0 的结点添加进去
		for (int i = 0; i < vexnum; i++) {
			if (vex_in[i] == 0) {
				que.push(i);
			}
		}

		while (!que.empty()) {
			int k = que.front(); // 获取队头
			que.pop(); // 弹出队头
			topSort.push_back(k); // 将队头添加进拓扑排序数组

			// 删除以该节点为起点的弧
			for (int i = 0; i < vexnum; i++) {
				if (G[k][i]) {
					vex_in[i]--;
					if (vex_in[i] == 0) {
						que.push(i);
					}
				}
			}
		}

		cout << "拓扑排序 --- \n\n";
		for (int x: topSort) {
			cout << "节点 -> " << x << "  ";
		}
		cout << "\n\n拓扑排序结束 --- \n";
	}

	// 获取结点的最早和最晚开始时间
	void GetEarliest_Latest()
	{
		GetTopSort(); // 先获取突破排序的结果sudo pacman-key --lsign-key CB222E7EBC11D682AAC8B317A4A0D73114FDE6FC
		cout << "\n打印结点最早和最晚开始时间 --- \n\n";
		for (int i = 0; i < vexnum; i++) {
			// 根据拓扑排序的结果差早结点最早开始时间
			// 因为拓扑排序的结果就是每个结点的前驱和后继，也就是说后面的结点必须等前面的完成了才能继续
			// 用来求最早开始时间正好！ 每个结点的最早开始时间就是以他为终点的权重的最大值
			// 因为他要开始那么所以以他为终点弧都必须结束，要以最大值为主

			// v_e[i]  都以被初始化为 0 
			int k = topSort[i]; 
			for (int j = 0; j < vexnum; j++) {
				if (G[k][j]) {
					int temp = G[k][j] + v_e[k];
					v_e[j] = max(temp, v_e[j]);
				}
			}
		}

		// 最后一个结点的最开开始和最晚开始是同一时间
		v_l[vexnum - 1] = v_e[vexnum - 1];

		// 每个结点的最晚开始时间 = 以他为起点的结点 减去这段弧的持续时间(权重) 的最小值
		// 因为只有他完成了 后续的结点才能继续 所以他的最晚开始时间 + 最长的持续时间(weight) 必须 <= 后续结点的最早开始时间
		// v_e 被初始化为 int_max 最大值
		for (int i = vexnum - 2; i >= 0; i--) {
			for (int j = 0; j < vexnum; j++) {
				if (G[i][j]) {
					int temp = v_l[j] - G[i][j];
					v_l[i] = min(temp, v_l[i]);
				}
			}
		}

		for (int i = 0; i < vexnum; i++) {
			cout << i  << " 结点最早开始时间: " << v_e[i] << "  最迟开始时间 : " << v_l[i] << endl;
		}

		cout << endl;
		
	}

	// 基于关键活动识别关键路径的方法
	void Critical_path()
	{
		int x, y;
		GetEarliest_Latest(); // 先获取结点最早开始和最晚开始时间
		cout << "\n打印事件最早开始和最晚开始的时间 ---- \n\n";
		for (int i = 0; i < arcnum; i++) {
			x = arcInfo[i][0]; // 事件 起点
			y = arcInfo[i][1]; // 事件 终点
			a_e[i] = v_e[x]; // 事件的最早开始时间就是事件起点的最早开始时间
			a_l[i] = v_l[y] - arcInfo[i][2]; // 事件的最晚开始时间就是事件 的终点的 最晚开始时间减去他的持续时间(weight)
			cout << "事件 " << i << " 最早开始 : " << a_e[i] << "  最晚开始 : " << a_l[i] << endl;
		}

		cout << "\n关键路径 --- \n\n";
		for (int i = 0; i < arcnum; i++) {
			if (a_e[i] == a_l[i]) {
				cout << "结点 " << arcInfo[i][0] << " ->  结点 " << arcInfo[i][1] << "   weight :  " << arcInfo[i][2] << endl;
			}
		}
	}


	// 打印邻接矩阵
	void printGraph()
	{
		cout << "\n打印矩阵 --- \n\n";
		for (int i = 0; i < vexnum; i++) {
			for (int j = 0; j < vexnum; j++) {
				cout.width(4);
				cout << G[i][j];
			}
			cout << "  结点 " << i << " 入度 " << vex_in[i] << endl;
        }
    }
};



int main()
{
	Graph graph;
	graph.Critical_path();
    return 0;
}