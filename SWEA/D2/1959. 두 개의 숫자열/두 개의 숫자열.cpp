#include <iostream>

using namespace std;

int main()
{
    int t, n, m, ans;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ans = 0;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        for (int j = 0; j < m; j++)
        {
            cin >> b[j];
        }
        for (int j = 0; j < abs(m - n) + 1; j++)
        {
            int tmp = 0;
            for (int k = 0; k < min(n, m); k++)
            {
                if (n > m)
                {
                    tmp += a[j + k] * b[k];
                }
                else
                {
                    tmp += a[k] * b[j + k];
                }
            }
            if (tmp > ans)
                ans = tmp;
        }
        cout << '#' << i + 1 << ' ' << ans << endl;
    }
}