import sys

n = int(input())

count = [0] * 10001

for i in range(n):
    a = int(sys.stdin.readline())
    count[a] += 1

for i, j in enumerate(count):
    if j != 0:
        for _ in range(j):
            print(i)