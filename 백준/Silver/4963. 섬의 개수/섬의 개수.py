from collections import deque

dx = [1, 1, 0, -1, -1, -1, 0, 1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]


dq = deque()

def sol():
    while dq:
        x, y = dq.popleft()
        for i in range(8):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < h and 0 <= ny < w:
                if not visited[nx][ny] and arr[nx][ny] == 1:
                    visited[nx][ny] = True
                    dq.append((nx, ny))

w, h = map(int, input().split())
while w != 0 and h != 0:
    visited = [[False] * w for _ in range(h)]
    arr = [[*map(int, input().split())] for _ in range(h)]
    ans = 0
    
    for i in range(h):
        for j in range(w):
            if arr[i][j] == 1 and not visited[i][j]:
                dq.append((i, j))
                visited[i][j] = True
                sol()
                ans += 1
    
    print(ans)
    w, h = map(int, input().split())