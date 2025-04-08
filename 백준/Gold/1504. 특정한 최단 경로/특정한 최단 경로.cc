#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
const int INF = (~0U >> 2);

vector<vector<pii>> graph;

void sol(vector<int> &dist, const int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int curDist = pq.top().first, curNode = pq.top().second;
		pq.pop();
		if (dist[curNode] != curDist) {
			continue;
		}
		for (auto &nxt : graph[curNode]) {
			int weight = nxt.first, nxtNode = nxt.second;
			if (dist[nxtNode] > weight + curDist) {
				dist[nxtNode] = weight + curDist;
				pq.push({ dist[nxtNode], nxtNode });
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int N, E;
	scanf("%d %d", &N, &E);
	graph.assign(N + 1, vector<pii>());
	vector<int> dist0(N + 1, INF);
	vector<int> dist1(N + 1, INF);
	vector<int> dist2(N + 1, INF);
	for (register int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}
	int v1, v2;
	scanf("%d %d", &v1, &v2);
	sol(dist0, 1);
	sol(dist1, v1);
	sol(dist2, v2);
	if (dist0[v1] == INF || dist0[v2] == INF || dist1[v2] == INF || dist1[N] == INF || dist2[v1] == INF || dist2[N] == INF) {
		printf("-1");
	}
	else {
		int a, b;
		a = dist0[v1] + dist1[v2] + dist2[N];
		b = dist0[v2] + dist2[v1] + dist1[N];
		printf("%d", min(a, b));
	}
}