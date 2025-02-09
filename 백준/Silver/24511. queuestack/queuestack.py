from collections import deque

my_deque = deque()

n = int(input())
a = [*map(int, input().split())]
b = [*map(int, input().split())]
m = int(input())
c = [*map(int, input().split())]

result = []

arr = zip(a, b)

for i in arr:
    if i[0] == 0:
        my_deque.append(i[1])
for i in c:
    my_deque.appendleft(i)
    result.append(my_deque.pop())
    
print(*result)