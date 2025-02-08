import sys
from collections import deque

n = int(input())
queue = deque()

for _ in range(n):
    command = sys.stdin.readline().rstrip()
    if command[:2] == "pu":
        queue.append(command[5:])
    elif command == "pop":
        if queue:
            print(queue.popleft())
        else:
            print(-1)
    elif command == "size":
        print(len(queue))
    elif command == "empty":
        if queue:
            print(0)
        else:
            print(1)
    elif command == "front":
        if queue:
            print(queue[0])
        else:
            print(-1)
    else:
        if queue:
            print(queue[-1])
        else:
            print(-1)