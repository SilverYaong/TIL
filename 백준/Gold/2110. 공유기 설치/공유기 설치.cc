#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> arr;

bool possible(const int &mid) {
	int cnt = 1, prev = arr[0];
	for (register int i = 1; i < N; i++) {
		if (arr[i] - prev >= mid) {
			cnt++;
			prev = arr[i];
		}
	}
	if (cnt >= C) {
		return 1;
	}
	return 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	
	scanf("%d %d", &N, &C);
	arr.assign(N, 0);
	for (register int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end());
	int L = 0, R = arr[N - 1] - arr[0];
	while (L <= R) {
		int mid = (L + R) / 2;
		if (possible(mid)) L = mid + 1;
		else R = mid - 1;
	}
	printf("%d\n", R);
}