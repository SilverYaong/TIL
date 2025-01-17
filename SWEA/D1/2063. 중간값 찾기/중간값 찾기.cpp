#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int score;
    cin >> n;
    int array[n];
    
    for (int i = 0; i < n; i++)
        {
            cin >> score;
            array[i] = score;
        }
    sort(array, array + n);
    cout << array[n/2];
}