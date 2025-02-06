n, m = map(int, input().split())
my_word = set()
check_word = []
for _ in range(n):
    my_word.add(input())
for _ in range(m):
    check_word.append(input())

check_word = [1 if x in my_word else 0 for x in check_word]
print(sum(check_word))