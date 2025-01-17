#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        {
            int number;
            cin >> number;
            int score;
            int max = 0;
            int index = 0;
            int n[101] = {0,};
            for (int j = 0; j < 1000; j++)
                {
                    cin >> score;
                    n[score-1]++;
                }
            for (int j = 0; j < 101; j++)
                {
                    if (max <= n[j])
                    {
                        max = n[j];
                        index = j + 1;
                    }
                }
            cout << "#" << number << " " << index << endl;
        }
}