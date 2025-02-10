tc = int(input())
for t in range(tc):
    n = input()
    current_clap = 0
    ans = 0
    for i in range(len(n)):
        if n[i] != '0':
            if current_clap < i:
                ans += i - current_clap
                current_clap = i + int(n[i])
            else:
                current_clap += int(n[i])

    print(f"#{t + 1} {ans}")