#include <iostream>

using namespace std;

void find_point(const int[][102], int);
void move_left(const int[][102], int, int &, int &);
void move_right(const int[][102], int, int &, int &);

int min_count;
int ans;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;

    for (int i = 0; i < 10; i++)
    {
        cin >> t;
        ans = 0;
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

        min_count = 9999;

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
            if (ladder[0][j] == 1)
            {
                find_point(ladder, j);
            }
        }

        cout << "#" << t << " " << ans << endl;
    }
}

void find_point(const int ladder[][102], int start_point)
{
    int col = start_point;
    int count = 0;
    for (int row = 0; row < 100; row++)
    {
        // cout << "현재 위치 : " << row << ", " << col << endl;
        if (ladder[row][col - 1] == 1)
        {
            move_left(ladder, row, col, count);
        }
        else if (ladder[row][col + 1] == 1)
        {
            move_right(ladder, row, col, count);
        }
        count++;
    }
    // cout << "이동 횟수 : " << count << endl;
    // cout << "열 : " << start_point - 1 << endl;
    if (min_count >= count)
    {
        min_count = count;
        ans = start_point - 1;
    }
    return;
}

void move_left(const int ladder[][102], int row, int &col, int &count)
{
    col--;
    count++;
    // cout << "왼쪽으로 이동 : " << row << ", " << col << endl;
    if (ladder[row][col - 1] == 1)
    {
        move_left(ladder, row, col, count);
    }
    return;
}

void move_right(const int ladder[][102], int row, int &col, int &count)
{
    col++;
    count++;
    // cout << "오른쪽으로 이동 : " << row << ", " << col << endl;
    if (ladder[row][col + 1] == 1)
    {
        move_right(ladder, row, col, count);
    }
    return;
}