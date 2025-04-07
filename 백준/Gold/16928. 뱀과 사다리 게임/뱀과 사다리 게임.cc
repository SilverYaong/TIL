#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>

using namespace std;

unordered_map<int, int> ladder, snake;
vector<int> dice(101, 100);
int ans = 0;

void sol() {
	queue<tuple<int, int>> q;
	q.push({ 1, 0 });
	int cur, cnt;
	while (!q.empty()) {
		tie(cur, cnt) = q.front(); q.pop();
		if (cur == 100) {
			ans = cnt;
			return;
		}
		if (dice[cur] > cnt) {
			dice[cur] = cnt;
		}
		else {
			continue;
		}
		for (register int i = 1; i <= 6; i++) {
			if (ladder.find(cur + i) != ladder.end()) {
				q.push({ ladder[cur + i], cnt + 1 });
				continue;
			}
			if (snake.find(cur + i) != snake.end()) {
				q.push({ snake[cur + i], cnt + 1 });
				continue;
			}
			q.push({ cur + i, cnt + 1 });
		}
	}
	
	
}

int main() {
	//freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	for (register int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		ladder.insert({ x, y });
	}
	for (register int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		snake.insert({ x, y });
	}
	sol();
	printf("%d", ans);
}