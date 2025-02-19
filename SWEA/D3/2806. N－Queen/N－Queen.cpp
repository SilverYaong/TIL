#include <iostream>
using namespace std;

int ans;
int n;

void sol(int idx, bool chk1[], bool chk2[], bool chk3[])
{
	if (idx == n)
	{
		ans++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (chk1[i] || chk2[i + idx] || chk3[idx - i + n - 1])
			continue;
		chk1[i] = 1;
		chk2[i + idx] = 1;
		chk3[idx - i + n - 1] = 1;
		sol(idx + 1, chk1, chk2, chk3);
		chk1[i] = 0;
		chk2[i + idx] = 0;
		chk3[idx - i + n - 1] = 0;
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		cin >> n;
		ans = 0;
		bool chk1[n] = {};
		bool chk2[2 * n - 1] = {};
		bool chk3[2 * n - 1] = {};
		
		sol(0, chk1, chk2, chk3);

		cout << '#' << t + 1 << ' ' << ans << '\n';
	}
}