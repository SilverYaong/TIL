from collections import deque

n, k = map(int, input().split())
my_deque = deque()

for i in range(1, n + 1):
    my_deque.append(i)

print('<', end = '')

while my_deque:
    my_deque.rotate(-k)
    if n != 1:
        print(my_deque.pop(), end=', ')
    else:
        print(my_deque.pop(), end='')
    n -= 1
        
print('>')