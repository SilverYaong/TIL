#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int array[n];
        for (int j = 0; j < n; j++)
        {
            cin >> array[j];
        }
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (array[j] > array[k])
                {
                    int tmp = array[j];
                    array[j] = array[k];
                    array[k] = tmp;
                }
            }
        }
        cout << "#" << i + 1;
        for (int j = 0; j < n; j++)
        {
            cout << " " << array[j];
        }
        cout << endl;
    }
}