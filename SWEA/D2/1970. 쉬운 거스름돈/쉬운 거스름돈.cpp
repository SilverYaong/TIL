#include <stdio.h>

using namespace std;

int main()
{
    int t, n;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int _50k = 0;
        int _10k = 0;
        int _5k = 0;
        int _1k = 0;
        int _500 = 0;
        int _100 = 0;
        int _50 = 0;
        int _10 = 0;

        scanf("%d", &n);
        printf("#%d\n", i + 1);
        if (n >= 50000)
        {
            _50k = n / 50000;
            n %= 50000;
        }

        if (n >= 10000)
        {
            _10k = n / 10000;
            n %= 10000;
        }

        if (n >= 5000)
        {
            _5k = n / 5000;
            n %= 5000;
        }

        if (n >= 1000)
        {
            _1k = n / 1000;
            n %= 1000;
        }

        if (n >= 500)
        {
            _500 = n / 500;
            n %= 500;
        }

        if (n >= 100)
        {
            _100 = n / 100;
            n %= 100;
        }

        if (n >= 50)
        {
            _50 = n / 50;
            n %= 50;
        }

        _10 = n / 10;

        printf("%d %d %d %d %d %d %d %d\n", _50k, _10k, _5k, _1k, _500, _100, _50, _10);
    }
}
