def merge_sort(arr, left, right):
    if left < right:    
        mid = (left + right) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)

def merge(arr, left, mid, right):
    global cnt, ans
    
    result = []
    i, j = left, mid + 1

    while i <= mid and j <= right:
        if arr[i] < arr[j]:
            result.append(arr[i])
            i += 1
        else:
            result.append(arr[j])
            j += 1
            
    while i <= mid:
        result.append(arr[i])
        i += 1

    while j <= right:
        result.append(arr[j])
        j += 1
            
    
    for i in range(len(result)):
        arr[left + i] = result[i]
        cnt += 1
        if cnt == k:
            ans = arr[left + i]
            return

n, k = map(int, input().split())
a = [*map(int, input().split())]

cnt = 0
ans = -1

merge_sort(a, 0, n - 1)

print(ans)