#include <iostream>
#include <set>
#include <string>

using namespace std;

set<int> number;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        number.clear();
        int n;
        int count = 0;
        string ans;
        cin >> n;
        while (true)
        {
            count++;
            ans = to_string(n * count);
            for (int j = 0; j < ans.size(); j++)
            {
                number.insert(stoi(ans.substr(j, 1)));
            }
            if (number.size() == 10)
                break;
        }
        cout << '#' << i + 1 << ' ' << ans << endl;
    }
}