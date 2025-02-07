# 알고리즘
---
## 소수 판별

소수 판별하는 방법은 2부터 찾고자하는 수의 제곱근의 범위에서 나누어 떨어지는 수가 없으면 소수인 것으로 판정한다

나누어 볼 수의 범위는 위와 같고

6k ± 1을 사용하면 소수를 빠르게 판별할 수 있음

0과 1은 소수가 아니고

2와 3은 소수이고

2나 3으로 나누어 떨어지면 소수가 아니고

마지막 조건 검사에서 반복변수 초기값을 5로 설정 후 `반복변수 * 반복변수`가 찾는 수 이하일 때만 반복함

반복 변수는 6씩 증가 시킴으로써 기본적으로 `6k + 5`의 형태가 됨

반복하는 변수의 제곱이 조건이 되는 이유는 제곱근까지 검사하면 되기 때문임

`6k + 1`과 같은 의미인 `6k + (5 + 2) = 6k + 7`를 만들어 나누어 떨어지거나

`6k - 1`과 같은 의미인 `6k + 5`를 만들어 나누어 떨어지면 소수가 아님

```python
def isPrime(n):
    if n <= 1:
        return False
    elif n <= 3:
        return True
    elif n % 2 == 0 or n % 3 == 0:
        return False
    else:
        i = 5
        while i * i <= n:
            if n % i == 0 or n % (i + 2) == 0:
                return False
            i += 6
    return True
```

## 에라토스테네스의 체

수의 범위가 정해져 있고 소수를 계속 가져다가 사용해야 하면 이 방법이 좋음

최대값 + 1 만큼의 bool 배열을 True로 생성

배열의 인덱스가 숫자를 나타내게 됨

0과 1은 소수가 아니므로 False

2부터 최대값의 제곱근을 정수로 변환하고 + 1 까지 반복하는데 현재 확인하고 있는 수를 나타내며 i라고 나타내겠음

i가 True로 되어있으면 두번째 반복문을 실행함

i * i부터 시작하여 최대값까지 반복하는데 i 값만큼 단계를 건너 뛸것임

결국 i를 제외한 i의 배수를 전부 False로 만들어주는 것

그 후 처음에 생성한 배열에서 True인 값만 뽑아서 반환하면 소수 리스트가 만들어짐

```python
def sieve(max_n):
    is_prime = [True] * (max_n + 1)
    is_prime[0] = is_prime[1] = False
    
    for i in range(2, int(max_n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, max_n + 1, i):
                is_prime[j] = False
    
    return [i for i in range(max_n + 1) if is_prime[i]]
```

## 부분집합

부분집합을 만드는 방법은 몇가지가 있는데 그 중 한가지

결과를 저장할 집합을 공집합을 포함해 생성해주고 `subsets = [[]]`

배열의 요소를 하나씩 확인하면서 subsets의 요소에다가 현재 요소를 다시 추가한 뒤에 subsets에 추가해줌

만약 `[1, 2, 3]`의 배열이 있다면

`[1]` -> `[2]` -> `[1] + [2]` 순서로 추가가 되고

이 시점에 subsets는 `[[], [1], [2], [1, 2]]`이므로 각각 3을 추가해 다시 리스트에 넣어주게 된다

```python
def get_subsets(arr):
    subsets = [[]]
    for num in arr:
        subsets += [s + [num] for s in subsets]
    return subsets
```