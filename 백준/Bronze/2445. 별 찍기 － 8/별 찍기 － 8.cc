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
        int star = n - abs(i);
        int space = 2 * abs(i);

        for (int j = 0; j < star; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < star; j++)
        {
            cout << "*";
        }
        cout << '\n';
    }
}