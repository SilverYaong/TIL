n = int(input())
for _ in range(n):
    s = input()
    cnt = 0
    ans = 0
    for i in s:
        if i == 'O':
            cnt += 1
            ans += cnt
        else:
            cnt = 0
    print(ans)