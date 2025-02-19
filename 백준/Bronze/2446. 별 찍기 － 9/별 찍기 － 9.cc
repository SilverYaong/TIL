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
        for (int j = -n + 1; j < abs(i) + 1; j++)
        {
            if (abs(j) <= abs(i))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << '\n';
    }
}
