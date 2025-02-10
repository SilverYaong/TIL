import sys

n, m = map(int, input().split())
word_set = set()
word_dict = {}
word_list = []
for _ in range(n):
    word = sys.stdin.readline().rstrip()
    if len(word) >= m:
        if word not in word_set:
            word_set.add(word)
            word_dict[word] = 0
        else:
            word_dict[word] += 1
word_list = sorted(word_dict.items(), key = lambda x: (-x[1], -len(x[0]), x[0]))
for word in word_list:
    print(word[0])