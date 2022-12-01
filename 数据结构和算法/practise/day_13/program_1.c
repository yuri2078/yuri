#include <stdlib.h>
#include <stdio.h>

typedef struct Vex {
	char data;
} Vex;

typedef struct Graph {
	int vexnum; // 结点个数
	int arcnum; // 弧数
	int **G; // 邻接矩阵
    Vex vex[100];
} Graph;

// 初始化邻接矩阵
void initGraph(Graph* graph, int num_vex)
{
	graph->vexnum = num_vex;
	graph->G = (int**)calloc(num_vex, sizeof(int*));
	for (int i = 0; i < num_vex; i++) {
		graph->G[i] = (int*)calloc(num_vex, sizeof(int));
    }
}

void createGraph(Graph* graph)
{

	int num_vex = 0, x, y;
	char ch;
	while ((ch = getchar()) != '#') {
		graph->vex[num_vex++].data = ch;
	}
	initGraph(graph, num_vex);
	scanf("%d,%d", &x, &y);
	while (x != -1 && y != -1) {
		graph->G[x][y] = graph->G[y][x] = 1;
		scanf("%d,%d", &x, &y);
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

// 释放图中申请的内存
void delGraph(Graph* graph)
{
	for (int i = 0; i < graph->vexnum; i++) {
		free(graph->G[i]);
	}
	free(graph->G);
	graph->G = NULL;
}


int main(void)
{
	Graph graph;
	createGraph(&graph);
	printf("graph:\n");
	printGraph(&graph);
	delGraph(&graph);
    return 0;
}