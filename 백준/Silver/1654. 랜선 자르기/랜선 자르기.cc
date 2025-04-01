#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int K, N;
	scanf("%d %d", &K, &N);
	vector<int> arr(K, 0);
	long long L = 1, R = 0, mid, ans = 0;
	for (register int i = 0; i < K; i++) {
		scanf("%d", &arr[i]);
	}

	R = (long long)*max_element(arr.begin(), arr.end());

	while (L <= R) {
		mid = (L + R) / 2;
		long long cnt = 0;
		for (register int i = 0; i < K; i++) {
			cnt += (long long)arr[i] / mid;
		}

		if (cnt >= N) {
			ans = mid;
			L = mid + 1;
		}
		else {
			R = mid - 1;
		}
	}
	printf("%lld", ans);
}