#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int N, K;
	scanf("%d %d", &N, &K);
	long long L = 1, R = (long long)N * N;
	long long mid, cnt;
	while (L <= R) {
		mid = (L + R) / 2;
		cnt = 0;
		for (register int i = 1; i <= N; i++) {
			cnt += min(mid / i, (long long)N);
		}
		if (cnt < K) {
			L = mid + 1;
		}
		else {
			R = mid - 1;
		}
	}
	printf("%lld\n", L);
}