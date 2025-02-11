def chkBingo(arr):
    bingo = 0
    cnt = 0

    for i in range(5):
        for j in range(5):
            if arr[i][j]:
                cnt += 1
            else:
                cnt = 0
                break
        if cnt == 5:
            bingo += 1
        cnt = 0

    for i in range(5):
        for j in range(5):
            if arr[j][i]:
                cnt += 1
            else:
                cnt = 0
                break
        if cnt == 5:
            bingo += 1
        cnt = 0

    for i in range(5):
        if arr[i][i]:
            cnt += 1
        else:
            cnt = 0
            break
    if cnt == 5:
        bingo += 1
    cnt = 0

    for i in range(5):
        if arr[i][4 - i]:
            cnt += 1
        else:
            cnt = 0
            break
        if cnt == 5:
            bingo += 1

    return bingo


my_bingo = [[*map(int, input().split())] for _ in range(5)]
call_number = [[*map(int, input().split())] for _ in range(5)]
cnt = 0
chk_arr = [[False] * 5 for _ in range(5)]
ans = 0
bingo = False

for i in range(5):
    for j in range(5):
        cnt += 1
        for ii in range(5):
            for jj in range(5):
                if call_number[i][j] == my_bingo[ii][jj]:
                    chk_arr[ii][jj] = True
                    if chkBingo(chk_arr) >= 3:
                        bingo = True
                        ans = cnt
                        break
        if bingo:
            break
    if bingo:
        break


print(ans)
