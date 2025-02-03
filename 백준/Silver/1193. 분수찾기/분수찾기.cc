#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, row = 1;
    cin >> n;
    int i, j;
    while ((row * (row + 1)) / 2 < n)
    {
        row++;
    }
    int prev_sum = (row * (row - 1)) / 2;
    int col = n - prev_sum;
    if (row % 2 == 0)
    {
        i = col;
        j = row - col + 1;
    }
    else
    {
        j = col;
        i = row - col + 1;
    }

    cout << i << "/" << j << "\n";
}
