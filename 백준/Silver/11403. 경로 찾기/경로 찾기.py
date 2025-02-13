from collections import deque

dq = deque()

def sol(start):
    visited = [False] * n
    while dq:
        v = dq.pop()
        for i in range(n):
            if uv[v][i] == 1 and not visited[i]:
                visited[i] = True
                dq.append(i)
                result[start][i] = 1

n = int(input())
uv = [[*map(int, input().split())] for _ in range(n)]
result = [[] for _ in range(n)]

for i in range(n):
    result[i] = uv[i]

for i in range(n):
    dq.append(i)
    sol(i)
    
for i in result:
    print(*i)