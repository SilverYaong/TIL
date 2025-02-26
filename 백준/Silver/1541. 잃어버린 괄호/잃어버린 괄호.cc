#include <iostream>
#include <deque>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    set<int> num_arr;
    for (int i = 0; i < 10; i++)
    {
        num_arr.insert(i);
    }

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    deque<int> buffer;
    deque<int> num;
    bool flag = false;
    int n = -1;
    int ans = 0;
    bool chk = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (num_arr.find(s[i] - '0') != num_arr.end())
        {
            int a = s[i] - '0';
            buffer.push_back(a);
            n++;
        }
        else
        {

            int a = 0;
            for (n; n > -1; n--)
            {
                int x = buffer.front() * pow(10, n);
                buffer.pop_front();
                a += x;
            }
            if (!flag)
            {
                num.push_back(a);
            }
            else
            {
                int b = num.back();
                num.pop_back();
                num.push_back(a + b);
                flag = false;
            }
            if (s[i] == '+')
            {
                flag = true;
            }
            else
            {
                chk = true;
            }
        }
    }
    int a = 0;
    for (n; n > -1; n--)
    {
        int x = buffer.front() * pow(10, n);
        buffer.pop_front();
        a += x;
    }
    num.push_back(a);
    ans = num.front();
    num.pop_front();
    if (chk)
    {
        while (!num.empty())
        {
            ans -= num.front();
            num.pop_front();
        }
    }
    else
    {
        while (!num.empty())
        {
            ans += num.front();
            num.pop_front();
        }
    }

    cout << ans;
}