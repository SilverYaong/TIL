#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    char s[1000000];
    int count[26] = {0};
    string str;
    string str2;
    int max = 0;
    char ans;
    bool check = false;

    scanf("%s", s);
    str = string(s);

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str2 += (str[i] - 32);
            count[str[i] - 32 - 'A']++;
        }
        else
        {
            str2 += str[i];
            count[str[i] - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            ans = 'A' + i;
            check = false;
        }
        else if (count[i] == max)
        {
            check = true;
        }
    }
    if (check)
        printf("?");
    else
        printf("%c", ans);
}
