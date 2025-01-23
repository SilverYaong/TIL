#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int position[n][2];
    int ans = 0;
    bool array[100][100] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> position[i][j];
        }
        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 10; y++)
            {
                array[position[i][0] + x][position[i][1] + y] = true;
            }
        }
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (array[i][j])
                ans++;
        }
    }
    cout << ans;
}
