#include <iostream>

using namespace std;

int main()
{
    int t;
    int n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << "#" << i + 1 << " " << endl;
        int count = 1;
        int matrix[n][n];
        int up = 0, down = n - 1, left = 0, right = n - 1;
        while (up <= down && left <= right)
        {
            for (int j = left; j <= right; ++j)
            {
                matrix[up][j] = count++;
            }
            up++;

            for (int j = up; j <= down; ++j)
            {
                matrix[j][right] = count++;
            }
            right--;

            for (int j = right; j >= left; --j)
            {
                matrix[down][j] = count++;
            }
            down--;

            for (int j = down; j >= up; --j)
            {
                matrix[j][left] = count++;
            }
            left++;
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << matrix[j][k];
                if (k != n)
                    cout << " ";
            }
            cout << endl;
        }
    }
}