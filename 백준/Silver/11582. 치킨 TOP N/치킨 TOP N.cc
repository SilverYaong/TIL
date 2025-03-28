#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int N, K;
vector<int> arr;

void merge(int l, int r) {
	if (r - l > N / K) return;
	int i = l;
	int mid = (l + r) / 2;
	int j = mid + 1;
	int k = 0;
	vector<int> res(r - l + 1);
	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j]) {
			res[k++] = arr[i++];
		}
		else {
			res[k++] = arr[j++];
		}
	}

	while (i <= mid) res[k++] = arr[i++];
	while (j <= r) res[k++] = arr[j++];

	for (register int t = 0; t < k; t++) arr[l + t] = res[t];
}

void merge_sort(int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		merge_sort(l, mid);
		merge_sort(mid + 1, r);
		merge(l, r);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	arr.assign(N, 0);
	for (register int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	
	scanf("%d", &K);
	merge_sort(0, N - 1);

	for (register int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
}