#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;
    int ans = 1;
    long long check = 1;
    int count = 0;
    while (n > check)
    {
        count++;
        check += count * 6;
    }
    ans += count;
    cout << ans;
}
