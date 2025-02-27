#include <iostream>

using namespace std;

int white, blue = 0;
int arr[128][128];
int n;

void sol(int row, int col, int num)
{
    int color = arr[row][col];

    for (int i = row; i < num + row; i++)
    {
        for (int j = col; j < num + col; j++)
        {
            if (arr[i][j] != color)
            {
                sol(row, col, num / 2);
                sol(row + (num / 2), col, num / 2);
                sol(row, col + (num / 2), num / 2);
                sol(row + num / 2, col + num / 2, num / 2);
                return;
            }
        }
    }
    if (color == 1)
    {
        blue++;
    }
    else
    {
        white++;
    }
    return;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    sol(0, 0, n);
    cout << white << '\n'
         << blue;
}
