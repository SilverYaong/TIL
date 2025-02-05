n = int(input())

count_list = []

def sol(num):
    global count_list
    for i in range(n // 3 + 1):
        for j in range(n // 3 + 1):
            weight = 0
            weight = j * 3 + i * 5
            if weight == num:
                count_list.append(j + i)

sol(n)

if count_list:
    print(min(count_list))
else:
    print(-1)