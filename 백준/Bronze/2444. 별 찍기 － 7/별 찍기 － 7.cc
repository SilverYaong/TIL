#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = -n + 1; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1 - abs(i); j++)
        {
            if (j >= abs(i))
            {
                cout << '*';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}