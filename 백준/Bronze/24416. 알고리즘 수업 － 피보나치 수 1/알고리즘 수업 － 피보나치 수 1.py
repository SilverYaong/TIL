def fib2(n):
    global cnt
    for i in range(3, n + 1):
        cnt += 1
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]

n = int(input())
cnt = 0
dp = [0] * 41
dp[1], dp[2] = 1, 1
print(fib2(n), cnt)