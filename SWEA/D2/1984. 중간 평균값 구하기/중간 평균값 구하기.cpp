#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int ans;
        int max = 0, min = 10000;
        float avg = 0;
        int array[10];
        for (int j = 0; j < 10; j++)
        {
            cin >> array[j];
            if (max <= array[j])
                max = array[j];
            if (min >= array[j])
                min = array[j];
            avg += array[j];
        }

        ans = round((avg - max - min) / 8);

        cout << "#" << i + 1 << " " << ans << endl;
    }
}
