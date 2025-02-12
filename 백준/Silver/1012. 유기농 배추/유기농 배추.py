from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def sol(i, j):
    dq = deque()
    dq.append((i, j))
    visited[i][j] = True
    
    while dq:
        x, y = dq.popleft()
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]
            if 0 <= nx < n and 0 <= ny < m and arr[nx][ny] == 1 and not visited[nx][ny]:
                visited[nx][ny] = True
                dq.append((nx, ny))
    
    return 1


dq = deque()
tc = int(input())

for _ in range(tc):
    m, n, k = map(int, input().split())
    arr = [[0] * m for _ in range(n)]
    visited = [[False] * m for _ in range(n)]
    
    for _ in range(k):
        x, y = map(int, input().split())
        arr[y][x] = 1
    
    cnt = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1 and not visited[i][j]:
                cnt += sol(i, j)
    print(cnt)