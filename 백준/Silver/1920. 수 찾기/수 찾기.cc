#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <set>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	multiset<int> A;
	for (register int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		A.insert(a);
	}
	int M;
	scanf("%d", &M);
	for (register int i = 0; i < M; i++) {
		int target;
		scanf("%d", &target);
		if (A.find(target) != A.end()) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
}