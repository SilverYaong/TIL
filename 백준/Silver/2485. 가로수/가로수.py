from math import gcd

n = int(input())
tree = []
for i in range(n):
    tree.append(int(input()))
distance = []
for i in range(n - 1, 0, -1):
    distance.append(tree[i] - tree[i - 1])
min_distance = gcd(*distance)
distance = [x // min_distance for x in distance]
print(sum(distance) - n + 1)