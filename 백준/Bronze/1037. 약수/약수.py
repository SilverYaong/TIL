n = int(input())
m = [*map(int, input().split())]
ans = max(m) * min(m)
print(ans)