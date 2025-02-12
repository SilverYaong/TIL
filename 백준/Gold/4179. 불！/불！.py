from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def sol():
    while dq:
        P, x, y = dq.popleft()

        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]

            if 0 <= nx < r and 0 <= ny < c:

                if P == 'F' and arr[nx][ny] != '#' and not F_visited[nx][ny]:
                    F_visited[nx][ny] = True
                    dq.append(('F', nx, ny))

                elif P == 'J' and arr[nx][ny] == '.' and not J_visited[nx][ny] and not F_visited[nx][ny]:
                    J_visited[nx][ny] = True
                    arr[nx][ny] = arr[x][y] + 1
                    dq.append(('J', nx, ny))

                    if nx == 0 or nx == r - 1 or ny == 0 or ny == c - 1:
                        return str(arr[nx][ny])

    return 'IMPOSSIBLE'

r, c = map(int, input().split())
arr = [[*map(str, input())] for _ in range(r)]
dq = deque()
ans = 0

J_visited = [[False] * c for _ in range(r)]
F_visited = [[False] * c for _ in range(r)]

for i in range(r):
    for j in range(c):
        if arr[i][j] == 'J':
            if i == 0 or i == r - 1 or j == 0 or j == c - 1:
                ans = 1
                print(ans)
                break
            arr[i][j] = 1
            dq.append(('J', i, j))
            J_visited[i][j] = True
        elif arr[i][j] == 'F':
            dq.appendleft(('F', i, j))
            F_visited[i][j] = True
    if ans == 1:
        break

if ans != 1:
    print(sol())