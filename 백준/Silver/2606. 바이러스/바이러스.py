from collections import deque

dq = deque()

def sol():
    cnt = 0
    while dq:
        v = dq.pop()
        for i in uv[v]:
            if not visited[i]:
                visited[i] = True
                dq.append(i)
                cnt += 1
    return cnt

n = int(input())
m = int(input())

uv = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, input().split())
    uv[u].append(v)
    uv[v].append(u)

visited = [False] * (n + 1)    
dq.append(1)
visited[1] = True

print(sol())