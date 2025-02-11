n = int(input())
p = [*map(int, input().split())]
prev_time = 0
total_time = 0
p.sort()
for i in p:
    prev_time += i
    total_time += prev_time
print(total_time)