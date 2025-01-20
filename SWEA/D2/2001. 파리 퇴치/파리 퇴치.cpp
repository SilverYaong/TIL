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
        int matrix[n][n];
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> matrix[j][k];
            }
        }
        for (int j = 0; j < n - m + 1; j++)
        {
            for (int k = 0; k < n - m + 1; k++)
            {
                int tmp = 0;
                for (int jj = 0; jj < m; jj++)
                {
                    for (int kk = 0; kk < m; kk++)
                    {
                        tmp += matrix[j + jj][k + kk];
                    }
                }
                if (tmp > ans)
                    ans = tmp;
            }
        }
        cout << "#" << i + 1 << " " << ans << endl;
    }
}