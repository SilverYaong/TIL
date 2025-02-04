n = int(input())
while n != -1:
    list = []
    for i in range(n // 2 + 1):
        if n % (i + 1) == 0:
            list.append(i + 1)
    if sum(list) == n:
        print(f'{n} = ', end="")
        for i in list:
            if n // 2 <= i:
                print(i)
            else:
                print(f'{i} + ',end="")
    else:
        print(f'{n} is NOT perfect.')
    n = int(input())