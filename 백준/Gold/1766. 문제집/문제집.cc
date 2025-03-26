#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<vector<int>> graph(N + 1, vector<int>());
	vector<int> degree(N + 1, 0);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		degree[b]++;
	}
	for (register int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int u = pq.top(); pq.pop();
		printf("%d ", u);
		for (auto nxt : graph[u]) {
			degree[nxt]--;
			if (degree[nxt] == 0) {
				pq.push(nxt);
			}
		}
	}
}