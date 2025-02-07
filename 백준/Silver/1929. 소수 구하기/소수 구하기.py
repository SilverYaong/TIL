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

n, m = map(int, input().split())
prime_num = n
while prime_num <= m:
    while not isPrime(prime_num):
        prime_num += 1
    if prime_num <= m:
        print(prime_num)
    prime_num += 1
