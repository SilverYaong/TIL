n = int(input())
dp = [*map(int, input().split())]
    
for i in range(1, n):
    dp[i] = max(dp[i], dp[i] + dp[i - 1])
    
print(max(dp))