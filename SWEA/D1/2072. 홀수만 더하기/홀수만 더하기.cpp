#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        {
            int result = 0;
            int n[10];
            for (int j = 0; j < 10; j++)
                {
                    cin >> n[j];
                    if (n[j] % 2 != 0) result += n[j];
                }
            cout << "#" << i+1 << " " << result << endl;
        }
}