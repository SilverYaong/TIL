#include <iostream>

using namespace std;

int find_point(const int[][102], int);
void move_left(const int[][102], int, int &);
void move_right(const int[][102], int, int &);

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;

    for (int i = 0; i < 10; i++)
    {
        cin >> t;
        int ans;
        int ladder[100][102] = {
            0,
        };
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                cin >> ladder[j][k + 1];
            }
        }

        // 양끝이 패딩된 배열 출력
        // for (const auto &row : ladder)
        // {
        //     for (int col : row)
        //     {
        //         cout << col;
        //     }
        //     cout << endl;
        // }

        for (int j = 0; j < 102; j++)
        {
            if (ladder[99][j] == 2)
            {
                ans = find_point(ladder, j);
                break;
            }
        }

        cout << "#" << t << " " << ans - 1 << endl;
    }
}

int find_point(const int ladder[][102], int start_point)
{
    int col = start_point;
    for (int row = 99; row > 0; row--)
    {
        if (ladder[row][col - 1] == 1)
        {
            move_left(ladder, row, col);
        }
        else if (ladder[row][col + 1] == 1)
        {
            move_right(ladder, row, col);
        }
    }
    return col;
}

void move_left(const int ladder[][102], int row, int &col)
{
    col--;
    if (ladder[row][col - 1] == 1)
    {
        move_left(ladder, row, col);
    }
    return;
}

void move_right(const int ladder[][102], int row, int &col)
{
    col++;
    if (ladder[row][col + 1] == 1)
    {
        move_right(ladder, row, col);
    }
    return;
}