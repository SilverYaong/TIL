#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int arr[n][n];
    int pre_sum[n][n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            pre_sum[i][j] = arr[i][j];
            if (j != 0)
            {
                pre_sum[i][j] += pre_sum[i][j - 1];
            }
        }
    }

    int x1, x2, y1, y2;

    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (int j = 0; j <= x2 - x1; j++)
        {
            if (y1 != 1)
            {
                ans += pre_sum[x1 + j - 1][y2 - 1] - pre_sum[x1 + j - 1][y1 - 2];
            }
            else
            {
                ans += pre_sum[x1 + j - 1][y2 - 1];
            }
        }
        cout << ans << '\n';
    }
}