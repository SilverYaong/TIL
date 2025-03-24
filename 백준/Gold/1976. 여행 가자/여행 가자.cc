#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> arr;

int unifind(int x) {
	if (arr[x] != x) {
		return arr[x] = unifind(arr[x]);
	}
	return x;
}

void uni(int x, int y) {
	x = unifind(x);
	y = unifind(y);
	if (x == y) {
		return;
	}
	arr[y] = x;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	for (register int i = 0; i <= N; i++) {
		arr.push_back(i);
	}
	for (register int i = 1; i <= N; i++) {
		for (register int j = 1; j <= N; j++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 1) {
				uni(i, j);
			}
		}
	}
	int a, b;
	scanf("%d", &a);
	bool flag = false;
	for (register int i = 1; i < M; i++) {
		scanf("%d", &b);
		if (unifind(a) != unifind(b)) {
			flag = true;
			break;
		}
	}
	if (flag) {
		printf("NO");
	}
	else {
		printf("YES");
	}
}