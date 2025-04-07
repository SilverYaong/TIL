#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int>> arr;
vector<vector<bool>> vis;
vector<int> ans;
int N;
int cnt = 0;

const int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

void sol(const int &r, const int &c) {
	int num = 0;
	queue<tuple<int, int>> q;
	q.push({ r, c });
	while (!q.empty()) {
		num++;
		int x, y;
		tie(x, y) = q.front(); q.pop();
		for (register int d = 0; d < 4; d++) {
			int nx = dx[d] + x, ny = dy[d] + y;
			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (!vis[nx][ny] && arr[nx][ny] == 1) {
					vis[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	ans.push_back(num);
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	arr.assign(N, vector<int>(N, 0));
	vis.assign(N, vector<bool>(N, 0));
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && !vis[i][j]) {
				cnt++;
				vis[i][j] = 1;
				sol(i, j);
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", cnt);
	for (register int i = 0; i < cnt; i++) {
		printf("%d\n", ans[i]);
	}
}