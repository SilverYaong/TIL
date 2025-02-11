def getDiv(n):

    div_list = []

    for i in range(1, n + 1):
        if n % i == 0:
            div_list.append(i)

    return div_list


s = input()
n = len(s)
div_list = getDiv(n)
idx = (len(div_list) // 2) - 1
r = div_list[idx + 1]
c = n // r
arr = [[""] * r for _ in range(c)]
k = 0
for i in range(r):
    for j in range(c):
        arr[j][i] = s[k]
        k += 1
for i in arr:
    print("".join(i), end="")