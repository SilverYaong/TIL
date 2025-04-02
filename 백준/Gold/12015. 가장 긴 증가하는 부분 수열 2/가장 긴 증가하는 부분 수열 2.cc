#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int N;
	int arr[1000001];
	vector<int> v;
	scanf("%d %d", &N, &arr[0]);
	v.push_back(arr[0]);
	for (register int i = 1; i < N; i++) {
		scanf("%d", &arr[i]);
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[idx] = arr[i];
		}
	}
	printf("%d\n", v.size());
}