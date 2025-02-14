def sol(start, arr):
    if len(arr) == m:
        print(*arr)
        return
    for i in range(start, n + 1):
        sol(i, arr + [i])

n, m = map(int, input().split())
sol(1, [])