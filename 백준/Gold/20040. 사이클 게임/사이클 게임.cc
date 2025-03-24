#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
int ans = 0;

int unifind(int x) {
	if (arr[x] != -1) {
		return arr[x] = unifind(arr[x]);
	}
	return x;
}

bool uni(int x, int y) {
	x = unifind(x);
	y = unifind(y);
	if (x == y) {
		return true;
	}
	if (arr[x] < arr[y]) {
		swap(x, y);
	}
	arr[y] = x;
	return false;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	arr.assign(N, -1);
	for (register int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		bool result = uni(a, b);
		if (result) {
			ans = i;
			break;
		}
	}
	printf("%d", ans);
}