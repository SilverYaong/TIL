n = int(input())

ans = 0
for i in range(1, n + 1):
    for j in range(i, (n // i) + 1):
        ans += 1
print(ans)
