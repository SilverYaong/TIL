n = int(input())
arr = []
dp = [[0] * n for _ in range(n)]

for i in range(n):
    arr.append([*map(int, input().split())])

left = 0
right = 0

for i in range(n):
    left += arr[i][0]
    dp[i][0] = left
    
    right += arr[i][i]
    dp[i][i] = right

for i in range(2, n):
    for j in range(1, i):
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j]

print(max(dp[n - 1]))