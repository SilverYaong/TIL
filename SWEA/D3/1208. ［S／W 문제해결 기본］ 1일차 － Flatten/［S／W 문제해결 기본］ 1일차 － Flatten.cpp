#include <iostream>
#include <map>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 10; i++)
    {

        int count, ans;
        cin >> count;
        map<int, int> table;
        int max = 1, min = 100;
        int box_height[100];
        for (int j = 0; j < 100; j++)
        {
            cin >> box_height[j];
            if (max < box_height[j])
            {
                max = box_height[j];
            }
            if (min > box_height[j])
            {
                min = box_height[j];
            }
            if (table.find(box_height[j]) == table.end())
            {
                table[box_height[j]] = 1;
            }
            else
            {
                table[box_height[j]]++;
            }
        }
        while (count != 0)
        {
            table[max]--;
            table[max - 1]++;
            table[min]--;
            table[min + 1]++;
            if (table[max] == 0)
            {
                table.erase(max);
                while (table.find(max) == table.end())
                {
                    max--;
                }
            }
            if (table[min] == 0)
            {
                table.erase(min);
                while (table.find(min) == table.end())
                {
                    min++;
                }
            }

            count--;
        }
        ans = max - min;
        cout << "#" << i + 1 << " " << ans << endl;
    }
}