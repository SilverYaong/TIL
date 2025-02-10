n = int(input())
my_set = set()
cnt = 0
for _ in range(n):
    a, b = map(str, input().split())
    if a == 'ChongChong' and b not in my_set:
        cnt += 1
        my_set.add(b)
    elif a == 'ChongChong' and b in my_set:
        continue
    elif b == 'ChongChong' and a not in my_set:
        cnt += 1
        my_set.add(a)
    elif b == 'ChongChong' and a in my_set:
        continue
    elif a in my_set and b not in my_set:
        cnt += 1
        my_set.add(b)
    elif b in my_set and a not in my_set:
        cnt += 1
        my_set.add(a)
    elif a in my_set and b in my_set:
        continue
print(cnt + 1)