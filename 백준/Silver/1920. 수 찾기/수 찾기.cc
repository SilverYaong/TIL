#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	int A[100000];
	for (register int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int M;
	scanf("%d", &M);
	sort(A, A + N);
	for (register int i = 0; i < M; i++) {
		int target;
		scanf("%d", &target);
		bool res = binary_search(A, A + N, target);
		if (res) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
}