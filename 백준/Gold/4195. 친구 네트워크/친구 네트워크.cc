#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

struct Group {
	int rep;
	int size;
	Group() : rep(-1), size(1) {}
};

const int MAX = 200001;
Group arr[MAX];

int unifind(int x) {
	if (arr[x].rep != -1) {
		return arr[x].rep = unifind(arr[x].rep);
	}
	return x;
}

void uni(int x, int y) {
	x = unifind(x);
	y = unifind(y);
	if (x == y) {
		return;
	}
	if (arr[x].size < arr[y].size) {
		swap(x, y);
	}
	arr[y].rep = x;
	arr[x].size += arr[y].size;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (register int t = 0; t < TC; t++) {
		unordered_map<string, int> id;
		id.reserve(MAX);
		int num = 1;
		int F;
		scanf("%d", &F);
		for (register int i = 0; i < F; i++) {
			char a[21], b[21];
			scanf("%s %s", a, b);
			if (id.find(a) == id.end()) {
				arr[num].rep = -1;
				arr[num].size = 1;
				id[a] = num++;
			}
			if (id.find(b) == id.end()) {
				arr[num].rep = -1;
				arr[num].size = 1;
				id[b] = num++;
			}
			uni(id[a], id[b]);
			printf("%d\n", arr[unifind(id[a])].size);
		}
	}
}