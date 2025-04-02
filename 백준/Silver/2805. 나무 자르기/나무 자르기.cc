#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> arr(N, 0);
	for (register int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int R = *max_element(arr.begin(), arr.end());
	int L = 0, mid, ans = 0;
	while (L <= R) {
		mid = (L + R) / 2;
		long long wood = 0;
		for (register int i = 0; i < N; i++) {
			if (arr[i] > mid) {
				wood += arr[i] - mid;
			}
		}
		if (wood >= M) {
			ans = mid;
			L = mid + 1;
		}
		else {
			R = mid - 1;
		}
	}
	printf("%d\n", ans);
}