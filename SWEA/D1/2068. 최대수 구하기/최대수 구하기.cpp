#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n[10];
    for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < 10; j++)
                {
                    cin >> n[j];
                }
            sort(n, n + 10);
            cout << "#" << i+1 << " " << n[9] << endl;
        }
}