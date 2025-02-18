import sys

s = input()
n = int(input())

pre_sum = {chr(c) : [0] * (len(s) + 1) for c in range(97, 123)}

for i, char in enumerate(s):
    for c in pre_sum:
        pre_sum[c][i + 1] = pre_sum[c][i] + (1 if c == char else 0)

res = []

for _ in range(n):
    char, left, right = sys.stdin.readline().split()
    left, right = int(left), int(right)
    
    ans = pre_sum[char][right + 1] - pre_sum[char][left]
    res.append(str(ans))
    
sys.stdout.write('\n'.join(res) + '\n')