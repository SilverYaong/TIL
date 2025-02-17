from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def sol():
    dq = deque()
    dq.append((0, 0))
    cost[0][0] = arr[0][0]
    
    while dq:
        x, y = dq.popleft()
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]
            if 0 <= nx < n and 0 <= ny < n:
                new_cost = cost[x][y] + arr[nx][ny]
                
                if new_cost < cost[nx][ny]:
                    cost[nx][ny] = new_cost
                    dq.append((nx, ny))
                    
    return cost[n - 1][n - 1]


tc = int(input())
for t in range(tc):
    n = int(input())
    arr = [[*map(int, input())] for _ in range(n)]
    cost = [[float('inf')] * n for _ in range(n)]
    ans = sol()
    print(f"#{t + 1} {ans}")