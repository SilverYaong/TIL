def sol(n, r, c):
    if n == 0:
        return 0
    half = 1 << (n - 1)
    if r < half and c < half:
        return sol(n - 1, r, c)
    if r < half and c >= half:
        return half * half + sol(n - 1, r, c - half)
    if r >= half and c < half:
        return 2 * half * half + sol(n - 1, r - half, c)
    return 3 * half * half + sol(n - 1, r - half, c - half)
n, r, c = map(int, input().split())
print(sol(n, r, c))
