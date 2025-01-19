#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, ans;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s1, s2;
        cin >> s1;
        for (int j = s1.size(); j > 0; j--)
        {
            s2 += s1[j - 1];
        }
        if (s1 == s2)
            ans = 1;
        else
            ans = 0;

        cout << '#' << i + 1 << ' ' << ans << endl;
    }
}