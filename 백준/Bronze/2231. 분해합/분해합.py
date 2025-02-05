n = int(input())

def sol(n):
    ans = 0
    for i in range(n):
        ans = num_sum(i)
        if ans == n:
            return i
    return 0

def num_sum(num):
    num_str = str(num)
    result = num
    for i in range(len(num_str)):
        result += int(num_str[i])
    return result

print(sol(n))