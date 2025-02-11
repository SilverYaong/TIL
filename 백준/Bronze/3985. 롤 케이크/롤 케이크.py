l = int(input())
n = int(input())
my_dict = {}
fake_max = 0
real_max = 0
cake = [False] * (l + 1)

for i in range(1, n + 1):
    p, k = map(int, input().split())
    m = k - p + 1
    if m > fake_max:
        fake_max = m
        fake_max_num = i
    my_dict[i] = (p, k)

for num in my_dict:
    m = 0
    for i in range(my_dict[num][0], my_dict[num][1] + 1):
        if cake[i]:
            continue
        cake[i] = True
        m += 1
    if m > real_max:
        real_max = m
        real_max_num = num
    
print(fake_max_num)
print(real_max_num)