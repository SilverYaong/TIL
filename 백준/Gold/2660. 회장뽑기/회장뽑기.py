from collections import deque

dq = deque()

def sol(num):
    dq.append((num, 0))
    visited = [False] * n
    visited[num] = True
    while dq:
        v, dist = dq.popleft()
        for i in uv[v]:
            if not visited[i]:
                visited[i] = True
                dq.append((i, dist + 1))

    dist_list[num] = dist
                

n = int(input())
u, v = map(int, input().split())
uv = [[] for _ in range(n)]
dist_list = [0] * n
                   
while u != -1 and v != -1:
    uv[u - 1].append(v - 1)
    uv[v - 1].append(u - 1)
    u, v = map(int, input().split())
    
for i in range(n):
    sol(i)
    

ans = min(dist_list)

print(ans, dist_list.count(ans))
for i in range(n):
    if dist_list[i] == ans:
        print(i + 1, end=' ')