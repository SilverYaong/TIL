# 알고리즘
---
## DP

점화식 생각 안날 때는 경우의  수를 작게 하여 하나씩 생각해보자

백준 2579 계단의 경우

계단이 다섯개일 때,

- 1번 계단을 반드시 밟는 경우: 1
- 2번 계단을 반드시 밟는 경우: 1-2
- 3번 계단을 반드시 밟는 경우: 1-3, 2-3
- 4번 계단을 반드시 밟는 경우: 1-2-4, 1-3-4, 2-4
- 5번 계단을 반드시 밟는 경우: 1-2-4-5, 1-3-5, 2-3-5
  
위를 식으로 정리

- score[1] = stair[1]
- score[2] = score[1] + stair[2]
- score[3] = score[1] + stair[3] 또는 score[2] + stair[3] (둘 중 최댓값)

일반화하는 과정

- score[4]
 - 1-2-4: score[2] + stair[4] ( score[2] = score[1] + stair[2] )
 - 1-3-4: score[1] + stair[3] + stair[4]
- score[5]
 - 1-3-5와 2-3-5: score[3] + stair[5] (score[3] 에서의 최댓값 + stair[5])
 - 1-2-4-5: score[2] + stair[4] + stair[5]
  
계단의 수를 N이라고 했을 때의 점화식

- score[N] = score[N-2] + stair[N]
- score[N] = score[N-3] + stair[N-1] + stair[N]
  
출처 : https://baehoon.tistory.com/49