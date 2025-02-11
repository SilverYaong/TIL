a = []
b = []
for i in range(10):
    a.append(int(input()))
for i in range(10):
    b.append(a[i] % 42)
print(len(set(b)))
