dp = [0] * 41
dp[1] = 1
for i in range(2, 41):
    dp[i] = dp[i - 1] + dp[i - 2]
    
tc = int(input())
for t in range(tc):
    n = int(input())
    if n == 0:
        print(1, 0)
    else:
        print(dp[n - 1], dp[n])