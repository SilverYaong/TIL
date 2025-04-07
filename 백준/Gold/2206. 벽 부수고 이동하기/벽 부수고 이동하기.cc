#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define tiii tuple<int, int, int>

const int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int N, M;
vector<vector<vector<int>>> vis;
vector<vector<int>> arr;
int ans = -1;

void sol() {
	queue<tiii> q;
	vis[0][0][0] = 1;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front(); q.pop();
		if (x == N - 1 && y == M - 1) {
			ans = vis[x][y][z];
			return;
		}
		for (register int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (arr[nx][ny] == 0 && vis[nx][ny][z] == 0) {
					vis[nx][ny][z] = vis[x][y][z] + 1;
					q.push({nx, ny, z});
				}
				if (arr[nx][ny] == 1 && z == 0 && vis[nx][ny][1] == 0) {
					vis[nx][ny][1] = vis[x][y][z] + 1;
					q.push({ nx, ny, 1 });
				}
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	arr.assign(N, vector<int>(M, 0));
	vis.assign(N, vector<vector<int>>(M, vector<int>(2, 0)));
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	sol();
	printf("%d", ans);
}