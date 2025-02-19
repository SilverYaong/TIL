#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int ans;

void sol(vector<int> uv[], vector<bool> &visited, int num, int dist)
{
    ans = max(ans, dist);

    for (int nxt : uv[num])
    {
        if (!visited[nxt])
        {
            visited[nxt] = 1;
            sol(uv, visited, nxt, dist + 1);
            visited[nxt] = 0;
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
        ans = 1;
        int n, m;
        cin >> n >> m;

        vector<int> uv[n];

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            uv[u - 1].push_back(v - 1);
            uv[v - 1].push_back(u - 1);
        }

        for (int i = 0; i < n; i++)
        {
            vector<bool> visited(n + 1, false);
            visited[i] = 1;
            sol(uv, visited, i, 1);
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}