#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int N, M, R;
	scanf("%d %d %d", &N, &M, &R);
	vector<priority_queue<int, vector<int>, greater<int>>> graph(N + 1);
	for (register int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push(v);
		graph[v].push(u);
	}

	vector<bool> vis(N + 1, 0);
	vector<int> order(N + 1, 0);
	stack<int> s;
	s.push(R);
	vis[R] = 1;
	order[R] = 1;
	int idx = 1;

	while (!s.empty()) {
		int u = s.top();
		if (!graph[u].empty()) {
			int nxt = graph[u].top(); graph[u].pop();
			if (!vis[nxt]) {
				vis[nxt] = 1;
				order[nxt] = ++idx;
				s.push(nxt);
			}
		}
		else {
			s.pop();
		}
	}
	for (register int i = 1; i <= N; i++) {
		printf("%d\n", order[i]);
	}
}