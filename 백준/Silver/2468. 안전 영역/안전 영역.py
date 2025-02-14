from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def bfs(dq, num, arr, visited, n):
    while dq:
        x, y = dq.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                if arr[nx][ny] > num:
                    visited[nx][ny] = True
                    dq.append((nx, ny))


def sol():
    global ans
    max_h = max(map(max, arr))
    
    for num in range(max_h):
        visited = [[False] * n for _ in range(n)]
        cnt = 0
        dq = deque()
                
        for i in range(n):
            for j in range(n):
                if arr[i][j] > num and not visited[i][j]:
                    dq.append((i, j))
                    visited[i][j] = True
                    bfs(dq, num, arr, visited, n)
                    cnt += 1
        if cnt > ans:
            ans = cnt

n = int(input())
arr = [[*map(int, input().split())] for _ in range(n)]

ans = 0

sol()

print(ans)