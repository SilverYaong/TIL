#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
bool cycle;

void dfs(int current, int parent) {
	visited[current] = true;
	for (int next : graph[current]) {
		if (!visited[next]) {
			dfs(next, current);
		}
		else if (next != parent) {
			cycle = true;
		}
	}
}

int main()
{
	int tc = 0;
	while (true)
	{
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;

		graph.assign(n + 1, vector<int>());
		visited.assign(n + 1, false);
		tc++;

		int treeCount = 0;

		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i]) {
				cycle = false;
				dfs(i, 0);
				if (!cycle) {
					treeCount++;
				}
			}
		}

		printf("Case %d: ", tc);
		if (treeCount == 0) printf("No trees.\n");
		else if (treeCount == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", treeCount);
	}
}