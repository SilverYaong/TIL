n = int(input())
arr = list(map(int, input().split()))

numbers = sorted(set(arr))

compress = {num: x for x, num in enumerate(numbers)}

arr = [compress[x] for x in arr]

print(*arr)