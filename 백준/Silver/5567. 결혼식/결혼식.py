from collections import deque

def sol():
    cnt = 0
    while dq:
        v, depth = dq.pop()
        for i in uv[v]:
            if not visited[i] and depth <= 1:
                visited[i] = True
                dq.append((i, depth + 1))
                cnt += 1
    return cnt

dq = deque()

n = int(input())
m = int(input())

uv = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, input().split())
    uv[u].append(v)
    uv[v].append(u)
    
visited = [False] * (n + 1)

dq.append((1, 0))
visited[1] = True
print(sol())