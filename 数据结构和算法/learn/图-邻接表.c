#include <stdio.h>
#include <stdlib.h>

typedef struct Vex {
	int id;
	struct Vex *next;
} Vex;

typedef struct Graph {
	int vexnum;
	int arcnum;
	Vex *G;
}Graph;

void initGraph(Graph* graph, int vexnum)
{

	// 初始化图，申请内存并且给他们的id赋值
	graph->G = (Vex*)calloc(vexnum, sizeof(Vex));
	graph->vexnum = vexnum;
	for (int i = 0; i < vexnum; i++) {
		graph->G[i].id = i;
	}
}

void addArc(Graph* graph, int arcnum)
{
	int start, end;
	graph->arcnum = arcnum;
	for (int i = 0; i < arcnum; i++) {
		// 输入结点信息
		printf("请输入两个结点信息: ");
		scanf("%d%d", &start, &end);
		// 建立新的结点用来存储数据
		Vex* vex = (Vex*)calloc(1, sizeof(Vex));

		// 将结点尾部指向修改
		vex->id = end;

		// 获取next指针，找到需要插入的位置
		Vex* head = &(graph->G[start]);
		while (head->next) {
			head = head->next;
		}
		head->next = vex;
		// 后面是无向图的代码,如果是有向图上面的就够了
		vex = (Vex*)calloc(1, sizeof(Vex));
		vex->id = start;
		head = &(graph->G[end]);
		while (head->next) {
			head = head->next;
		}
		head->next = vex;
	}
}

// 打印图
void printGraph(Graph* graph)
{
	for (int i = 0; i < graph->vexnum; i++) {
		Vex* head = graph->G[i].next;
		printf("结点 %d ->    ", i);
		while (head) {
			printf("结点 %d ---    ", head->id);
			head = head->next;
		}
		printf("\n");
	}
}

// 深度优先搜索法
void dfs(Graph* graph, int v, int* visited)
{
	// 打印数据
	visited[v] = 1;
	printf("结点 %d -> ", graph->G[v].id);
	// 循环查找下没访问过的元素
	Vex* head = graph->G[v].next;
	while (head) {
		if (visited[head->id] == 0) {
			visited[head->id] = 1;
			dfs(graph, head->id, visited);
		}
		head = head->next;
	}
	printf("\n");
}

// 删除图生成的空间
void delGraph(Graph** graph, int **visited)
{
	if ((*graph)->G) {
		for (int i = 0; i < (*graph)->vexnum; i++) {
			Vex* head = (*graph)->G[i].next;
			while (head) {
				Vex* temp = head;
				head = head->next;
				free(temp);
			}
		}
		free((*graph)->G);
		(*graph)->G = NULL;
	}
	free(*graph);
	free(*visited);
	*visited = NULL;
	*graph = NULL;
}

int main(void)
{
	int num_vex = 6, num_arc = 8;
	int* visited = (int*)calloc(num_vex, sizeof(int));
	Graph* graph = (Graph*)calloc(1, sizeof(Graph));
	initGraph(graph, num_vex);
	addArc(graph, num_arc);
	printGraph(graph);
	dfs(graph, 0, visited);
	delGraph(&graph, &visited);
	return 0;
}