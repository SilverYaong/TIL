n, m = map(int, input().split())
arr = [*map(int, input().split())]
target = [[*map(int, input().split())] for _ in range(m)]

dp = [0] * (n + 1)
for i in range(1, n + 1):
    dp[i] = dp[i - 1] + arr[i - 1]
for i in range(m):
    l, r = target[i]
    print(dp[r] - dp[l - 1])