tc = int(input())

for t in range(tc):
    n = int(input())
    bus = [[*map(int, input().split())] for _ in range(n)]
    p = int(input())
    c = [int(input()) for _ in range(p)]
    ans = [0] * p
    
    for i in bus:
        min_num = i[0]
        max_num = i[1]
        for j in range(p):
            if c[j] <= max_num and c[j] >= min_num:
                ans[j] += 1
                
    
    print(f'#{t + 1} ', end = '')
    print(*ans)