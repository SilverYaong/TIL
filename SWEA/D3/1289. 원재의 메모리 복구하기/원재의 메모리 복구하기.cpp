#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc, ans;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        ans = 0;
        string s;
        cin >> s;
        int n = s.length();
        int prev = s[0] - '0';
        if (prev == 1)
        {
            ans++;
        }

        for (int i = 1; i < n; i++)
        {
            if (prev == s[i] - '0')
            {
                continue;
            }
            ans++;
            prev = s[i] - '0';
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}