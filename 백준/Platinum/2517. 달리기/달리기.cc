#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class FenwickTree {
	vector<int> tree;
	int n;
public:
	FenwickTree(int n) : n(n) {
		tree.assign(n + 1, 0);
	}
	void update(int index, int delta) {
		while (index <= n) {
			tree[index] += delta;
			index += index & -index;
		}
	}
	int query(int index) {
		int sum = 0;
		while (index > 0) {
			sum += tree[index];
			index -= index & -index;
		}
		return sum;
	}
};

int main() {
	int N;
	scanf("%d", &N);
	vector<long long> arr(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	vector<long long> sorted = arr;
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	int size = sorted.size();
	FenwickTree ft(size);

	for (int i = 0; i < N; i++) {
		int idx = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() + 1;
		int greaterCount = ft.query(size) - ft.query(idx);
		printf("%d\n", greaterCount + 1);
		ft.update(idx, 1);
	}
}
