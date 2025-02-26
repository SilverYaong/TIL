#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int total_dist = 0;
    long long total_cost;
    int dist_arr[100000];
    int cost_arr[100000];
    int n;
    int min_cost = 1000000001;
    int min_cost_idx;
    int current_cost;
    int dist_left;

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> dist_arr[i];
        total_dist += dist_arr[i];
    }

    dist_arr[n] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> cost_arr[i];
        if (min_cost > cost_arr[i])
        {
            min_cost = cost_arr[i];
            min_cost_idx = i;
        }
    }

    dist_left = total_dist - dist_arr[0];
    total_cost = cost_arr[0] * dist_arr[0];
    current_cost = cost_arr[0];

    for (int i = 1; i < n; i++)
    {
        if (i == min_cost_idx)
        {
            total_cost += dist_left * min_cost;
            break;
        }
        if (current_cost > cost_arr[i])
        {
            current_cost = cost_arr[i];
        }
        dist_left -= dist_arr[i];
        total_cost += current_cost * dist_arr[i];
    }

    cout << total_cost;
}