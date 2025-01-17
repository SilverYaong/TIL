#include <iostream>

using namespace std;

string ans(int, int);

int main() {
    int t;
    cin >> t;
    int a, b;
    for (int i = 0; i < t; i++)
        {
            string result;
            cin >> a >> b;
            result = ans(a, b);
            cout << "#" << i+1 << " " << result << endl;
        }
}

string ans(int a, int b)
{
    if (a < b) return "<";
    else if (a > b) return ">";
    else return "=";
}