#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, n, k, ans;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ans = 0;
        cin >> n >> k;
        int array[n][n];
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
            {
                cin >> array[j][l];
            }
        }
        for (int j = 0; j < n; j++)
        {
            int start = 0;
            int end;
            string tmp;
            for (int l = 0; l < n; l++)
            {
                tmp += to_string(array[j][l]);
            }
            while (true)
            {
                start = tmp.find('1', start);
                if (start == string::npos)
                    break;

                end = tmp.find('0', start);
                if (end == string::npos)
                {
                    if (tmp.substr(start).size() == k)
                        ans++;
                    break;
                }
                else
                {
                    if (tmp.substr(start, end - start).size() == k)
                        ans++;
                    start = end;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            int start = 0;
            int end;
            string tmp;
            for (int l = 0; l < n; l++)
            {
                tmp += to_string(array[l][j]);
            }
            while (true)
            {
                start = tmp.find('1', start);
                if (start == string::npos)
                    break;

                end = tmp.find('0', start);
                if (end == string::npos)
                {
                    if (tmp.substr(start).size() == k)
                        ans++;
                    break;
                }
                else
                {
                    if (tmp.substr(start, end - start).size() == k)
                        ans++;
                    start = end;
                }
            }
        }
        cout << "#" << i + 1 << " " << ans << endl;
    }
}