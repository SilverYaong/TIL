#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> arr;

int unifind(int x) {
	if (arr[x] != x) {
		return x = unifind(arr[x]);
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
	for (int i = 0; i < M; i++) {
		int c, a, b;
		scanf("%d %d %d", &c, &a, &b);
		switch (c)
		{
		case 0:
			uni(a, b);
			break;
		case 1:
			if (unifind(a) == unifind(b)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
			break;
		default:
			break;
		}
	}
}