from collections import deque
import sys

dq = deque()

def dfs():
    while dq:
        v = dq.pop()
        if not visited[v]:
            visited[v] = True
            result.append(v)
            for i in reversed(uv[v]):
                if not visited[i]:
                    dq.append(i)

def bfs():
    result.append(start)
    while dq:
        v = dq.popleft()
        for i in uv[v]:
            if not visited[i]:
                visited[i] = True
                dq.append(i)
                result.append(i)


n, m, start = map(int, input().split())
uv = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, sys.stdin.readline().split())
    uv[u].append(v)
    uv[v].append(u)

for i in uv:
    i.sort()

visited = [False] * (n + 1)
result = []
dq.append(start)
dfs()
print(*result)

visited = [False] * (n + 1)
result.clear()
dq.append(start)
visited[start] = True
bfs()
print(*result)