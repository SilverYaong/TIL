def sieve(max_n):
    is_prime = [True] * (max_n + 1)
    is_prime[0] = is_prime[1] = False
    
    for i in range(2, int(max_n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, max_n + 1, i):
                is_prime[j] = False
    
    return [i for i in range(max_n + 1) if is_prime[i]]

test_case = int(input())
nums = [int(input()) for _ in range(test_case)]

max_n = max(nums)
primes = sieve(max_n)
prime_set = set(primes)

for n in nums:
    count = 0
    for prime in primes:
        if prime > n // 2:
            break
        if (n - prime) in prime_set:
            count += 1
    print(count)