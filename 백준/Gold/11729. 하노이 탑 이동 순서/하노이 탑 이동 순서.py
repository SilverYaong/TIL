def sol(a, b, n):
    if n == 1:
        print(a, b)
        return
    sol(a, 6 - a - b, n - 1)
    print(a, b)
    sol(6 - a - b, b, n - 1)

n = int(input())
print((1 << n) - 1)
sol(1, 3, n)