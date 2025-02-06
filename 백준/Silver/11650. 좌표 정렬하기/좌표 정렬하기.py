n = int(input())
arr = [[] for x in range(n)]
for i in range(n):
    arr[i] = list(map(int, input().split()))
arr.sort()
for i in arr:
    for j in i:
        print(j, end=' ')
    print()