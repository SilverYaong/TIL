#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define X first
#define Y second

const int INF = (~0U >> 2);

int main() {
	//freopen("input.txt", "r", stdin);
	int V, E, K;
	scanf("%d %d %d", &V, &E, &K);
	vector<vector<pii>> graph(V + 1, vector<pii>());
	vector<int> dist(V + 1, INF);
	for (register int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({ w, v });
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[K] = 0;
	pq.push({ 0, K });
	while (!pq.empty()) {
		int curDist = pq.top().X;
		int curNode = pq.top().Y;
		pq.pop();

		if (curDist != dist[curNode]) {
			continue;
		}
		for (auto &nxt : graph[curNode]) {
			int weight = nxt.X, nxtNode = nxt.Y;
			if (dist[nxtNode] > curDist + weight) {
				dist[nxtNode] = curDist + weight;
				pq.push({ dist[nxtNode], nxtNode });
			}
		}
	}

	for (register int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}
}