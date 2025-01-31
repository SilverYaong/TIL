#include <iostream>

using namespace std;

int max_score;
int current_score;

void subsets(const int score[], const int calorie[], const int limit, const int size)
{
    int total = 1 << size;

    for (int i = 0; i < total; i++)
    {
        int calorie_sum = 0;
        int score_sum = 0;
        for (int j = 0; j < size; j++)
        {
            if (i & (1 << j))
            {
                score_sum += score[j];
                calorie_sum += calorie[j];
            }
        }
        if (calorie_sum > limit)
        {
            continue;
        }
        else if (max_score < score_sum)
        {
            max_score = score_sum;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int test_case = 0; test_case < t; test_case++)
    {
        max_score = 0;
        int ans, n, limit;
        cin >> n >> limit;
        int score[n], calorie[n];
        for (int i = 0; i < n; i++)
        {
            cin >> score[i] >> calorie[i];
        }

        subsets(score, calorie, limit, n);
        cout << "#" << test_case + 1 << " " << max_score << endl;
    }
}
