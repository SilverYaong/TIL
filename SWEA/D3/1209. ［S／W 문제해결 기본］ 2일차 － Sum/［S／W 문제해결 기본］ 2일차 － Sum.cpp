#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 10; i++)
    {
        int t;
        cin >> t;

        int max_sum = 0;
        int diag_up = 0;
        int diag_down = 0;
        int array[100][100];

        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                cin >> array[j][k];
            }
        }

        for (int j = 0; j < 100; j++)
        {
            int rows = 0;
            int cols = 0;

            diag_up += array[j][j];
            diag_down += array[j][99 - j];

            for (int k = 0; k < 100; k++)
            {
                rows += array[j][k];
                cols += array[k][j];
            }
            max_sum = max(max_sum, max(rows, cols));
        }
        max_sum = max(max_sum, max(diag_down, diag_up));

        cout << "#" << t << " " << max_sum << endl;
    }
}