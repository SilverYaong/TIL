#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> vis;

int N, M;
int a, b;
int result;
bool found;
void calDist(int cur, int dist) {
	if (cur == b) {
		result = dist;
		found = true;
		return;
	}
	vis[cur] = true;
	for (auto nxt : graph[cur]) {
		if (vis[nxt.first]) continue;
		if (found) return;
		calDist(nxt.first, dist + nxt.second);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	graph.assign(N + 1, vector<pair<int, int>>());

	for (int i = 1; i < N; i++) {
		int u, v, d;
		scanf("%d %d %d", &u, &v, &d);
		graph[u].push_back(make_pair(v, d));
		graph[v].push_back(make_pair(u, d));
	}
	for (int i = 0; i < M; i++) {
		vis.assign(N + 1, false);
		result = 0;
		found = false;
		scanf("%d %d", &a, &b);
		calDist(a, 0);
		printf("%d\n", result);
	}
}