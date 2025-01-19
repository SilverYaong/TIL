#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        int ans = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            if (j % 2 == 0)
            {
                ans += j + 1;
            }
            else
            {
                ans -= j + 1;
            }
        }
        cout << '#' << i + 1 << ' ' << ans << endl;
    }
}