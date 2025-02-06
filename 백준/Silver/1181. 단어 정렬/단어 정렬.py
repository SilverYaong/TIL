import sys

n = int(input())
arr = set()
for i in range(n):
    a = sys.stdin.readline()
    a = a.rstrip('\n')
    arr.add(a)
arr = list(arr)
arr.sort(key = lambda x: (len(x), x))
for i in arr:
    print(i)