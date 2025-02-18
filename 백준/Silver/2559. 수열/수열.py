n, k = map(int, input().split())
arr = [*map(int, input().split())]
sum_arr = [0] * (n - k + 1)
ans = 0
sum_arr[0] = sum(arr[:k])
for i in range(1, n - k + 1):
    sum_arr[i] = sum_arr[i - 1] - arr[i - 1] + arr[i + k - 1]
print(max(sum_arr))