#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
    int mid;
    int fin;
    int task;
};

bool compare(pair<int, double> a, pair<int, double> b)
{
    return a.second > b.second;
}

int main()
{
    int t, n, k;
    int mid, fin, task;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &k);
        vector<pair<int, double>> scoreTable;
        struct Student students[n];
        string grade[n];
        int gradesize = n * 0.1;
        for (int j = 0; j < n; j++)
        {
            scanf("%d %d %d", &students[j].mid, &students[j].fin, &students[j].task);
            scoreTable.push_back(make_pair(j + 1, students[j].mid * .35 + students[j].fin * .45 + students[j].task * .2));
        }
        sort(scoreTable.begin(), scoreTable.end(), compare);
        for (int j = 0; j < n; j++)
        {
            if (j < gradesize)
                grade[scoreTable[j].first - 1] = "A+";
            else if (j < gradesize * 2)
                grade[scoreTable[j].first - 1] = "A0";
            else if (j < gradesize * 3)
                grade[scoreTable[j].first - 1] = "A-";
            else if (j < gradesize * 4)
                grade[scoreTable[j].first - 1] = "B+";
            else if (j < gradesize * 5)
                grade[scoreTable[j].first - 1] = "B0";
            else if (j < gradesize * 6)
                grade[scoreTable[j].first - 1] = "B-";
            else if (j < gradesize * 7)
                grade[scoreTable[j].first - 1] = "C+";
            else if (j < gradesize * 8)
                grade[scoreTable[j].first - 1] = "C0";
            else if (j < gradesize * 9)
                grade[scoreTable[j].first - 1] = "C-";
            else
                grade[scoreTable[j].first - 1] = "D0";
        }
        printf("#%d %s\n", i + 1, grade[k - 1].c_str());
    }
}