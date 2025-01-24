#include <iostream>
#include <map>

using namespace std;

map<string, int> password = {
    {"0001101", 0},
    {"0011001", 1},
    {"0010011", 2},
    {"0111101", 3},
    {"0100011", 4},
    {"0110001", 5},
    {"0101111", 6},
    {"0111011", 7},
    {"0110111", 8},
    {"0001011", 9}};

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int ans = 0;
        cin >> n >> m;

        string code;
        string passcode;
        bool found = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> code;
            for (int k = m - 1; k >= 0; k--)
            {
                if (found)
                    break;
                else if (code[k] == '1')
                {
                    passcode = code.substr(k - 55, 56);
                    found = 1;
                    break;
                }
            }
        }
        int odd = 0, even = 0;
        for (int j = 0; j < 8; j++)
        {
            if ((j + 1) % 2 == 0)
            {
                even += password[passcode.substr(j * 7, 7)];
            }
            else
            {
                odd += password[passcode.substr(j * 7, 7)];
            }
        }
        ans = (odd * 3) + even;
        if (ans % 10 != 0)
            ans = 0;
        else
            ans = odd + even;
        cout << "#" << i + 1 << " " << ans << endl;
    }
}