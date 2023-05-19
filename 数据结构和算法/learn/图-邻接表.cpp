#include <queue>
#include <yuri.h>
using namespace std;

typedef struct EdgeNode {
  int adjvex;            // 结点序号
  struct EdgeNode *next; // 保存下一个结点
  EdgeNode() {
    adjvex = 0;
    next = nullptr;
  }
} EdgeNode;

typedef struct VNode {
  char data;                // 结点信息
  EdgeNode *link = nullptr; // 邻接表
} VNode;

class Graph {
private:
  int vexnum;                  // 节点个数
  int arcnum;                  // 边的个数
  vector<int> visited;         // 用来报错是否访问过节点
  vector<VNode> graph;         // 存储邻接表
  vector<vector<int>> arcInfo; // 用来保存 边的信息 0 ： 起点 1 ： 终点 2 ： 权重
  yuri::Yuri yuri;             // 读取文件对象

public:
  Graph() {
    vexnum = 9; // 设置节点数

    // 初始化数组
    visited = vector<int>(vexnum);
    graph = vector<VNode>(vexnum);
    arcInfo = yuri.getData(); // 读取边的信息
    arcnum = arcInfo.size();  // 设置边的数量

    createGraph();      // 构造邻接表
    yuri.outData(true); // 打印边的信息
  }

  // 创建邻接表- 逆序存储
  void createGraph() {
    int x, y;
    // 遍历每条边 建立邻接表
    for (int i = 0; i < arcnum; i++) {
      x = arcInfo[i][0];
      y = arcInfo[i][1];
      EdgeNode *node = new EdgeNode;
      node->next = graph[x].link;
      node->adjvex = y;
      graph[x].link = node;

      // 无向图
      node = new EdgeNode;
      node->next = graph[y].link;
      node->adjvex = x;
      graph[y].link = node;

      /* 顺序存储
      EdgeNode* node = new EdgeNode;
      node->next = nullptr;
      node->adjvex = y;
      if (graph[x].link == nullptr) {
          graph[x].link = node;
      } else {
          EdgeNode* head = graph[x].link;
          while (head->next) {
              head = head->next;
          }
          head->next = node;
      }
      */
    }
  }

  // 打印图
  void printGraph() {
    cout << "\n打印邻接表 --- \n\n";
    for (int i = 0; i < vexnum; i++) {
      cout << "结点 :" << i << "   ";
      EdgeNode *head = graph[i].link;
      while (head) {
        cout << " -> 结点 " << head->adjvex << "  ";
        head = head->next;
      }
      cout << endl;
    }
    cout << "\n邻接表打印结束 --- \n\n";
  }

  // 初始化visited数组
  void initVisited() {
    const int size = visited.size();
    for (int i = 0; i < size; i++) {
      visited[i] = 0;
    }
  }

  // 深度优先算法
  // 从一个节点开始，找到和他相连的节点 进行遍历
  // 将找到的节点作为新的节点 重复操作
  void dfs(int k) {
    visited[k] = 1;
    cout << "结点 " << k << " -> ";
    EdgeNode *head = graph[k].link;
    while (head) {
      if (visited[head->adjvex] == 0) {
        dfs(head->adjvex);
      }
      head = head->next;
    }
  }

  // 广度优先算法
  // 从初始节点开始遍历 将初始节点添加进队列当中
  // 然后遍历队列里仅有的元素，不算后续添加的元素
  // 将他们未遍历且相连的节点添加进去
  void bfs() {
    cout << "\n\nbfs 开始:\n\n";
    initVisited();
    queue<int> que;
    que.push(0);    // 先把初始节点添加进去
    visited[0] = 1; // 先把初始节点设置为已经访问过了
    while (!que.empty()) {
      const int size = que.size();
      // 循环添加数据
      for (int i = 0; i < size; i++) {
        int k = que.front(); // 获取队头
        que.pop();           // 弹出队头
        cout << "节点 " << k << " -> ";
        // 循环添加未访问的元素
        EdgeNode *head = graph[k].link;
        while (head) {
          if (visited[head->adjvex] == 0) {
            que.push(head->adjvex);
            visited[head->adjvex] = 1;
          }
          head = head->next;
        }
      }
      // 打印回车更加的美观
      cout << "\n";
    }
    cout << "\nbfs 结束:\n\n";
  }

  // 析构邻接表
  ~Graph() {
    for (int i = 0; i < vexnum; i++) {
      EdgeNode *head = graph[i].link;
      while (head) {
        EdgeNode *temp = head;
        head = head->next;
        delete temp;
      }
    }
  }
};

int main() {
  Graph graph;
  graph.printGraph();
  graph.dfs(0);
  graph.bfs();
  return 0;
}
