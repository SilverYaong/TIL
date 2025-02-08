n = int(input())
numbers = list(map(int, input().split()))
stack = []
current_num = 1

for num in numbers:
    if num == current_num:
        current_num += 1
    else:
        while stack and stack[-1] == current_num:
            stack.pop()
            current_num += 1
        stack.append(num)

while stack and stack[-1] == current_num:
    stack.pop()
    current_num += 1
        
if stack:
    print('Sad')
else:
    print('Nice')    