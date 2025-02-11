def get_comb(arr, n):
    comb_list = []
    if n == 0:
        return [[]]
    for i in range(len(arr)):
        num = arr[i]
        arr_left = arr[i + 1 :]
        for comb in get_comb(arr_left, n - 1):
            comb_list.append([num] + comb)
    return comb_list


arr = [int(input()) for _ in range(9)]
arr.sort()
comb = get_comb(arr, 7)
bk = False
for i in comb:
    if bk:
        break
    if sum(i) == 100:
        bk = True
        for j in i:
            print(j)