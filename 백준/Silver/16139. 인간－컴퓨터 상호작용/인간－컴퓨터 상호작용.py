import sys

s = input()
n = int(input())
char_arr = []
left_arr = []
right_arr = []
for _ in range(n):
    char, left, right = sys.stdin.readline().rstrip().split()
    left = int(left)
    right = int(right)
    char_arr.append(char)
    left_arr.append(left)
    right_arr.append(right)
    
for i in range(n):
    ans = 0
    for j in range(left_arr[i], right_arr[i] + 1):
        if s[j] == char_arr[i]:
            ans += 1
    print(ans)