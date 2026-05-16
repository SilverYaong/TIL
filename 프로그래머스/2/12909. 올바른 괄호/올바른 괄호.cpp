#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string str)
{
    bool answer = false;
    
    int size = str.length();
    
    stack<char> s;
    bool flag = false;
    
    for (int i = 0; i < size; i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else
        {
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
                continue;
            }
            flag = true;
            break;
        }
    }
        
    if (!flag && s.empty()) answer = true;
    return answer;
}