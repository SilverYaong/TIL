n = int(input())
dp = [0] * (n + 5)

t = []
p = []

for _ in range(n):
    a, b = map(int, input().split())
    t.append(a)
    p.append(b)

for i in range(n - 1, -1, -1):
    if t[i] + i <= n:
        dp[i] = p[i]
        for j in range(1, n - i):
            if t[i] + i <= i + j:
                dp[i] = max(dp[i], dp[i + j] + p[i])
print(max(dp))