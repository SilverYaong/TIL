test_case = int(input())

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return (a * b) // gcd(a, b)

for i in range(test_case):
    a, b = map(int, input().split())
    print(lcm(a, b))