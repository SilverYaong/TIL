max_x = -10000
min_x = 10000
max_y = -10000
min_y = 10000

n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    if max_x < x:
        max_x = x
    if min_x > x:
        min_x = x
    if max_y < y:
        max_y = y
    if min_y > y:
        min_y = y

ans = (max_x - min_x) * (max_y - min_y)
print(ans)    