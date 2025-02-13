def sol(a, b, c):
    if b == 1:
        return a % c
    val = sol(a, b//2, c)
    val = val * val % c
    if b % 2 == 0:
        return val
    return val * a % c

a, b, c = map(int, input().split())

print(sol(a, b, c))