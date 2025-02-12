from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs():
    while dq:
        x, y = dq.popleft()
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]
            if 0 <= nx < n and 0 <= ny < m:
                if arr[nx][ny] == 0:
                    arr[nx][ny] = arr[x][y] + 1
                    dq.append((nx, ny))

m, n = map(int, input().split())
arr = [[*map(int, input().split())] for _ in range(n)]
ans = -1
dq = deque()

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            dq.append((i, j))
bfs()

for i in arr:
    if 0 in i:
        ans = -1
        break
    ans = max(ans, (max(i) - 1))
print(ans)