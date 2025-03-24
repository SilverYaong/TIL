#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	if (N == 1) {
		printf("0");
		return 0;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	while (N--) {
		int x;
		scanf("%d", &x);
		pq.push(x);
	}
	int ans = 0;
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	printf("%d", ans);
}