n, m = map(int, input().split())
a_set = set()
b_set = set()
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a = set(a)
b = set(b)
ab = list(a - b)
ab += b - a

print(len(ab))