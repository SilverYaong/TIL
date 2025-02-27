#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m;
    int arrA[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arrA[i][j];
        }
    }
    cin >> m >> k;
    int arrB[m][k];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> arrB[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int sum = 0;
            for (int l = 0; l < m; l++)
            {
                sum += arrA[i][l] * arrB[l][j];
            }
            cout << sum << " ";
        }
        cout << '\n';
    }
}
