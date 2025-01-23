#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long t, a, b, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> n;
        int j = 0;
        while (a <= n && b <= n)
        {
            if (a < b)
                a += b;
            else if (b < a)
                b += a;
            else
                a += b;
            j++;
        }
        cout << j << endl;
    }
}
