#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    //freopen("sample_input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({ e, w });
    }

    int start, end;
    cin >> start >> end;

    vector<int> dist(N + 1, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost) continue;
        for (auto next : graph[cur]) {
            int next_cost = cost + next.second;
            if (next_cost < dist[next.first]) {
                dist[next.first] = next_cost;
                pq.push({ -next_cost, next.first });
            }
        }
    }
    cout << dist[end] << endl;
    return 0;
}