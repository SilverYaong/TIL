n = int(input())
count = 0
num = 665

while count < n:
    num += 1
    num_str = str(num)
    six_count = 0
    for i in range(len(num_str)):
        if six_count > 0 and num_str[i] != '6':
            six_count = 0
        if num_str[i] == '6':
            six_count += 1
            if six_count == 3:
                count += 1
                break
print(num)