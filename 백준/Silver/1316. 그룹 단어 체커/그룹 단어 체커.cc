#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int n;
    char s[100];
    string str;
    int count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        bool isbreak = false;
        bool check[26] = {false};
        scanf("%s", s);
        str = string(s);
        for (size_t j = 0; j < str.size(); j++)
        {
            if (check[str[j] - 97])
            {
                isbreak = true;
                break;
            }
            check[str[j] - 97] = true;
            if (str[j + 1] == str[j])
                check[str[j] - 97] = false;
        }
        if (!isbreak)
            count++;
    }
    printf("%d", count);
}
