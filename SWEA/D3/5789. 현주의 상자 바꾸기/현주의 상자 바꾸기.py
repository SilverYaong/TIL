tc = int(input())
for t in range(tc):
    n, q = map(int, input().split())
    arr = [0] * n
    for num in range(q):
        l, r = map(int, input().split())
        for i in range(l - 1, r):
            arr[i] = num + 1
    print(f'#{t + 1} ', end='')
    print(*arr)