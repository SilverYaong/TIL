n = int(input())
arr = [*map(int, input().split())]
dp = [0] * n
for i in range(n):
    dp[i] = arr[i]
    for j in range(i):
        if arr[j] < arr[i] and dp[i] < dp[j] + arr[i]:
            dp[i] = dp[j] + arr[i]
        
print(max(dp))