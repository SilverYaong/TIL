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
	priority_queue<int, vector<int>, greater<int>> pq;
	for (register int i = 0; i < N; i++) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 0) {
			if (!pq.empty()) {
				printf("%d\n", pq.top());
				pq.pop();
			}
			else {
				printf("0\n");
			}
		}
		else {
			pq.push(cmd);
		}
	}
}