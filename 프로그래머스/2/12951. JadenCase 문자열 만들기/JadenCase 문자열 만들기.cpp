#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int len = s.length();
    bool flag = true;
    
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == ' ')
        {
            answer += " ";
            flag = true;
        }
        else
        {
            if (flag)
            {
                answer += toupper(s[i]);
            }
            else
            {
                answer += tolower(s[i]);
            }
            flag = false;
        }
    }
    
    return answer;
}