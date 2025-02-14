def sol(arr):
    if len(arr) == m:
        print(*arr)
        return
    for i in range(1, n + 1):
        sol(arr + [i])

n, m = map(int, input().split())
sol([])