#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        char str[n];
        int count[n];
        string result;
        for (int j = 0; j < n; j++)
        {
            cin >> str[j] >> count[j];
            result.append(count[j], str[j]);
        }

        cout << "#" << i + 1 << endl;

        for (int j = 0; j < result.length(); j++)
        {
            cout << result[j];
            if ((j + 1) % 10 == 0)
            {
                cout << endl;
            }
        }
        cout << endl;
    }
}
