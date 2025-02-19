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
    for (int t = 1; t <= tc; t++)
    {
        cin >> n;
        ans = 0;
        int arr[n][n];
        string val;
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = val[j] - '0';
            }
        }
        for (int i = -n / 2; i < n / 2 + 1; i++)
        {
            for (int j = abs(i); j < n - abs(i); j++)
            {
                ans += arr[i + n / 2][j];
            }
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}