#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tiii;

vector<int> p;

int unifind(int a) {
	if (p[a] < 0) return a;
	return p[a] = unifind(p[a]);
}

void uni(int a, int b) {
	a = unifind(a);
	b = unifind(b);
	if (a != b) p[b] = a;
}

const int INF = (~0U >> 1);

int main() {
	//freopen("input.txt", "r", stdin);
	while (true) {
		int N, M;
		scanf("%d %d", &M, &N);
		if (N == 0 && M == 0) break;

		p.assign(M + 1, -1);
		int total = 0;
		priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

		while (N--) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			total += z;
			pq.push({ z, x, y });
		}

		int edge = 0;

		while (!pq.empty()) {
			int d, u, v;
			tie(d, u, v) = pq.top(); pq.pop();

			if (unifind(u) != unifind(v)) {
				uni(u, v);
				total -= d;
				edge++;
				if (edge == M - 1) break;
			}
		}
		printf("%d\n", total);
	}
}