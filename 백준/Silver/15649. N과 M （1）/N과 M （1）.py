def dfs(k):
    if k == m:
        for i in range(m):
            print(arr[i], end=' ')
        print()
        return
    for i in range(1, n + 1):
        if not isused[i]:
            arr[k] = i
            isused[i] = True
            dfs(k + 1)
            isused[i] = 0

n, m = map(int, input().split())
isused = [False] * 10
arr = [0] * 10

dfs(0)