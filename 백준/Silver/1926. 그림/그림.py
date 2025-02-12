from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs(i, j):
    dq = deque()
    dq.append((i, j))
    visited[i][j] = True
    area = 1
    
    while dq:
        x, y = dq.popleft()
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and arr[nx][ny] == 1:
                area += 1
                visited[nx][ny] = True
                dq.append((nx, ny))
    return area


n, m = map(int, input().split())
arr = [[*map(int, input().split())] for _ in range(n)]
visited = [[False] * m for _ in range(n)]
ans = 0
max_area = 0

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1 and not visited[i][j]:
            ans += 1
            max_area = max(max_area, bfs(i, j))
print(ans)
print(max_area)