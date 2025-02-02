#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int test_case;
    string word, str;

    for (int t = 0; t < 10; t++)
    {
        cin >> test_case;
        int ans = 0;
        cin >> word >> str;
        int n = word.length();

        for (int i = 0; i < str.length(); i++)
        {
            if (word[0] == str[i])
            {
                if (str.substr(i, n) == word)
                {
                    ans++;
                }
            }
        }

        cout << "#" << test_case << " " << ans << endl;
    }
}