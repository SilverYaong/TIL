#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int test_case;

    for (int t = 0; t < 10; t++)
    {
        string table;
        int ans = 0;
        int max_len = 1;
        cin >> test_case;
        for (int i = 0; i < 100; i++)
        {
            string tmp;
            cin >> tmp;
            table.append(tmp);
        }

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                if (j > 100 - max_len)
                {
                    break;
                }
                for (int k = 99; k > j; k--)
                {
                    if (k < max_len)
                    {
                        break;
                    }

                    if (table[j + i * 100] == table[i * 100 + k])
                    {
                        string tmp, rtmp;
                        tmp = table.substr(j + i * 100, k - j + 1);
                        rtmp = tmp;
                        reverse(rtmp.begin(), rtmp.end());
                        if (tmp == rtmp && tmp.length() > max_len)
                        {
                            max_len = tmp.length();
                            break;
                        }
                    }
                    if (table[i + j * 100] == table[k * 100 + i])
                    {
                        string tmp, rtmp;
                        for (int kk = 0; kk <= k - j; kk++)
                        {
                            tmp += table[i + (j + kk) * 100];
                        }
                        rtmp = tmp;
                        reverse(rtmp.begin(), rtmp.end());
                        if (tmp == rtmp && tmp.length() > max_len)
                        {
                            max_len = tmp.length();
                            break;
                        }
                    }
                }
            }
        }

        cout << "#" << test_case << " " << max_len << endl;
    }
}