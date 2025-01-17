#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        {
            int n;
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;
            int e = 0;
            cin >> n;

            while (n % 2 == 0)
                {
                    n /= 2;
                    a++;
                }
            while (n % 3 == 0)
                {
                    n /= 3;
                    b++;
                }
            while (n % 5 == 0)
                {
                    n /= 5;
                    c++;
                }
            while (n % 7 == 0)
                {
                    n /= 7;
                    d++;
                }
            while (n % 11 == 0)
                {
                    n /= 11;
                    e++;
                }
            cout << "#" << i + 1 << " " << a << " " << b << ' ' << c << ' ' << d << ' ' << e << endl;
        }
}