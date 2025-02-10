def makelist(n, arr):
    num_list = []
    global result_list
    for num in arr:
        num_list.append(num * n)
    for num in num_list:
        chknum = [*map(int, str(num))]
        if chk(chknum):
            result_list.append(num)
    return

def chk(n):
    for i in range(len(n) - 1):
        if n[i] > n[i + 1]:
            return False
    return True


tc = int(input())
result_list = []

for t in range(tc):
    result_list.clear()
    ans = -1
    n = int(input())
    a = [*map(int, input().split())]
    for i in range(n - 1):
        makelist(a[i], a[i + 1:])
    
    if result_list:
        ans = max(result_list)
    
    print(f'#{t + 1} {ans}')