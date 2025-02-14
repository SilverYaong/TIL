def sol(n, r, c):
    cur = arr[r][c]
    
    for i in range(r, r + n):
        for j in range(c, c + n):
            if arr[i][j] != cur:
                div = n // 3
                sol(div, r, c)
                sol(div, r, c + div)
                sol(div, r, c + div * 2)
                sol(div, r + div, c)
                sol(div, r + div, c + div)
                sol(div, r + div, c + div * 2)
                sol(div, r + div * 2, c)
                sol(div, r + div * 2, c + div)
                sol(div, r + div * 2, c + div * 2)
                return
    my_dict[cur] += 1
    return

n = int(input())
arr = [[*map(int, input().split())] for _ in range(n)]
my_dict = {
    -1 : 0,
    0 : 0,
    1 : 0,
}

sol(n, 0, 0)
for i in my_dict.values():
    print(i)