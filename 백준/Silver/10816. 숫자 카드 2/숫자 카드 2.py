n = int(input())
my_card = list(map(int, input().split()))
m = int(input())
check_num = list(map(int, input().split()))

count_dict = {}
for num in my_card:
    if num in count_dict:
        count_dict[num] += 1
    else:
        count_dict[num] = 1
check_num = [count_dict[x] if x in count_dict else 0 for x in check_num]
print(*check_num)