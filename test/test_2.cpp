#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 200010;
const long long inf = 1000000000000000;

struct node {
	int x, y, id;
} e[200010];

struct node2 {
	int x;
	long long len;
};

bool operator<(node2 a, node2 b)
{
	return a.len > b.len;
}

int n, head[maxn], to[maxn * 4], nextt[maxn * 4], tot = 1, w[maxn * 4],
                                                  vis[maxn * 4];
priority_queue<node2> q;
long long d[maxn];

bool cmp1(node a, node b) { return a.x < b.x; }

bool cmp2(node a, node b) { return a.y < b.y; }

void add(int x, int y, int z)
{
	w[tot] = z;
	to[tot] = y;
	nextt[tot] = head[x];
	head[x] = tot++;
}

void dijkstra()
{
	for (int i = 1; i <= n; i++)
		d[i] = inf;
	d[1] = 0;
	node2 temp;
	temp.len = 0;
	temp.x = 1;
	q.push(temp);
	while (!q.empty()) {
		while (!q.empty() && vis[q.top().x])
			q.pop();
		if (q.empty())
			return;
		node2 u = q.top();
		q.pop();
		int x = u.x;
		long long len = u.len;
		vis[x] = 1;
		for (int i = head[x]; i; i = nextt[i]) {
			int v = to[i];
			if (d[v] > d[x] + w[i]) {
				d[v] = d[x] + w[i];
				node2 temp;
				temp.x = v;
				temp.len = d[v];
				q.push(temp);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &e[i].x, &e[i].y);
		e[i].id = i;
	}
	sort(e + 1, e + 1 + n, cmp1);
	for (int i = 1; i < n; i++) {
		int t = min(abs(e[i].x - e[i + 1].x), abs(e[i].y - e[i + 1].y));
		add(e[i].id, e[i + 1].id, t);
		add(e[i + 1].id, e[i].id, t);
	}
	sort(e + 1, e + 1 + n, cmp2);
	for (int i = 1; i < n; i++) {
		int t = min(abs(e[i].x - e[i + 1].x), abs(e[i].y - e[i + 1].y));
		add(e[i].id, e[i + 1].id, t);
		add(e[i + 1].id, e[i].id, t);
	}
	dijkstra();
	printf("%lld\n", d[n]);

	return 0;
}
