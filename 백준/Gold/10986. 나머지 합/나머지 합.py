n, m = map(int, input().split())
arr = [*map(int, input().split())]

count = [0] * m
pre_sum = 0
ans = 0

for num in arr:
    pre_sum = (pre_sum + num) % m
    count[pre_sum] += 1

ans += count[0]
for c in count:
    if c > 1:
        ans += (c * (c - 1)) // 2

print(ans)