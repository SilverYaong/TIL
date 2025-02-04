x = int(input())
y = int(input())
z = int(input())

if x == 60 and y == 60 and z == 60:
    print("Equilateral")
elif x + y + z == 180:
    if x == y or x == z or y == z:
        print("Isosceles")
    else:
        print("Scalene")
else:
    print("Error")