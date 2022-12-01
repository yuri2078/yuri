#include <stdio.h>
#include <stdlib.h>

typedef struct Vex {
	char data;
	struct Vex *next;
} Vex;

typedef struct Graph {
	int vexnum;
	int arcnum;
	Vex G[100];
} Graph;
void addArc(Graph* graph)
{
	int x, y;
	scanf("%d,%d", &x, &y);
	while (x != -1 && y != -1) {
		Vex* new_node = (Vex*)calloc(1, sizeof(Vex));
		new_node->data = graph->G[y].data;
		new_node->next = graph->G[x].next;
		graph->G[x].next = new_node;
		scanf("%d,%d", &x, &y);
    }
}

// 打印图
void printGraph(Graph* graph)
{
	for (int i = 0; i < graph->vexnum; i++) {
		Vex* head = graph->G[i].next;
		printf("%c:", graph->G[i].data);
		while (head) {
			printf("->%c", head->data);
			head = head->next;
		}
		printf("\n");
	}
}

void createGraph(Graph* graph)
{
	int num_vex = 0;
	char ch;
	while ((ch = getchar()) != '#') {
		graph->G[num_vex].data = ch;
		graph->G[num_vex++].next = NULL;
	}
	graph->vexnum = num_vex;
	addArc(graph);
}

// 删除图生成的空间
void delGraph(Graph** graph)
{
    for (int i = 0; i < (*graph)->vexnum; i++) {
		Vex* head = (*graph)->G[i].next;
		while (head) {
			Vex* temp = head;
			head = head->next;
			free(temp);
        }
	}
	free(*graph);
	*graph =NULL;
}

int main(void)
{
	
	Graph* graph = (Graph*)calloc(1, sizeof(Graph));
	createGraph(graph);
	printGraph(graph);
	delGraph(&graph);
	return 0;
}