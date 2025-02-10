from collections import deque

tc = int(input())

for t in range(tc):
    dq = deque()
    stick = input()
    stick = stick.replace('()', '0')
    ans = 0
    for i in range(len(stick)):
        if stick[i] == '(':
            dq.append(stick[i])
        elif stick[i] == ')':
            dq.pop()
            ans += 1
        elif stick[i] == '0':
            ans += len(dq)
            
    print(f'#{t + 1} {ans}')