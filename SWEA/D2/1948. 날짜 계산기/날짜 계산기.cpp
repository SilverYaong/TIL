#include <stdio.h>
#include <map>
#include <string>

using namespace std;

map<string, int> month_to_day = {
    {"1", 31},
    {"2", 28},
    {"3", 31},
    {"4", 30},
    {"5", 31},
    {"6", 30},
    {"7", 31},
    {"8", 31},
    {"9", 30},
    {"10", 31},
    {"11", 30},
    {"12", 31}};

int main()
{
    int t, ans, month_1, month_2, day_1, day_2;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int ans = 0;
        scanf("%d %d %d %d", &month_1, &day_1, &month_2, &day_2);
        do
        {
            if (ans == 0)
            {
                if (month_1 == month_2)
                {
                    ans += day_2 - day_1 + 1;
                }
                else
                {
                    ans += month_to_day[to_string(month_1)] - day_1 + day_2 + 1;
                }
            }
            else if (month_1 != month_2)
            {
                ans += month_to_day[to_string(month_1)];
            }
            ++month_1;
        } while (month_1 <= month_2);
        printf("#%d %d\n", i + 1, ans);
    }
}
