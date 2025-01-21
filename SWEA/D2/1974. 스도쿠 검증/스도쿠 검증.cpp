#include <iostream>
#include <set>

using namespace std;

int checksuccess();

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "#" << i + 1 << " " << checksuccess() << endl;
    }
}

int checksuccess()
{
    set<int> check;
    int array[9][9];
    for (int j = 0; j < 9; j++)
    {
        for (int k = 0; k < 9; k++)
        {
            cin >> array[j][k];
        }
    }

    for (int j = 0; j < 9; j++) // 가로검사
    {
        check.clear();
        for (int k = 0; k < 9; k++)
        {
            auto issuccess = check.insert(array[j][k]);
            if (!issuccess.second)
            {
                return 0;
            }
        }
    }

    for (int j = 0; j < 9; j++) // 세로검사
    {
        check.clear();
        for (int k = 0; k < 9; k++)
        {
            auto issuccess = check.insert(array[k][j]);
            if (!issuccess.second)
            {
                return 0;
            }
        }
    }

    for (int j = 0; j < 9; j += 3) // 내부 사각형 검사
    {
        for (int k = 0; k < 9; k += 3)
        {
            check.clear();
            for (int jj = 0; jj < 3; jj++)
            {
                for (int kk = 0; kk < 3; kk++)
                {
                    auto issuccess = check.insert(array[j + jj][k + kk]);
                    if (!issuccess.second)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}