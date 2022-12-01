#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 20

typedef struct EdgeNode{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VNode{
    char data;
    EdgeNode *link;
}VNode;
typedef struct ALGraph{
    int vexnum,arcnum;
    VNode adjlist[N];
}ALGraph;

typedef struct{
    int data[N];
    int front,rear;
}SqQueue;

int visited[N];

void createGraph(ALGraph *g){
    int i,j,c;
    char v;
    EdgeNode *s;
    i=c=0;
    while((v=getchar())!='#')
    {
        g->adjlist[i].data=v;
        g->adjlist[i].link=NULL;
        i++;
    }
    g->vexnum=i;
    scanf("%d,%d",&i,&j);
    while(i!=-1)
    {
        s=(EdgeNode*)malloc(sizeof(EdgeNode));
        s->adjvex=j;
        s->next=g->adjlist[i].link;
        g->adjlist[i].link=s;
        c++;
        scanf("%d,%d",&i,&j);
    }
    g->arcnum=c;
    return;
}

void initVisited(){
   int i;
   for (i=0;i<N;i++)
    visited[i]=0;
}
//此处填写代码，完成在图g中从k点进行连通分量的广度优先搜索
void bfs(ALGraph g, int k)
{
    SqQueue queue;
    queue.front = queue.rear = 0;
	queue.data[queue.rear++] = k;
	visited[k] = 1;
    while (queue.rear != queue.front) {
        int size = (queue.rear - queue.front + N) % N;
        for (int i = 0; i < size; i++) {
            int pos = queue.data[queue.front++ % N];
            EdgeNode *node = g.adjlist[pos].link;
            printf("%c", g.adjlist[pos].data);
			while (node) {
				if (visited[node->adjvex] == 0) {
					visited[node->adjvex] = 1;
					queue.data[queue.rear++ % N] = node->adjvex;
				}
                node = node->next;
            }
        }
    }
    printf("\n");
}

//此处填写代码，完从u顶点开始对整个图g进行广度优先搜索
void tbfs(ALGraph g,int u)
{
	for (int i = 0; i < g.vexnum;i++){
		if(visited[(i + u) % g.vexnum] == 0){
			bfs(g, (i + u) % g.vexnum);
		}
	}
}

int main()
{
    ALGraph g;
    int u;
    createGraph(&g);
    scanf("%d",&u);
    initVisited();
    tbfs(g,u);
    return 0;
}

