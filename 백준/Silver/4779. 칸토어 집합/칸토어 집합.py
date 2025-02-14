dp = [0] * 13
dp[0] = '-'

for i in range(1, 13):
    dp[i] = ''.join(dp[i - 1] + ' ' * len(dp[i - 1]) + dp[i - 1])

while True:
    try:
        print(dp[int(input())])
    except:
        break