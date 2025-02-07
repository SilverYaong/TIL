def isPrime(n):
    if n <= 1:
        return False
    elif n <= 3:
        return True
    elif n % 2 == 0 or n % 3 == 0:
        return False
    else:
        i = 5
        while i * i <= n:
            if n % i == 0 or n % (i + 2) == 0:
                return False
            i += 6
    return True

t = int(input())

for _ in range(t):
    n = int(input())
    prime_num = n
    while not isPrime(prime_num):
        prime_num += 1
    print(prime_num)