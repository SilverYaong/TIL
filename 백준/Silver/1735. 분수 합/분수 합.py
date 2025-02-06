def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return (a * b) // gcd(a, b)

a, b = map(int, input().split())
c, d = map(int, input().split())
bottom = lcm(b, d)
top = (bottom // b) * a + (bottom // d) * c
e = gcd(top, bottom)
if e == 1:
    print(top, bottom)
else:
    print(top // e, bottom // e)