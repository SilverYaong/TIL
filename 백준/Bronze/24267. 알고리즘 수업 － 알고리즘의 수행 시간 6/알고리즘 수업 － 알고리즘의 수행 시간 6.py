n = int(input()) - 2
ans = 0
for i in range(1, n + 1):
    ans += (n - i + 1) * (n - i + 2) // 2
print(ans)
print(3)