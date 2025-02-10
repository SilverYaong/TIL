from collections import deque

tc = int(input())
for t in range(tc):
    n, m, k = map(int, input().split())
    arrive_time = deque(sorted(map(int, input().split())))
    stock = 0
    sold = 0
    ans = 'Possible'

    while arrive_time:
        time = arrive_time[0]
                
        stock = (time // m) * k - sold
        
        while arrive_time and arrive_time[0] == time:
            arrive_time.popleft()
            stock -= 1
            sold += 1
            if stock < 0:
                ans = 'Impossible'
                break

        if ans == 'Impossible':
            break

    print(f'#{t + 1} {ans}')