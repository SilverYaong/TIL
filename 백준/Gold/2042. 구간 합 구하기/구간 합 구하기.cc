#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<long long> tree;

void update(long long idx, const long long &val) {
	if (idx < 1) return;
	tree[idx] += val;
	update(idx / 2, val);
}

long long query(long long &left, long long &right) {
	long long result = 0;
	while (left <= right) {
		if (left % 2 == 1) {
			result += tree[left];
			left = (left + 1) / 2;
		}
		else {
			left /= 2;
		}
		if (right % 2 == 0) {
			result += tree[right];
			right = (right - 1) / 2;
		}
		else {
			right /= 2;
		}
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
	tree.assign(size * 2, 0);
	for (register int i = 0; i < N; i++) {
		long long n;
		scanf("%lld", &n);
		update(i + size, n);
	}
	for (register int i = 0; i < M + K; i++) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			long long idx = b + size - 1;
			long long diff = c - tree[idx];
			update(idx, diff);
		}
		else {
			long long left = b + size - 1;
			long long right = c + size - 1;
			printf("%lld\n", query(left, right));
		}
	}
}