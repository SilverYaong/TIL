import sys

k = int(input())
num_list = []
for _ in range(k):
    n = sys.stdin.readline().rstrip()
    if n == '0':
        num_list.pop()
    else:
        num_list.append(int(n))
        
print(sum(num_list))