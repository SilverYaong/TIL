n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))
max_x = -10000
min_x = 10000
max_y = -10000
min_y = 10000

for i in arr:
    if max_x < i[0]:
        max_x = i[0]
    if min_x > i[0]:
        min_x = i[0]
    if max_y < i[1]:
        max_y = i[1]
    if min_y > i[1]:
        min_y = i[1]
        
ans = (max_x - min_x) * (max_y - min_y)
print(ans)    