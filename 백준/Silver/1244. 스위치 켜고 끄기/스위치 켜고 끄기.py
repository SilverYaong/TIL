switch_len = int(input())
switch = [*map(int, input().split())]
n = int(input())
ppl = [[*map(int, input().split())] for _ in range(n)]

for person in ppl:
    if person[0] == 1:
        for i in range(switch_len):
            if (i + 1) % person[1] == 0:
                if switch[i] == 0:
                    switch[i] = 1
                else:
                    switch[i] = 0
    else:
        i = person[1] - 1
        j = 1
        if switch[i] == 0:
            switch[i] = 1
        else:
            switch[i] = 0

        while i - j >= 0 and i + j <= switch_len - 1:
            if switch[i - j] == switch[i + j]:
                if switch[i - j] == 0:
                    switch[i - j] = 1
                else:
                    switch[i - j] = 0
                    
                if switch[i + j] == 0:
                    switch[i + j] = 1
                else:
                    switch[i + j] = 0
            else:
                break
            j += 1

for i in range(0, switch_len, 20):
    print(' '.join(map(str, switch[i : i + 20])))