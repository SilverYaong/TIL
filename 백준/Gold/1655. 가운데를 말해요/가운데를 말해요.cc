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
	priority_queue<int, vector<int>, greater<int>> lpq;
	priority_queue<int, vector<int>, less<int>> upq;
	while (N--) {
		int a;
		scanf("%d", &a);
		if (lpq.size() == upq.size()) {
			upq.push(a);
		}
		else {
			lpq.push(a);
		}
		if (lpq.empty()) {
			printf("%d\n", upq.top());
			continue;
		}
		if (upq.top() > lpq.top()) {
			int x = lpq.top(); lpq.pop();
			int y = upq.top(); upq.pop();
			lpq.push(y);
			upq.push(x);
		}
		printf("%d\n", upq.top());
	}
}