n, m, l = map(int, input().split())
cnt = 0
cnt_arr = [0] * n
cnt_arr[0] = 1
target = 0
while True:
    if cnt_arr[target] == m:
        break
    if cnt_arr[target] % 2 == 1:
        target += l
        if target >= n:
            target %= n
        cnt_arr[target] += 1
    else:
        target -= l
        if target < 0:
            target += n
        cnt_arr[target] += 1
    cnt += 1
print(cnt)