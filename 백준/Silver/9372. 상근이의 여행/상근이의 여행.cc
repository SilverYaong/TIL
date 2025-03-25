#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> arr;

int main() {
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);
		arr.assign(N + 1, vector<int>());
		while (M--) {
			int a, b;
			scanf("%d %d", &a, &b);
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		printf("%d\n", N - 1);
	}
}