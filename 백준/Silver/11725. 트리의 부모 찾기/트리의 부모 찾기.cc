#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> arr[100001];
int p[100001];

void dfs(int cur) {
	for (int nxt : arr[cur]) {
		if (p[cur] == nxt) continue;
		p[nxt] = cur;
		dfs(nxt);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= N; i++)
	{
		printf("%d\n", p[i]);
	}
}