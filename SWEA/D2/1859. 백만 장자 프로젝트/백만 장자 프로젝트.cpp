#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    long long n, ans;
    vector<long long> array;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long tmp = 0;
        ans = 0;
        cin >> n;
        array.clear();
        for (long long j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            array.push_back(a);
        }
        for (long long j = n - 1; j >= 0; j--)
        {
            if (tmp <= array[j])
            {
                tmp = array[j];
                continue;
            }
            ans += tmp - array[j];
        }
        cout << "#" << i + 1 << " " << ans << endl;
    }
}