import heapq

n = int(input())
hp = []
for i in range(n):
    tmp = [*map(int, input().split())]
    if not hp:
        for num in tmp:
            heapq.heappush(hp, num)
    else:
        for num in tmp:
            if hp[0] < num:
                heapq.heappush(hp, num)
                heapq.heappop(hp)

print(hp[0])