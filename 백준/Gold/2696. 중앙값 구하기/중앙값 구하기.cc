#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int M;
		scanf("%d", &M);
		printf("%d\n", M / 2 + 1);
		priority_queue<int, vector<int>, greater<int>> pq2;
		priority_queue<int> pq1;
		for (register int i = 0; i < M; i++) {
			int x;
			scanf("%d", &x);
			if (pq1.size() <= pq2.size()) {
				pq1.push(x);
			}
			else {
				pq2.push(x);
			}
			if (!pq1.empty() && !pq2.empty()) {
				while (pq1.top() > pq2.top()) {
					int a = pq1.top(); pq1.pop();
					int b = pq2.top(); pq2.pop();
					pq2.push(a);
					pq1.push(b);
				}
			}
			if (i % 2 == 0) {
				printf("%d ", pq1.top());
			}
			if ((i + 1) % 20 == 0) printf("\n");
		}
		printf("\n");
	}
}