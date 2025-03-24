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

Group arr[200001];
unordered_map<string, int> id;
int num;

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
	int TC, F;
	scanf("%d", &TC);
	for (int t = 0; t < TC; t++) {
		id.clear();
		num = 1;
		scanf("%d", &F);
		for (int i = 0; i < F; i++) {
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
			int root = unifind(id[a]);
			printf("%d\n", arr[root].size);
		}
	}
}