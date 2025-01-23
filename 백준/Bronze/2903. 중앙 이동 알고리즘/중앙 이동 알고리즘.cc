#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    long long ans;
    ans = (pow(2, n) + 1) * (pow(2, n) + 1);
    cout << ans;
}
