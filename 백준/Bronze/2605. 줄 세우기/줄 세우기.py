n = int(input())
arr = [*map(int, input().split())]
ans = []

for i in range(n):
    ans.insert(len(ans) - arr[i], i + 1)
print(*ans)