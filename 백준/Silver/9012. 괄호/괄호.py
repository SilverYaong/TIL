def vps(s, i):
    cnt = 0
    for _ in range(i):
        if cnt < 0:
            print("NO")
            return
        chk = s.pop()
        if chk == "(":
            cnt -= 1
        elif chk == ")":
            cnt += 1
    print("YES" if cnt == 0 else "NO")
    return

t = int(input())
for _ in range(t):
    s = []
    s += input()
    i = len(s)
    if i % 2 != 0:
        print('NO')
    else:
        vps(s, i)