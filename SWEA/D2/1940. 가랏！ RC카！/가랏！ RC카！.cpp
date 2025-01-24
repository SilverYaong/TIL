#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int speed = 0;
        int ans = 0;
        cin >> n;
        int command[n][2];
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            command[j][0] = tmp;
            if (tmp == 0)
            {
                continue;
            }
            else
            {
                cin >> command[j][1];
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (command[j][0] == 0)
            {
                ans += speed;
            }
            else if (command[j][0] == 1)
            {
                speed += command[j][1];
                ans += speed;
            }
            else
            {
                speed -= command[j][1];
                if (speed < 0)
                    speed = 0;
                ans += speed;
            }
        }
        cout << "#" << i + 1 << " " << ans << endl;
    }
}
