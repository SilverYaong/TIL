import sys

n, m = map(int, input().split())
pokemon = {}
for i in range(n):
    a = sys.stdin.readline()
    pokemon[i + 1] = a.rstrip("\n")
pokemon_alt = {value : key for key, value in pokemon.items()}
for i in range(m):
    a = sys.stdin.readline()
    quest = a.rstrip('\n')
    if quest.isdecimal() == True:
        print(pokemon[int(quest)])
    else:
        print(pokemon_alt[quest])