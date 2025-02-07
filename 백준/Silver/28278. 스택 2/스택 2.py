import sys

n = int(input())
stack = []
for _ in range(n):
    command = sys.stdin.readline().rstrip()
    if command.startswith('1'):
        _, x = command.split()
        stack.append(int(x))
        
    elif command == '2':
        if stack:
            print(stack.pop())
        else:
            print(-1)
    
    elif command == '3':
        print(len(stack))
    
    elif command == '4':
        print(0 if stack else 1)
        
    else:
        if stack:
            print(stack[-1])
        else:
            print(-1)