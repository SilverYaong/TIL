n, k = map(int, input().split())
list = []
for i in range(n + 1):
    if n % (i + 1) == 0:
        list.append(i + 1)
try:
    if list[k - 1]:
        print(list[k - 1])
except IndexError:
    print(0)