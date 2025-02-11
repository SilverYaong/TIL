n = int(input())
s = '*' + input()
s = s.replace('S', 'S*').replace('LL', 'LL*')
ans = s.count("*")
if ans > n:
    ans = n
print(ans)