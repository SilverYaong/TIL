#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
#include <tuple>

using namespace std;

typedef pair<double, int> pdi;

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

double calDist(const double &x1, const double &y1, const double &x2, const double &y2) {
	return sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));
}

const double INF = INFINITY;

int main() {
	//freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	
	vector<int> posX(N + 1), posY(N + 1);
	vector<double> dist(N + 1, INF);
	vector<bool> vis(N + 1, false);
	p.assign(N + 1, -1);
	
	for (register int i = 1; i <= N; i++) {
		scanf("%d %d", &posX[i], &posY[i]);
	}
	for (register int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		uni(a, b);
	}
	priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;
	for (register int i = 1; i <= N; i++) {
		for (register int j = i + 1; j <= N; j++) {
			double d = calDist(posX[i], posY[i], posX[j], posY[j]);
			pq.push({ d, i, j });
		}
	}
	double ans = 0.0;
	int edge = 0;
	while (!pq.empty()) {
		double d;
		int u, v;
		tie(d, u, v) = pq.top(); pq.pop();

		if (unifind(u) != unifind(v)) {
			uni(u, v);
			ans += d;
			edge++;
			if (edge == N - 1) break;
		}
	}
	printf("%.2lf\n", ans);
}