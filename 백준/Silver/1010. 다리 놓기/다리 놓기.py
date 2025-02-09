def fact(n):
    if n == 0:
        return 1
    return fact(n - 1) * n

tc = int(input())
for _ in range(tc):
    n, m = map(int, input().split())
    ans = fact(m) // (fact(m - n) * fact(n))
    print(ans)