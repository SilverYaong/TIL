#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t, money;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> money;

        int _25 = 0;
        int _10 = 0;
        int _05 = 0;
        int _01 = 0;

        if (money >= 25)
        {
            _25 = money / 25;
            money %= 25;
        }
        if (money >= 10)
        {
            _10 = money / 10;
            money %= 10;
        }
        if (money >= 5)
        {
            _05 = money / 5;
            money %= 5;
        }
        _01 = money;

        cout << _25 << " " << _10 << " " << _05 << " " << _01 << endl;
    }
}
