#include <iostream>

using namespace std;

int arr[64][64];
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
                cout << "(";
                sol(row, col, num / 2);
                sol(row, col + (num / 2), num / 2);
                sol(row + (num / 2), col, num / 2);
                sol(row + num / 2, col + num / 2, num / 2);
                cout << ")";
                return;
            }
        }
    }
    cout << color;

    return;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = s[j] - '0';
        }
    }
    sol(0, 0, n);
}
