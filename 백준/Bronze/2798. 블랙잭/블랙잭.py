n, m = map(int, input().split())
card = list(map(int, input().split()))
def find_ans(card, n, m):
    result = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            for k in range(j + 1, n):
                tmp_sum = card[i] + card[j] + card[k]
                if tmp_sum == m:
                    result = tmp_sum
                    return result
                elif tmp_sum > m:
                    continue
                elif tmp_sum > result:
                    result = tmp_sum
    return result
print(find_ans(card, n, m))