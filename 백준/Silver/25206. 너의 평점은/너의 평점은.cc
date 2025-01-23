#include <iostream>
#include <sstream>
#include <map>

using namespace std;

map<string, float> grade_table =
    {
        {"A+", 4.5},
        {"A0", 4.0},
        {"B+", 3.5},
        {"B0", 3.0},
        {"C+", 2.5},
        {"C0", 2.0},
        {"D+", 1.5},
        {"D0", 1.0},
        {"F", 0.0}};

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string subject[20];
    float credit[20];
    float total_credit = 0;
    double score = 0;
    double ans = 0;
    string grade[20];

    for (int i = 0; i < 20; i++)
    {
        cin >> subject[i] >> credit[i] >> grade[i];
        if (grade[i] != "P")
        {
            total_credit += credit[i];
            score += credit[i] * grade_table[grade[i]];
        }
    }
    if (score != 0)
        ans = score / total_credit;
    cout.precision(7);
    cout.setf(ios::showpoint);
    cout << ans;
}
