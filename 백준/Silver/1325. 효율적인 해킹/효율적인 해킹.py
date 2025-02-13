from collections import deque
import sys

dq = deque()

def sol(num):
    visited = [False] * n
    dq.append(num)
    visited[num] = True
    cnt = 0
    while dq:
        v = dq.popleft()
        for i in uv[v]:
            if not visited[i]:
                visited[i] = True
                cnt += 1
                dq.append(i)
    result_list.append(cnt)

n, m = map(int, input().split())
uv = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, sys.stdin.readline().split())
    uv[v - 1].append(u - 1)
    
result_list = []
    
for i in range(n):
    sol(i)
    
mx = max(result_list)
for i in range(n):
    if result_list[i] == mx:
        print(i + 1, end=' ')