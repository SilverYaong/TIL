from collections import deque

n = int(input())
my_deque = deque(enumerate(map(int, input().split()), start = 1))

result = []

while my_deque:
    index, val = my_deque.popleft()
    result.append(index)
    
    if my_deque:
        if val > 0:
            my_deque.rotate(-val + 1)
        else:
            my_deque.rotate(-val)

print(*result)