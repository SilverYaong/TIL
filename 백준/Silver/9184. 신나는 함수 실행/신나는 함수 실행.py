memo = [[[-1] * 21 for _ in range(21)] for _ in range(21)]

def sol(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1

    if a > 20 or b > 20 or c > 20:
        return sol(20, 20, 20)
    
    if memo[a][b][c] != -1:
        return memo[a][b][c]

    if a < b and b < c:
        memo[a][b][c] = sol(a, b, c - 1) + sol(a, b - 1, c - 1) - sol(a, b - 1, c)

    else:
        memo[a][b][c] = sol(a - 1, b, c) + sol(a - 1, b - 1, c) + sol(a - 1, b, c - 1) - sol(a - 1, b - 1, c - 1)
    
    return memo[a][b][c]

a, b, c = map(int, input().split())
while a != -1 or b != -1 or c != -1:
    print(f"w({a}, {b}, {c}) = {sol(a, b, c)}")
    a, b, c = map(int, input().split())