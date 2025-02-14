def chk(x, y, num):
    for i in range(9):
        if arr[x][i] == num or arr[i][y] == num:
            return False
    
    nx, ny = (x // 3) * 3, (y // 3) * 3
    for i in range(3):
        for j in range(3):
            if arr[nx + i][ny + j] == num:
                return False
            
    return True

def sol():
    for i in range(9):
        for j in range(9):
            if arr[i][j] == 0:
                for num in range(1, 10):
                    if chk(i, j, num):
                        arr[i][j] = num
                        if sol():
                            return True
                        arr[i][j] = 0
                return False
    return True
                
arr = [[*map(int, input().split())] for _ in range(9)]

sol()

for i in arr:
    print(*i)