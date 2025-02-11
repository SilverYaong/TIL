for t in range(10):
    n = int(input())
    arr = [[*map(int, input().split())] for _ in range(100)]

    cnt = 0

    for i in range(100):
        for j in range(100):
            if arr[j][i] == 0:
                continue
            elif arr[j][i] == 1:
                while j < 99:
                    j += 1
                    if arr[j][i] == 2:
                        cnt += 1
                        break
                    if arr[j][i] == 1:
                        j -= 1
                        break
    print(f'#{t + 1} {cnt}')