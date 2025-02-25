#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int arr[10];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (k < 5)
        {
            ans += k;
            break;
        }
        ans += k / arr[i];
        k %= arr[i];
    }

    cout << ans;
}