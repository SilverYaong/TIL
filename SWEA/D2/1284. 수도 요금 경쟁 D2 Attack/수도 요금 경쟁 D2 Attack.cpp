#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        {
            int ans;
            int p, q, r, s, w;
            cin >> p >> q >> r >> s >> w;
            int a, b;
            
            a = p * w;
            if (w <= r) b = q;
            else b = q + (s * (w - r));
            
            if (a < b) ans = a;
            else ans = b;

            cout << "#" << i + 1 << " " << ans << endl;
        }
}