#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int hour;
        int min;
        int array[4];
        cin >> array[0] >> array[1] >> array[2] >> array[3];

        hour = array[0] + array[2];
        min = array[1] + array[3];

        if (min > 59)
        {
            min -= 60;
            hour++;
        }

        if (hour > 12)
        {
            hour -= 12;
        }

        cout << "#" << i + 1 << " " << hour << " " << min << endl;
    }
}
