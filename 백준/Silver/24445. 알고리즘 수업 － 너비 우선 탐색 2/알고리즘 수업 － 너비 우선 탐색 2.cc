#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int N, M, R;
	scanf("%d %d %d", &N, &M, &R);
	vector<priority_queue<int>> graph(N + 1);
	for (register int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push(v);
		graph[v].push(u);
	}

	vector<bool> vis(N + 1, 0);
	vector<int> order(N + 1, 0);
	queue<int> q;
	q.push(R);
	vis[R] = 1;
	int idx = 1;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		order[u] = idx++;
		while (!graph[u].empty()) {
			int v = graph[u].top(); graph[u].pop();
			if (!vis[v]) {
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	for (register int i = 1; i <= N; i++) {
		printf("%d\n", order[i]);
	}
}