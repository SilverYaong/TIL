import math

n = int(input())
arr = list(map(int, input().split()))
ans = 0

def prime(num):
    if num < 2:
        return False
    for x in range(2, int(math.sqrt(num)) + 1):
        if num % x == 0:
            return False
    return True

for i in arr:
    if prime(i):
        ans += 1
        
print(ans)