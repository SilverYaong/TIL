def fact(n):
    if n == 0:
        return 1
    return fact(n - 1) * n

n, m = map(int, input().split())
ans = fact(n) // (fact(n - m) * fact(m))
print(ans)