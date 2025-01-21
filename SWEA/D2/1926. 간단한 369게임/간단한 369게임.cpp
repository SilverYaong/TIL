#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string count;
        string number = to_string(i + 1);
        for (int j = 0; j < number.size(); j++)
        {
            if (number[j] == '3' or number[j] == '6' or number[j] == '9')
            {
                count.append("-");
            }
        }
        if (i > 0)
            cout << " ";
        if (count.empty())
        {
            cout << number;
        }
        else
        {
            cout << count;
        }
    }
}