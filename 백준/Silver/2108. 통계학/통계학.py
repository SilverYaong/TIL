import sys

def my_round(n):
    if n > 0:
        if n - int(n) >= 0.5:
            return int(n) + 1
        return int(n)
    elif n < 0:
        if n - int(n) <= -0.5:
            return int(n) - 1
        return int(n)
    else:
        return 0

n = int(input())
my_list = []
num_list = [0] * 8001
for _ in range(n):
    x = sys.stdin.readline().rstrip()
    my_list.append(int(x))
    num_list[int(x) + 4000] += 1
avg = sum(my_list) / n
my_list.sort()
mid = my_list[n // 2]
max_freq = max(num_list)
max_freq_cnt = num_list.count(max_freq)
cnt = 0
if max_freq_cnt > 1:
    for i in range(8001):
        if num_list[i] == max_freq:
            if cnt == 1:
                freq = i - 4000
                break
            cnt += 1
else:
    freq = num_list.index(max_freq) - 4000
n_range = max(my_list) - min(my_list)
print(my_round(avg))
print(mid)
print(freq)
print(n_range)