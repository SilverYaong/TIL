a1, a0 = map(int, input().split())
c = int(input())
n0 = int(input())

if a1 * n0 + a0 <= c * n0:
    if a1 * 100 + a0 <= c * 100:
        print(1)
    else:
        print(0)
else:
    print(0)