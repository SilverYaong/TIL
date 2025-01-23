#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int array[9][9];
    int max = -1;
    int row, col;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> array[i][j];
            if (array[i][j] > max)
            {
                max = array[i][j];
                row = i + 1;
                col = j + 1;
            }
        }
    }
    cout << max << endl;
    cout << row << " " << col;
}
