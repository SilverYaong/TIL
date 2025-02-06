s = input()
count = 0
my_set = set()
for i in range(len(s)):
    for j in range(i + 1, len(s) + 1):
        my_set.add(s[i:j])    
print(len(my_set))