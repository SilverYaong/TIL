n = int(input())
uv = [[] for _ in range(500)]
for _ in range(n):
    u, v = map(int, input().split())
    uv[u - 1].append(v - 1)
dp = [1] * n
arr = []
for i in range(500):
    if uv[i]:
        arr.append(*uv[i])
for i in range(n):
    for j in range(i):
        if arr[j] < arr[i]:
            dp[i] = max(dp[i], dp[j] + 1)
print(n - max(dp))