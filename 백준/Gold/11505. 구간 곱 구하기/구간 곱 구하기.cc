#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define MOD 1'000'000'007

vector<int> tree;

void update(int idx, const int &val) {
	tree[idx] = val;
	idx /= 2;
	while (idx >= 1) {
		tree[idx] = ((long long)tree[idx * 2] * tree[idx * 2 + 1]) % MOD;
		idx /= 2;
	}
}

int query(int left, int right) {
	int result = 1;
	while (left <= right) {
		if (left % 2 == 1) {
			result = ((long long)tree[left++] * result) % MOD;
			
		}
		if (right % 2 == 0) {
			result = ((long long)tree[right--] * result) % MOD;
		}
		left /= 2;
		right /= 2;
	}
	return result;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int size = 1;
	while (size < N) {
		size <<= 1;
	}
	tree.assign(size * 2, 1);
	for (register int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		update(i + size, n);
	}

	for (register int i = 0; i < M + K; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			int idx = b + size - 1;
			update(idx, c);
		}
		else {
			int left = b + size - 1;
			int right = c + size - 1;
			printf("%d\n", query(left, right));
		}
	}
}