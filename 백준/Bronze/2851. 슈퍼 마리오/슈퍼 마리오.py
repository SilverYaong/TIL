arr = []
current_score = 0

for _ in range(10):
    arr.append(int(input()))
    
for i in arr:
    if current_score + i < 100:
        current_score += i
    elif current_score + i == 100:
        current_score = 100
        break
    elif current_score + i > 100:
        if (current_score + i - 100) <= (100 - current_score):
            current_score += i
        break
    
print(current_score)