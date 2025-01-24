#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 10; i++)
    {
        int n, ans = 0;
        cin >> n;
        int array[n];
        for (int j = 0; j < n; j++)
        {
            cin >> array[j];
        }
        for (int j = 2; j < n - 2; j++)
        {
            for (int k = array[j]; k > 0; k--)
            {
                if (k > array[j - 1] && k > array[j + 1])
                {
                    if (k > array[j - 2] && k > array[j + 2])
                        ans++;
                    else
                        break;
                }
                else
                    break;
            }
        }
        cout << "#" << i + 1 << " " << ans << endl;
    }
}
