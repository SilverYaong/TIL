#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    char s[100];
    string str;
    int count = 0;

    scanf("%s", s);
    str = string(s);

    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i + 1] == '=' || str[i + 1] == '-')
        {
            count++;
            i++;
        }
        else if (str[i + 1] == 'j')
        {
            if (str[i] == 'l' || str[i] == 'n')
            {
                count++;
                i++;
            }
            else
            {
                count++;
            }
        }
        else if (str[i] == 'd')
        {
            if (str[i + 1] == 'z')
            {
                if (str[i + 2] == '=')
                {
                    count++;
                    i += 2;
                }
                else
                {
                    count++;
                }
            }
            else
            {
                count++;
            }
        }
        else
        {
            count++;
        }
    }
    printf("%d", count);
}
