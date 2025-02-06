n = int(input())
arr = [[] for x in range(n)]
for i in range(n):
    arr[i] = list(map(int, input().split()))
arr.sort(key = lambda x: (x[1], x[0]))
for i in arr:
    for j in i:
        print(j, end=' ')
    print()