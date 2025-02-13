from collections import deque
import sys

dq = deque()

def sol():
    while dq:
        v = dq.popleft()
        for i in uv[v]:
            if not visited[i]:
                dq.append(i)
                visited[i] = True

n, m = map(int, input().split())
uv = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, sys.stdin.readline().split())
    uv[u].append(v)
    uv[v].append(u)
    
visited = [False] * (n + 1)

ans = 0

for i in range(1, n + 1):
    if not visited[i]:
        dq.append(i)
        visited[i] = True
        sol()
        ans += 1     
            
print(ans)