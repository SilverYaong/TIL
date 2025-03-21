#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M, ans, cnt = 1;
const int INF = 999999;
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> dist;


const int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

void chkIsland(int r, int c) {
	visited[r][c] = true;
	queue<pair<int, int>> q;
	q.push({ r, c });
	arr[r][c] = cnt;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (register int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (!visited[nx][ny] && arr[nx][ny] == 1) {
					visited[nx][ny] = true;
					arr[nx][ny] = cnt;
					q.push({ nx, ny });
				}
			}
		}
	}
	cnt++;
}

int main() {
	ans = 0;
	scanf("%d %d", &N, &M);
	arr.assign(N, vector<int>(M));
	visited.assign(N, vector<bool>(M, false));
	priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}	
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < M; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				chkIsland(i, j);
			}
		}
	}
	dist.assign(cnt, vector<int>(cnt, INF));
	graph.assign(cnt, vector<pair<int, int>>());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != 0) {
				int landNum = arr[i][j];
				bool border = false;
				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d], ny = j + dy[d];
					if (0 <= nx && nx < N && 0 <= ny && ny < M) {
						if (arr[nx][ny] == 0) {
							border = true;
							break;
						}
					}
				}
				if (!border) continue;

				for (int d = 0; d < 4; d++) {
					int length = 0;
					int x = i, y = j;
					while (true) {
						x += dx[d];
						y += dy[d];
						if (x < 0 || N <= x || y < 0 || M <= y) break;
						if (arr[x][y] == landNum) break;
						if (arr[x][y] == 0) {
							length++;
							continue;
						}
						if (length >= 2) {
							int otherLandNum = arr[x][y];
							if (dist[landNum][otherLandNum] > length) {
								dist[landNum][otherLandNum] = length;
								dist[otherLandNum][landNum] = length;
							}
						}
						break;
					}
				}
			}
		}
	}
	for (register int i = 1; i < cnt; i++) {
		for (register int j = 1; j < cnt; j++) {
			if (dist[i][j] != INF) {
				graph[i].push_back({ dist[i][j], j });
				graph[j].push_back({ dist[i][j], i });
			}
		}
	}
	int edge = 0;
	for (auto &nxt : graph[1]) {
		pq.push({ nxt.first, 1, nxt.second });
	}
	vector<bool> used(cnt, false);
	used[1] = true;
	while (!pq.empty()) {
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (!used[b]) {
			used[b] = true;
			ans += cost;
			edge++;
			for (auto &nxt : graph[b]) {
				pq.push({ nxt.first, b, nxt.second });
			}
		}
	}
	if (edge != cnt - 2) ans = -1;
	printf("%d\n", ans);
}