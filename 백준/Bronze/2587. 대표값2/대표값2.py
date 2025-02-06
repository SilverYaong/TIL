arr = []
for i in range(5):
    arr.append(int(input()))
average = int(sum(arr) / 5)
print(average)
arr.sort()
print(arr[2])