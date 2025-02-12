from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs(i, j):
    dq = deque()
    dq.append((i, j))
    dst[i][j] = 0    
    
    while dq:
        x, y = dq.popleft()
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]
            if 0 <= nx < n and 0 <= ny < m:
                if arr[nx][ny] == 1 and dst[nx][ny] < 0:
                    dst[nx][ny] = dst[x][y] + 1
                    dq.append((nx, ny))

n, m = map(int, input().split())
dst = [[-1] * m for _ in range(n)]
arr = [[*map(int, input())] for _ in range(n)]
ans = bfs(0, 0)
print(dst[n - 1][m - 1] + 1)