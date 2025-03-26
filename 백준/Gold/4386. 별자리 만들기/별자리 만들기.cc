#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

const double INF = INFINITY;

int main() {
	//freopen("input.txt", "r", stdin);
	int N;
	double ans = 0;
	scanf("%d", &N);
	vector<bool> used(N, false);
	vector<double> minEdge(N, INF);
	vector<double> posX(N), posY(N);
	for (int i = 0; i < N; i++){
		scanf("%lf %lf", &posX[i], &posY[i]);
	}
	minEdge[0] = 0;
	for (register int i = 0; i < N; i++) {
		int u = -1;
		double minCost = INF;
		for (int j = 0; j < N; j++) {
			if (!used[j] && minEdge[j] < minCost) {
				minCost = minEdge[j];
				u = j;
			}
		}
		used[u] = true;
		ans += minCost;

		for (register int v = 0; v < N; v++) {
			if (!used[v]) {
				double dx = posX[u] - posX[v];
				double dy = posY[u] - posY[v];
				double cost = sqrt(dx * dx + dy * dy);
				if (cost < minEdge[v]) {
					minEdge[v] = cost;
				}
			}
		}
	}
	printf("%.2lf", ans);
}