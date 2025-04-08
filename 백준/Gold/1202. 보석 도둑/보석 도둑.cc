#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define pll pair<long long, long long>

int main() {
	//freopen("input.txt", "r", stdin);
	int N, K;
	scanf("%d %d", &N, &K);
	priority_queue<long long> pq;
	vector<pll> jews(N);
	vector<long long> bags(K);
	long long ans = 0;
	for (register int i = 0; i < N; i++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		jews[i] = { x, y };
	}
	for (register int i = 0; i < K; i++) {
		long long x;
		scanf("%lld", &x);
		bags[i] = x;
	}
	sort(jews.begin(), jews.end());
	sort(bags.begin(), bags.end());
	int idx = 0;
	for (int i = 0; i < K; i++) {
		while (idx < N && bags[i] >= jews[idx].first) {
			pq.push(jews[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			ans += pq.top(); pq.pop();
		}
	}
	printf("%lld", ans);
}