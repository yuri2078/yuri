#include <stdlib.h>
#include <stdio.h>
typedef struct Vex {
	int x;
	int y;
} Vex;

typedef struct Graph {
	int vexnum;
	int **G;

} Graph;

void initGraph(Graph* graph, int num_vex)
{
	graph->vexnum = num_vex;
	graph->G = (int**)calloc(num_vex, sizeof(int*));
	for (int i = 0; i < num_vex; i++) {
		graph->G[i] = (int*)calloc(num_vex, sizeof(int));
		for (int j = 0; j < num_vex; j++) {
			graph->G[i][j] = 0;
        }
    }
}

void printGraph(const Graph* graph)
{
	for (int i = 0; i < graph->vexnum; i++) {
		for (int j = 0; j < graph->vexnum; j++) {
			printf("%d ", graph->G[i][j]);
		}
		printf("\n");
    }
}

void drawGraph(Graph* graph, int num_arc)
{
	int x, y;
	graph->arcnum = num_arc;
	for (int i = 0; i < num_arc; i++) {
		printf("请输入结点信息 : ");
		scanf("%d%d", &x, &y);
		if (x == y || x >= graph->vexnum || y >= graph->vexnum) {
			i--;
			continue;
        }
		graph->G[x][y] = graph->G[y][x] = 1;
    }
}

void delGraph(Graph* graph)
{
	for (int i = 0; i < graph->vexnum; i++) {
		free(graph->G[i]);
		graph->G[i] = NULL;
	}
	free(graph->G);
	graph->G = NULL;
}

int main(void)
{
	int num_vex = 4, num_arc = 4; // 输入顶点数
	Graph graph;
	initGraph(&graph, num_vex);
	drawGraph(&graph, num_arc);
	printGraph(&graph);
	delGraph(&graph);
    return 0;
}