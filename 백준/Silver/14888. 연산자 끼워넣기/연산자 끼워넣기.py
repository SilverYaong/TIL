def sol(k, num):
    global max_res, min_res

    if k == n:
        max_res = max(max_res, num)
        min_res = min(min_res, num)
        return

    for i in range(4):
        if oper_arr[i] > 0:
            if i == 0:
                oper_arr[i] -= 1
                sol(k + 1, num + num_arr[k])
                oper_arr[i] += 1
            if i == 1:
                oper_arr[i] -= 1
                sol(k + 1, num - num_arr[k])
                oper_arr[i] += 1
            if i == 2:
                oper_arr[i] -= 1
                sol(k + 1, num * num_arr[k])
                oper_arr[i] += 1
            if i == 3:
                oper_arr[i] -= 1
                sol(k + 1, int(num / num_arr[k]))
                oper_arr[i] += 1


n = int(input())
num_arr = [*map(int, input().split())]
oper_arr = [*map(int, input().split())]
max_res, min_res = -1_000_000_000, 1_000_000_000

sol(1, num_arr[0])

print(max_res)
print(min_res)