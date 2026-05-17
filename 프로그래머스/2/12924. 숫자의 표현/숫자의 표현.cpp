#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= n; ++i)
    {
        int sum = 0;
        int cnt = i;
        while(sum < n)
        {
            sum += cnt++;
            if (sum == n) answer++;
        }
    }
    
    
    return answer;
}