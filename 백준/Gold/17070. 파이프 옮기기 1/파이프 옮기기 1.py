def sol():
    dp[0][1][0] = 1
    for j in range(2, n):
        if arr[0][j] == 0:
            dp[0][j][0] = dp[0][j - 1][0]
    
    for i in range(1, n):
        for j in range(2, n):
            if arr[i][j] == 0:
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1]
                dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2]
                if arr[i - 1][j] == 0 and arr[i][j - 1] == 0:
                    dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]

n = int(input())
arr = [[*map(int, input().split())] for _ in range(n)]
dp = [[[0, 0, 0] for _ in range(n)] for _ in range(n)]

sol()

print(dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2])