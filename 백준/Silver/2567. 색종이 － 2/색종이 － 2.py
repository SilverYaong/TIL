dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

paper = [[False] * 102 for _ in range(102)]
n = int(input())
ans = 0
pos = [[*map(int, input().split())] for _ in range(n)]
for i in range(n):
    x = pos[i][0] + 1
    y = pos[i][1] + 1

    for j in range(10):
        for k in range(10):
            paper[x + j][y + k] = True

for i in range(1, 101):
    for j in range(1, 101):
        if paper[i][j]:
            for k in range(4):
                if not paper[i + dy[k]][j + dx[k]]:
                    ans += 1

print(ans)
