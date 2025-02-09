n = int(input())
m = []
my_set = set()
cnt = 0
ans = 0
for _ in range(n):
    m.append(input())

for name in m:
    if name == 'ENTER':
        my_set.clear()
        ans += cnt
        cnt = 0
        continue
    if not name in my_set:
        my_set.add(name)
        cnt += 1
print(ans + cnt)