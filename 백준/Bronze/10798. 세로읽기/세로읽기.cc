#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    char array[5][16] = {};

    for (int i = 0; i < 5; i++)
    {
        cin.getline(array[i], 16);
    }
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (array[j][i] != '\0')
            {
                cout << array[j][i];
            }
        }
    }
}
