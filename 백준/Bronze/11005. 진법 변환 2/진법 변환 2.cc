#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    map<int, char> table;
    for (int i = 0; i < 26; i++)
    {
        table.insert({i + 10, i + 65});
    }

    string ans;
    long long n;
    int b;
    cin >> n >> b;
    if (n == 0)
    {
        cout << "0";
        return 0;
    }
    do
    {
        if (n % b >= 10)
        {
            ans.insert(0, 1, table[n % b]);
        }
        else
        {
            ans.insert(0, to_string(n % b));
        }
        n /= b;
    } while (n > 0);

    cout << ans;
}
