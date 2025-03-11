#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> subTreeSize;

int countSubtreeNodes(int cur) {
	visited[cur] = true;
	for (int nxt : graph[cur]) {
		if (visited[nxt]) continue;
		subTreeSize[cur] += countSubtreeNodes(nxt);
	}
	subTreeSize[cur]++;
	return subTreeSize[cur];
}

int N, R, Q;

int main()
{
	scanf("%d %d %d", &N, &R, &Q);
	graph.assign(N + 1, vector<int>());
	visited.assign(N + 1, false);
	subTreeSize.assign(N + 1, 0);

	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	countSubtreeNodes(R);
	for (int i = 0; i < Q; i++) {
		int a;
		scanf("%d", &a);
		printf("%d\n", subTreeSize[a]);
	}
}