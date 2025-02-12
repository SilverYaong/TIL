from collections import deque

dx = [1, 0, -1, 0, 0, 0]
dy = [0, 1, 0, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

dq = deque()

def sol():
    while dq:
        x, y, z = dq.popleft()
        for d in range(6):
            nx, ny, nz = x + dx[d], y + dy[d], z + dz[d]
            if 0 <= nx < height and 0 <= ny < row and 0 <= nz < col:
                if not visited[nx][ny][nz] and arr[nx][ny][nz] == 0:
                    dq.append((nx, ny, nz))
                    visited[nx][ny][nz] = True
                    arr[nx][ny][nz] = arr[x][y][z] + 1

col, row, height = map(int, input().split())
arr = [[[*map(int, input().split())] for _ in range(row)] for _ in range(height)]
visited = [[[False] * col for _ in range(row)] for _ in range(height)]
ans = -1

for i in range(height):
    for j in range(row):
        for k in range(col):
            if arr[i][j][k] == 1:
                dq.append((i, j, k))

sol()

for i in arr:
    for j in i:
        ans = max(ans, *j)

for i in arr:
    for j in i:
        if 0 in j:
            ans = 0
            break
    if ans == 0:
        break
print(ans - 1)