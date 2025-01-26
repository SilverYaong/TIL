#include <iostream>
#include <algorithm>

using namespace std;

void dfs(string, int);

string optimum_num;
string max_num;
int n;
bool is_duplicated_number;
bool found;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    string num;
    int change_left;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int digitCount[10] = {0};
        is_duplicated_number = false;
        found = false;
        cin >> num >> change_left;

        for (char ch : num)
        {
            int digit = ch - '0';
            digitCount[digit]++;
            if (digitCount[digit] > 1)
            {
                is_duplicated_number = true;
                break;
            }
        }

        n = num.size();
        optimum_num = num;
        max_num = num;

        sort(optimum_num.rbegin(), optimum_num.rend());
        dfs(num, change_left);

        cout << "#" << i + 1 << " " << max_num << endl;
    }
}

void dfs(string num, int change_left)
{
    if (found)
    {
        return;
    }
    if (optimum_num == num)
    {
        found = true;
        max_num = num;
        if (change_left % 2 == 1 && !is_duplicated_number)
        {
            swap(max_num[n - 1], max_num[n - 2]);
        }
        return;
    }
    if (change_left == 0)
    {
        max_num = max(max_num, num);
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(num[i], num[j]);
            dfs(num, change_left - 1);
            swap(num[i], num[j]);
        }
    }
}