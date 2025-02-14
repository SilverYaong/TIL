def sol(cur):
    global cnt
    if cur == n:
        cnt += 1
        return
    for i in range(n):
        if chk1[i] or chk2[i + cur] or chk3[cur - i + n - 1]:
            continue
        chk1[i] = True
        chk2[i + cur] = True
        chk3[cur - i + n - 1] = True
        sol(cur + 1)
        chk1[i] = False
        chk2[i + cur] = False
        chk3[cur - i + n - 1] = False


n = int(input())
chk1 = [False] * n
chk2 = [False] * (n * 2 - 1)
chk3 = [False] * (n * 2 - 1)
cnt = 0
sol(0)
print(cnt)