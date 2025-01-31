#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const vector<int> score, const vector<int> calorie, const int limit, const int size)
{
    vector<int> dp(limit + 1, 0);

    for (int i = 0; i < size; i++)
    {
        for (int j = limit; j >= calorie[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - calorie[i]] + score[i]);
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int test_case = 0; test_case < t; test_case++)
    {
        int ans, n, limit;
        cin >> n >> limit;
        vector<int> score(n), calorie(n);
        for (int i = 0; i < n; i++)
        {
            cin >> score[i] >> calorie[i];
        }

        ans = solve(score, calorie, limit, n);
        cout << "#" << test_case + 1 << " " << ans << endl;
    }
}
