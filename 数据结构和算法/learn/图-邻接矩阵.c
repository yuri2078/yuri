#include <stdlib.h>
#include <stdio.h>
typedef struct Queue {
	int base[100];
	int size;
	int front;
	int back;
}Queue;

typedef struct Vex {
	int x;
	int y;
} Vex;

typedef struct Graph {
	int vexnum; // 结点个数
	int arcnum; // 弧数
	int **G; // 邻接矩阵

} Graph;

// 初始化邻接矩阵
void initGraph(Graph* graph, int num_vex)
{
	graph->vexnum = num_vex;
	graph->G = (int**)calloc(num_vex, sizeof(int*));
	for (int i = 0; i < num_vex; i++) {
		graph->G[i] = (int*)calloc(num_vex, sizeof(int));
		// for (int j = 0; j < num_vex; j++) {
		// 	// 申请内存并将所有元素zhi
		// 	graph->G[i][j] = 0;
		// }


		// 这里用了calloc函数，申请内存时会将内存置为 0 ，就不用循环置为0 了
    }
}

// 打印邻接矩阵
void printGraph(const Graph* graph)
{
	for (int i = 0; i < graph->vexnum; i++) {
		for (int j = 0; j < graph->vexnum; j++) {
			printf("%d ", graph->G[i][j]);
		}
		printf("\n");
    }
}

void drawGraph(Graph* graph, int num_arc, Vex *vex)
{
	// int x, y;
	graph->arcnum = num_arc; 
	for (int i = 0; i < num_arc; i++) {
		// printf("请输入结点信息 : ");
		// scanf("%d%d", &x, &y);
		// // 不满足条件则继续获取数据
		// if (x == y || x >= graph->vexnum || y >= graph->vexnum) {
		// 	i--;
		// 	continue;
		// }
		// graph->G[x][y] = graph->G[y][x] = 1; // 将结点设置为1 表示可以连接
		graph->G[vex[i].x][vex[i].y] = graph->G[vex[i].y][vex[i].x] = 1; // 将结点设置为1 表示可以连接
    }
}

// 释放图中申请的内存
void delGraph(Graph* graph)
{
	for (int i = 0; i < graph->vexnum; i++) {
		free(graph->G[i]);
		graph->G[i] = NULL;
	}
	free(graph->G);
	graph->G = NULL;
}


// 深度优先算法
void dfs(Graph* graph, int v, int *visited)
{
	// 通过递归调用函数打印
	visited[v] = 1;
	// 默认从小的结点开始遍历
	for (int i = 0; i < graph->vexnum; i++) {
		// 当出现和起始结点相连并且没有被遍历过的结点时
		if (graph->G[v][i] == 1 && visited[i] == 0) {
			// 先打印结点信息
			printf("%d 节点 -> %d 节点    ", v + 1, i + 1);
			visited[i] = 1; // 将他设置为已经访问过了
			dfs(graph, i, visited); // 递归调用函数访问后续被相连且没被访问过的结点
		}
	}
	printf("\n");
}

// 广度优先算法
void bfs(Graph* graph, int v, int* visited)
{
	// 初始化队列
	Queue queue;
	queue.front = queue.back = queue.size = 0;
	queue.base[queue.back++] = v;
	queue.size++;

	visited[0] = 1; // 将第一个节点设置为已经访问
	// 只要队列不为空就一直访问
	while (queue.size) {
		const int k = queue.size; // 获取当前队列中的元素个数
		// 循环添加他们的相连接的边
		for (int i = 0; i < k; i++) {
			int vv = queue.base[queue.front++]; // 获取队头元素
			// 打印结点信息
			printf("%d 结点遍历完成捏!\n",vv + 1);
			queue.size--; // 元素个数减一

			// 循环查找队头元素的相连边
			for (int j = 0; j < graph->vexnum; j++) {
				// 如果他们相连并且他没有被遍历过就添加到队列中
				if (graph->G[vv][j] == 1 && visited[j] == 0) {
					queue.base[queue.back++] = j;
					visited[j] = 1; // 将他设置为已经访问
					queue.size++; // 队列元素个数加一
			
				}
			}
		}
		printf("\n"); // 每遍历一层打印一个回车
	}
}

int main(void)
{
	int num_vex = 8, num_arc = 11; // 输入顶点数
	int* visited = (int*)calloc(num_vex, sizeof(int));
	Vex* vex = (Vex*)calloc(num_arc, sizeof(Vex));
	vex[0].x = 0; vex[0].y = 1;
	vex[1].x = 0; vex[1].y = 2;
	vex[2].x = 0; vex[2].y = 5;
	vex[3].x = 1; vex[3].y = 2;
	vex[4].x = 1; vex[4].y = 3;
	vex[5].x = 2; vex[5].y = 4;
	vex[6].x = 2; vex[6].y = 5;
	vex[7].x = 2; vex[7].y = 6;
	vex[8].x = 4; vex[8].y = 6;
	vex[9].x = 6; vex[9].y = 7;
	vex[10].x = 5; vex[10].y = 7;
	
	Graph graph;
	initGraph(&graph, num_vex);
	drawGraph(&graph, num_arc, vex);
	printGraph(&graph);
	dfs(&graph, 0, visited);
	// bfs(&graph, 0, visited);
	delGraph(&graph);
	free(visited);
	free(vex);
    return 0;
}