def team(arr, start = 1, team1 = None):
    if ans == 0:
        return
    if team1 is None:
        team1 = [arr[0]]
    
    if len(team1) == r:
        team2 = [x for x in num_arr if x not in team1]
        sol(team1, team2)
        return
    
    for i in range(start, n):
        team(arr, i + 1, team1 + [arr[i]])

def sol(team1, team2):
    global ans
    team1_val = 0
    team2_val = 0
    for i in range(r):
        for j in range(r):
            if i != j:
                team1_val += arr[team1[i]][team1[j]]
                team2_val += arr[team2[i]][team2[j]]
    ans = min(ans, abs(team1_val - team2_val))

n = int(input())
r = n // 2

arr = [[*map(int, input().split())] for _ in range(n)]
num_arr = range(n)

ans = 100

team(num_arr)
print(ans)