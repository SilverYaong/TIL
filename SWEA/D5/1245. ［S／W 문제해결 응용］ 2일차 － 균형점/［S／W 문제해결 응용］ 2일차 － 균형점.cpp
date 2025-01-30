#include <iostream>

using namespace std;

double binary_search(const int[], const int[], int, double, double);
double forcesum(const int[], const int[], int, double);

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    cout.precision(10);
    cout.setf(ios::fixed);

    for (int i = 0; i < t; i++)
    {
        double ans = 0;
        int n;
        cin >> n;
        int pos[n], mass[n];
        for (int j = 0; j < n; j++)
        {
            cin >> pos[j];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> mass[j];
        }
        cout << "#" << i + 1;
        for (int j = 0; j < n - 1; j++)
        {
            ans = binary_search(mass, pos, n, pos[j], pos[j + 1]);
            cout << " " << ans;
        }
        cout << endl;
    }
}

double binary_search(const int mass[], const int pos[], int size, double left, double right)
{
    double mid;
    while (right - left > 1e-12)
    {
        mid = (left + right) / 2;
        double f = forcesum(mass, pos, size, mid);

        if (f < 0)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return mid;
}

double forcesum(const int mass[], const int pos[], int size, double mid)
{
    double sum_left = 0.0, sum_right = 0.0;

    for (int i = 0; i < size; i++)
    {
        double force = mass[i] / ((mid - pos[i]) * (mid - pos[i]));
        if (mid > pos[i])
        {
            sum_left += force;
        }
        else
        {
            sum_right += force;
        }
    }
    return sum_left - sum_right;
}
