from collections import deque

dq = deque()

def sol(num):
    dq.append((num, 0))
    visited = [False] * n
    visited[num] = True
    cnt = 0
    while dq:
        v, dist = dq.popleft()
        for i in uv[v]:
            if not visited[i]:
                visited[i] = True
                dq.append((i, dist + 1))
                cnt += dist + 1
    dist_list[num] = cnt
                

n, m = map(int, input().split())
uv = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    uv[u - 1].append(v - 1)
    uv[v - 1].append(u - 1)

dist_list = [0] * n

for i in range(n):
    sol(i)
    
ans = min(dist_list)
print(dist_list.index(ans) + 1)