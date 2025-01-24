#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int matrix[n][n];
        int _90[n][n], _180[n][n], _270[n][n];

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> matrix[j][k];
                _90[k][n - 1 - j] = matrix[j][k];
                _180[n - 1 - j][n - 1 - k] = matrix[j][k];
                _270[n - 1 - k][j] = matrix[j][k];
            }
        }

        cout << "#" << i + 1 << endl;

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << _90[j][k];
            }
            cout << " ";
            for (int k = 0; k < n; k++)
            {
                cout << _180[j][k];
            }
            cout << " ";
            for (int k = 0; k < n; k++)
            {
                cout << _270[j][k];
            }
            cout << endl;
        }
    }
}
