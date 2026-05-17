#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer = {0, 0};
    
    while (s != "1") // 1이 될때까지
    {
        answer[0]++; // 변환 카운트 증가
        int len = s.length(); // 문자열 길이
        int cnt = 0; // 0 제거 카운트
        for (int i = 0; i < len; ++i) // 문자열 검사
        {
            if (s[i] == '0')
            {
                answer[1]++;
                cnt++;
            }
        }
        len = len - cnt;
        s.clear();
        while (len > 0)
        {
            int n = len % 2;
            s += to_string(n);
            len /= 2;
        }
        reverse(s.begin(), s.end());
    }
    return answer;
}