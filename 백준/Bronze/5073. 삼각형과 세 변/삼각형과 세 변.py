n = list(map(int, input().split()))
while sum(n) != 0:
    n.sort()
    if n[2] >= n[0] + n[1]:
        print("Invalid")
    elif n[0] == n[1] == n[2]:
        print("Equilateral")
    elif n[0] == n[1] or n[0] == n[2] or n[1] == n[2]:
        print("Isosceles")
    else:
        print("Scalene")
    n = list(map(int, input().split()))