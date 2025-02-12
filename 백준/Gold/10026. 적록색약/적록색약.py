from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def sol(C, i, j):
    dq = deque()
    dq.append((C, i, j))
    visited[i][j] = True

    while dq:
        color, x, y = dq.pop()
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and arr[nx][ny] == color:
                visited[nx][ny] = True
                dq.append((C, nx, ny))
    return 1


def sol2(C, i, j):
    dq = deque()
    dq.append((C, i, j))
    visited[i][j] = True

    while dq:
        color, x, y = dq.pop()
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]

            if 0 <= nx < n and 0 <= ny < n:
                if color == 'R' or color == 'G':
                    if not visited[nx][ny] and (arr[nx][ny] == 'R' or arr[nx][ny] == 'G'):
                        visited[nx][ny] = True
                        dq.append((C, nx, ny))
                else:
                    if not visited[nx][ny] and arr[nx][ny] == color:
                        visited[nx][ny] = True
                        dq.append((C, nx, ny))
    return 1


n = int(input())
arr = [[*map(str, input())] for _ in range(n)]

visited = [[False] * n for _ in range(n)]
ans = 0

for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            C = arr[i][j]
            ans += sol(C, i, j)

print(ans, end=' ')
ans = 0

visited = [[False] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            C = arr[i][j]
            ans += sol2(C, i, j)

print(ans)