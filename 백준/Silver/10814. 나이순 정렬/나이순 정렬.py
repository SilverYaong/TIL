import sys

n = int(input())
arr = [[] for _ in range(n)]
for i in range(n):
    a, b = map(str, input().split())
    a = int(a)
    arr[i] += a, b
    
arr.sort(key = lambda x: x[0])

for i in arr:
    for j in i:
        print(j, end = ' ')
    print()