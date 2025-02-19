#include <iostream>
#include <vector>

using namespace std;

int black, white;
int n, m;
const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

void sol(int idx, int row, int col, int color, vector<vector<int>> &arr)
{
    for (int d = 0; d < 8; d++)
    {
        int nx = row + dx[d];
        int ny = col + dy[d];
        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            if ((color == 1 && arr[nx][ny] == 2) || (color == 2 && arr[nx][ny] == 1))
            {
                int nxx = nx + dx[d];
                int nyy = ny + dy[d];
                while (0 <= nxx && nxx < n && 0 <= nyy && nyy < n)
                {
                    if (arr[nxx][nyy] == color)
                    {
                        while (nxx != nx || nyy != ny)
                        {
                            nxx -= dx[d];
                            nyy -= dy[d];
                            arr[nxx][nyy] = color;
                        }
                        break;
                    }
                    else if (arr[nxx][nyy] == 0)
                    {
                        break;
                    }
                    else
                    {
                        nxx += dx[d];
                        nyy += dy[d];
                    }
                }
            }
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        cin >> n >> m;
        black = white = 0;
        vector<vector<int>> arr(n, vector<int>(n, 0));
        arr[n / 2 - 1][n / 2 - 1] = 2;
        arr[n / 2][n / 2] = 2;
        arr[n / 2][n / 2 - 1] = 1;
        arr[n / 2 - 1][n / 2] = 1;

        for (int i = 0; i < m; i++)
        {
            int r, c, color;
            cin >> r >> c >> color;
            arr[r - 1][c - 1] = color;
            sol(0, r - 1, c - 1, color, arr);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 1)
                {
                    black++;
                }
                else if (arr[i][j] == 2)
                {
                    white++;
                }
            }
        }

        cout << "#" << t << " " << black << " " << white << '\n';
    }
}