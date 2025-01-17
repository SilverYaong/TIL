#include <iostream>
#include <string>
#include <set>
using namespace std;

void ans(int, string);
void error(int);

set<int> month31 = {1,3,5,7,8,10,12};
set<int> month30 = {4,6,9,11};

int main() {
    int t, year, month, day;
    string date;
    cin >> t;
    for (int i = 0; i < t; i++)
        {
            cin >> date;
            year = stoi(date.substr(0,4));
            month = stoi(date.substr(4,2));
            day = stoi(date.substr(6,2));
            if (month31.count(month))
                {
                if (1 <= day && day <= 31)
                {
                    ans(i, date);
                }
                else{
                    error(i);
                }
                }
            else if (month30.count(month))
                {
                if (1 <= day && day <= 30)
                {
                    ans(i, date);
                }
                else {
                    error(i);
                }
                }
            else if (month == 2)
            {
                if (1 <= day && day <= 28)
                {
                    ans(i, date);
                }
                else {
                    error(i);
                }
            }
            else {
                error(i);
            }
        }
}

void ans(int i, string date) {
    cout << "#" << i+1 << " " << date.substr(0,4) << "/" << date.substr(4,2) << "/" << date.substr(6,2) << endl;
}

void error(int i) {
    cout << "#" << i+1 << " " << -1 << endl;
}