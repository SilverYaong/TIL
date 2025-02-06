n, m = map(int, input().split())
no_name = set()
yes_name = set()
for _ in range(n):
    no_name.add(input())
for _ in range(m):
    yes_name.add(input())
ans = list(no_name.intersection(yes_name))
ans.sort()
print(len(ans))
for i in ans:
    print(i)