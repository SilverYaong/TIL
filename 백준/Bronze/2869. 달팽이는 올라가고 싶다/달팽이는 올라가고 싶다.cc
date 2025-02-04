#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, v;
    cin >> a >> b >> v;

    int ans = (v - a + (a - b) - 1) / (a - b) + 1;

    cout << ans << "\n";
}
