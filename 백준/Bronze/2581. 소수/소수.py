import math

m = int(input())
n = int(input())
arr = list(range(m, n + 1))
prime_list = []

def prime(num):
    if num < 2:
        return 0
    for x in range(2, int(math.sqrt(num)) + 1):
        if num % x == 0:
            return 0
    return num

for i in arr:
    num = prime(i)
    if num != 0:
        prime_list.append(num)

ans = sum(prime_list)

if ans == 0:
    print(-1)
else:
    print(ans)
    print(min(prime_list))