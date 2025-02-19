#include <iostream>

using namespace std;

int ans;

void sol(int idx, const int n, const int k, const int arr[], bool isused[], int val)
{
    if (val == k)
    {
        ans++;
        return;
    }
    else if (val > k)
    {
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (!isused[i])
        {
            isused[i] = 1;
            sol(i + 1, n, k, arr, isused, val + arr[i]);
            isused[i] = 0;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        int n, k;
        ans = 0;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool isused[n] = {0};

        sol(0, n, k, arr, isused, 0);

        cout << '#' << t << ' ' << ans << '\n';
    }
}