from collections import deque

dx = [1, 2, 2, 1, -1, -2, -2, -1]
dy = [2, 1, -1, -2, -2, -1, 1, 2]

dq = deque()

def sol(x, y, z, w):
    dq.append((x, y, 0))
    visited[x][y] = True
    while dq:
        x, y, cnt = dq.popleft()
        for d in range(8):
            nx, ny = x + dx[d], y + dy[d]
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                if nx == tar_x and ny == tar_y:
                    dq.clear()
                    return cnt + 1
                dq.append((nx, ny, cnt + 1))
                visited[nx][ny] = True
                
tc = int(input())
for t in range(tc):
    ans = 0
    n = int(input())
    arr = [[0] * n for _ in range(n)]
    visited = [[False] * n for _ in range(n)]
    cur_x, cur_y = map(int, input().split())
    tar_x, tar_y = map(int, input().split())
    if cur_x != tar_x or cur_y != tar_y:
        ans = sol(cur_x, cur_y, tar_x, tar_y)
    
    print(ans)