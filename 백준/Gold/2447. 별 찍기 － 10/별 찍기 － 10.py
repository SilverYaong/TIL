def sol(n):
    if n == 1:
        return ['*']
    div = sol(n // 3)
    res = []
    
    for i in div:
        res.append(i * 3)
    for i in div:
        res.append(i + ' ' * (n // 3) + i)
    for i in div:
        res.append(i * 3)
        
    return res
    
ans = sol(int(input()))

for i in ans:
    print(''.join(i))