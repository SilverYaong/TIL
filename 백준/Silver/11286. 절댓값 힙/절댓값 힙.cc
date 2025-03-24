#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;


struct comp {
	bool operator ()(const int &a, const int &b) const {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};


int main()
{
	//freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	priority_queue<int, vector<int>, comp> pq;
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