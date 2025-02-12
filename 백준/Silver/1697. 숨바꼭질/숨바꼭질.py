from collections import deque

def sol():
    visited = [False] * 100001
    while dq:
        pos, cnt = dq.popleft()
        if pos == k:
            return cnt
        if pos - 1 >= 0 and not visited[pos - 1]:
            visited[pos - 1] = True
            dq.append((pos - 1, cnt + 1))
        if pos + 1 <= 100000 and not visited[pos + 1]:
            visited[pos + 1] = True
            dq.append((pos + 1, cnt + 1))
        if pos * 2 <= 100000 and not visited[pos * 2]:
            visited[pos * 2] = True
            dq.append((pos * 2, cnt + 1))
dq = deque()
n, k = map(int, input().split())
dq.append((n, 0))

print(sol())