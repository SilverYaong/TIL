n = int(input())
my_card = set(map(int, input().split()))
m = int(input())
check_num = list(map(int, input().split()))
check_num = [1 if x in my_card else 0 for x in check_num]

print(*check_num)