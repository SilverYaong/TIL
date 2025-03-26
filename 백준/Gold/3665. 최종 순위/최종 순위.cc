#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d", &N);
		vector<int> arr(N + 1);
		vector<vector<int>> graph(N + 1, vector<int>());
		vector<int> result;
		vector<int> degree(N + 1, 0);
		priority_queue<int, vector<int>, greater<int>> pq;
		for (register int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}
		for (register int i = 1; i < N; i++) {
			for (register int j = i + 1; j <= N; j++) {
				graph[arr[i]].push_back(arr[j]);
				degree[arr[j]]++;
			}
		}
		scanf("%d", &M);
		while (M--) {
			int a, b;
			scanf("%d %d", &a, &b);
			auto it = find(graph[b].begin(), graph[b].end(), a);
			if (it != graph[b].end()) {
				graph[b].erase(it);
				degree[a]--;
				graph[a].push_back(b);
				degree[b]++;
			}
			else {
				it = find(graph[a].begin(), graph[a].end(), b);
				graph[a].erase(it);
				degree[b]--;
				graph[b].push_back(a);
				degree[a]++;
			}
		}
		for (register int i = 1; i <= N; i++) {
			if (degree[i] == 0) {
				pq.push(i);
			}
		}
		bool flag1 = false, flag2 = false;
		
		for (int i = 0; i < N; i++) {
			if (pq.empty()) {
				flag1 = true;
				break;
			}
			if (pq.size() > 1) {
				flag2 = true;
				break;
			}
			int cur = pq.top(); pq.pop();
			result.push_back(cur);
			for (int nxt : graph[cur]) {
				if (--degree[nxt] == 0) pq.push(nxt);
			}
		}

		if (flag1) printf("IMPOSSIBLE\n");
		else if (flag2) printf("?\n");
		else {
			for (register int i = 0; i < N; i++) {
				printf("%d ", result[i]);
			}
			printf("\n");
		}
	}

}