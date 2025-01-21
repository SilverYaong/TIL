#include <stdio.h>

using namespace std;

void triangle(int);

int main()
{
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("#%d\n", i + 1);
        scanf("%d", &n);
        triangle(n);
    }
}

void triangle(int n)
{
    int triangle[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                triangle[i][j] = 1;
            }
            else
            {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            printf("%d", triangle[i][j]);
            if (j != i)
                printf(" ");
        }
        printf("\n");
    }
}