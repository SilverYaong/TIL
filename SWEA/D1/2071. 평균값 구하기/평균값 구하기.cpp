#include <iostream>
#include <cmath>

using namespace std;

string ans(float, float);

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        {
            float result = 0;
            int n[10];
            for (int j = 0; j < 10; j++)
                {
                    cin >> n[j];
                    result += n[j];
                }
            cout << "#" << i+1 << " " << round(result / 10) << endl;
        }
}