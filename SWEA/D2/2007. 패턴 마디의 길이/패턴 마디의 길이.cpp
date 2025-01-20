#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t, ans;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string tmp;
        ans = 0;
        cin >> s;

        for (int j = 0; j < 10; j++)
        {
            tmp += s[j];
            if (tmp == s.substr(j + 1, j + 1))
            {
                ans = j + 1;
                break;
            }
        }

        cout << '#' << i + 1 << ' ' << ans << endl;
    }
}