n = int(input())
my_dict = {}
for i in range(n):
    name, status = map(str, input().split())
    my_dict[name] = status
    if status == 'leave':
        del my_dict[name]
my_dict = sorted(my_dict, reverse = True)
for i in my_dict:
    print(i)