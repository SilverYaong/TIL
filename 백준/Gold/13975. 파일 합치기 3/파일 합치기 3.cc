#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		int N;
		scanf("%d", &N);
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		while (N--) {
			int x;
			scanf("%d", &x);
			pq.push(x);
		}
		long long ans = 0;
		while (pq.size() > 1) {
			long long a = pq.top(); pq.pop();
			long long b = pq.top(); pq.pop();
			ans += a + b;
			pq.push(a + b);
		}
		printf("%lld\n", ans);
	}
}