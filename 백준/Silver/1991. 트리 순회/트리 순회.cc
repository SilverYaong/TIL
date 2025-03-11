#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int lc[27];
int rc[27];

void preorder(int cur) {
	printf("%c", cur + 'A' - 1);
	if (lc[cur] != 0) preorder(lc[cur]);
	if (rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) {
	if (lc[cur] != 0) inorder(lc[cur]);
	printf("%c", cur + 'A' - 1);
	if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) {
	if (lc[cur] != 0) postorder(lc[cur]);
	if (rc[cur] != 0) postorder(rc[cur]);
	printf("%c", cur + 'A' - 1);
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		char c, l, r;
		scanf(" %c %c %c", &c, &l, &r);
		if (l != '.') lc[c - 'A' + 1] = l - 'A' + 1;
		if (r != '.') rc[c - 'A' + 1] = r - 'A' + 1;
	}
	preorder(1);
	printf("\n");
	inorder(1);
	printf("\n");
	postorder(1);
	printf("\n");
}