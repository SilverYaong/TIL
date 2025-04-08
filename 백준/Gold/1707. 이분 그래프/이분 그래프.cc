#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define tii tuple<int, int>

int N, M;
vector<vector<int>> graph;
vector<int> color;
bool flag;

int main() {
	//freopen("input.txt", "r", stdin);
	int K;
	scanf("%d", &K);
	while (K--) {
		graph.clear();
		color.clear();
		flag = 0;
		scanf("%d %d", &N, &M);
		graph.assign(N + 1, vector<int>());
		color.assign(N + 1, 0);
		for (register int i = 0; i < M; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (register int i = 1; i <= N; i++) {
			if (color[i] == 0) {
				color[i] = 1;
				queue<int> q;
				q.push(i);
				while (!q.empty()) {
					int cur = q.front(); q.pop();
					for (auto nxt : graph[cur]) {
						if (color[nxt] == 0) {
							color[nxt] = (color[cur] == 1) ? 2 : 1;
							q.push(nxt);
						}
						else {
							if (color[cur] == color[nxt]) {
								flag = 1;
								break;
							}
						}
					}
					if (flag) break;
				}
			}
			if (flag) break;
		}
		if (!flag) printf("YES\n");
		else printf("NO\n");
	}
}