#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
	//freopen("input.txt", "r", stdin);
	int N, M, ans = 0;
	scanf("%d %d", &N, &M);
	vector<vector<pii>> arr(N + 1, vector<pii>());
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	while (M--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		arr[a].push_back({ c, b });
		arr[b].push_back({ c, a });
	}
	vector<bool> vis(N + 1, false);
	vis[1] = true;
	for (auto nxt : arr[1]) {
		pq.push({ nxt.first, nxt.second });
	}
	while (pq.size()) {
		int w = pq.top().first, v = pq.top().second;
		pq.pop();
		if (!vis[v]) {
			vis[v] = true;
			ans += w;
			for (auto nxt : arr[v]) {
				pq.push({ nxt.first, nxt.second });
			}
		}
	}
	printf("%d\n", ans);
}