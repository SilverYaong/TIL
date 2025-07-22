#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	string data;
	Node* head = nullptr;
	Node* tail = nullptr;
};

Node nodes[500001];
Node* nodeTail[500001];

void connect(int a, int b)
{
	Node* A = &nodes[a];
	Node* B = &nodes[b];

	Node* tailA = nodeTail[a];
	tailA->tail = B;
	B->head = tailA;
	nodeTail[a] = nodeTail[b];
}

int main()
{
	// freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nodes[i].data;
		nodeTail[i] = &nodes[i];
	}
	
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		connect(a, b);
	}
	Node* ptr = &nodes[1];
	while (ptr->head != nullptr)
	{
		ptr = ptr->head;
	}
	while (ptr != nullptr)
	{
		cout << ptr->data;
		ptr = ptr->tail;
	}
}