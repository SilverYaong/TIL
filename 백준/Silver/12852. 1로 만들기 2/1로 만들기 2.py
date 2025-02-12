n = int(input())
if n == 2:
    print(1)
    print(2, 1)
elif n == 3:
    print(1)
    print(3, 1)
else:
    dp = [0] * (n + 1)
    redp = [0] * (n + 1)

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + 1
        redp[i] = i - 1
        if i % 2 == 0 and dp[i] > dp[i // 2] + 1:
            dp[i] = dp[i // 2] + 1
            redp[i] = i // 2
        if i % 3 == 0 and dp[i] > dp[i // 3] + 1:
            dp[i] = dp[i // 3] + 1
            redp[i] = i // 3

    print(dp[n])
    while True:
        print(n, end=' ')
        if n == 1: break
        n = redp[n]