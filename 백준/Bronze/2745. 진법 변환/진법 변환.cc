#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    map<char, int> table;
    for (int i = 0; i < 26; i++)
    {
        table.insert({i + 65, i + 10});
    }
    for (int i = 0; i < 10; i++)
    {
        table.insert({i + 48, i});
    }

    long long ans = 0;
    string n;
    int b;
    cin >> n >> b;
    int j = 0;
    for (int i = n.length() - 1; i >= 0; i--)
    {
        if (n[i] >= 65)
        {
            ans += table[n[i]] * pow(b, j);
        }
        else
        {
            ans += table[n[i]] * pow(b, j);
        }
        j++;
    }
    cout << ans;
}
