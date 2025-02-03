#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int len;

    for (int t = 0; t < 10; t++)
    {
        string table;
        int ans = 0;
        cin >> len;
        for (int i = 0; i < 8; i++)
        {
            string tmp;
            cin >> tmp;
            table.append(tmp);
        }

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (j + len <= 8)
                {
                    string tmp, rtmp;
                    tmp = table.substr(j + i * 8, len);
                    rtmp = tmp;
                    reverse(rtmp.begin(), rtmp.end());
                    if (tmp == rtmp)
                    {
                        ans++;
                    }
                }

                if (i + len <= 8)
                {
                    string tmp, rtmp;
                    for (int k = 0; k < len; k++)
                    {
                        tmp += table[(j + i * 8) + k * 8];
                    }
                    rtmp = tmp;
                    reverse(rtmp.begin(), rtmp.end());

                    if (tmp == rtmp)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << "#" << t + 1 << " " << ans << endl;
    }
}