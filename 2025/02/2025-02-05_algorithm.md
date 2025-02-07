# 알고리즘
---
## 버블정렬

최대값을 끝으로 보내면서 점점 빨라짐

```python
for i in range(n):
    for j in range(n - i - 1):
        if arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]
```