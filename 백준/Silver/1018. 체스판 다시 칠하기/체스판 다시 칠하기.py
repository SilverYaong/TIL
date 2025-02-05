n, m = map(int, input().split())
arr = []
for i in range(n):
    arr.append(list(input()))
result = 32
for row in range(n - 8 + 1):
    for col in range(m - 8 + 1):
        count = 0
        for i in range(8):
            for j in range(8):
                if i % 2 == 0:
                    if j % 2 == 1:
                        if arr[i + row][j + col] == 'W':
                            count += 1
                    else:
                        if arr[i + row][j + col] == "B":
                            count += 1
                else:
                    if j % 2 == 1:
                        if arr[i + row][j + col] == "B":
                            count += 1
                    else:
                        if arr[i + row][j + col] == "W":
                            count += 1
        if count < result:
            result = count
        count = 0
        for i in range(8):
            for j in range(8):
                if i % 2 == 0:
                    if j % 2 == 1:
                        if arr[i + row][j + col] == "B":
                            count += 1
                    else:
                        if arr[i + row][j + col] == "W":
                            count += 1
                else:
                    if j % 2 == 1:
                        if arr[i + row][j + col] == "W":
                            count += 1
                    else:
                        if arr[i + row][j + col] == "B":
                            count += 1
        if count < result:
            result = count
print(result)