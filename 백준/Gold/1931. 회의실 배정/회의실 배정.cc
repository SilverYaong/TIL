#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][1] >> arr[i][0];
    }
    int ans = 0;
    sort(arr.begin(), arr.end());
    int endtime = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i][1] >= endtime)
        {
            endtime = arr[i][0];
            ans++;
        }
    }
    cout << ans;
}