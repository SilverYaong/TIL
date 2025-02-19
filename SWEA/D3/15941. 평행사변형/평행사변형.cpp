#include <iostream>
using namespace std;

int ans;
int n;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		cin >> n;
		ans = n * n;

		cout << '#' << t + 1 << ' ' << ans << '\n';
	}
}