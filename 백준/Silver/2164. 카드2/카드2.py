import sys
from collections import deque

n = int(input())
queue = deque()
for i in range(1, n + 1):
    queue.append(i)
for _ in range(n - 1):
    queue.popleft()
    queue.append(queue.popleft())
print(queue.pop())