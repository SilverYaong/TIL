#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int count = 0, min = 100000;
        cin >> n;
        int array[n];
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            array[j] = abs(tmp);
            if (min > array[j])
            {
                min = array[j];
                count = 1;
            }
            else if (min == array[j])
                count++;
        }
        cout << "#" << i + 1 << " " << min << " " << count << endl;
    }
}
