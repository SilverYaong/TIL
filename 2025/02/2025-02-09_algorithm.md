# 알고리즘
---
## 연결 리스트로 스택 구현

값을 가리킬 `노드` 구조체를 생성하고 `스택`을 구현할 스택 클래스 생성

### 노드

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # 다음 노드를 가리키는 포인터 역할
```

`Node`는 생성될 때 현재 값을 기록하고 `self.data = data`

다음 값은 아무것도 가리키지 않음 `self.next = None`

### 스택

```python
class Stack:
    def __init__(self):
        self.top = None  # 스택의 최상단 노드
        self.cnt = 0    # 스택 요소 개수

    def push(self, x):
        new_node = Node(x)
        new_node.next = self.top  # 새 노드가 기존 top을 가리키게 함
        self.top = new_node  # top을 새로운 노드로 변경

    def pop(self):
        if self.top is None:
            return None

        val = self.top.data
        self.top = self.top.next  # 현재 top을 다음 노드로 변경
        return val

    def peek(self):
        return self.top.data if self.top else None

    def is_empty(self):
        return self.top is None

    def count(self):
        return self.cnt
```

`Stack`은 생성될 때 아무것도 가리키지 않음 `self.top = None`

요소의 개수를 세기 위해 인스턴스 변수를 0으로 초기화

스택에 노드가 추가되면 새로운 노드를 생성하고 `new_node = Node(val)`

새 노드가 기존에 가리키던 값을 가리키게 함 `new_node.next = self.top`

그 후 최상단 노드를 새 노드로 변경하고 요소의 개수를 증가시킴

값을 꺼낼 때 최상단 노드가 아무것도 가리키지 않으면 스택이 비어있는 것임

그게 아니라면 최상단 노드를 저장해두고 최상단 노드를 다음 노드로 변경해준 뒤 저장했던 최상단 노드를 반환하고 요소의 개수를 감소시킴

현재 최상단 노드를 확인할 때는 노드가 아무것도 가리키는 것이 아니면 최상단 노드를 반환함

비어있는지 확인할 때는 최상단 노드가 None인지 확인해서 반환

요소의 개수를 출력하기 위해 인스턴스 변수의 요소 개수를 반환

## 연결 리스트로 원형 덱 구현

```python
class Node:
    def __init__(self, data):
        self.data = data  # 노드에 저장할 데이터
        self.prev = None  # 이전 노드를 가리키는 포인터
        self.next = None  # 다음 노드를 가리키는 포인터


class Deque:
    def __init__(self):
        self.front = None  # 덱의 앞
        self.rear = None  # 덱의 뒤

    # 덱이 비어 있는지 확인
    def is_empty(self):
        return self.front is None

    # 덱의 앞에 삽입
    def push_front(self, x):
        new_node = Node(x)
        if self.is_empty():  # 덱이 비어 있을 때
            self.front = self.rear = new_node  # front와 rear가 동일한 노드를 가리킴
        else:
            new_node.next = self.front  # 새로운 노드의 next가 기존 front를 가리킴
            self.front.prev = new_node  # 기존 front의 prev가 새로운 노드를 가리킴
            self.front = new_node  # front 포인터를 새 노드로 변경

    # 덱의 뒤에 삽입
    def push_back(self, x):
        new_node = Node(x)
        if self.is_empty():  # 덱이 비어 있을 때
            self.front = self.rear = new_node  # front와 rear가 동일한 노드를 가리킴
        else:
            self.rear.next = new_node  # 기존 rear의 next가 새 노드를 가리킴
            new_node.prev = self.rear  # 새로운 노드의 prev가 기존 rear를 가리킴
            self.rear = new_node  # rear 포인터를 새 노드로 변경
            

    # 덱의 앞에서 삭제
    def pop_front(self):
        if self.is_empty():  # 덱이 비어 있을 때
            return
        temp = self.front
        self.front = self.front.next  # front 포인터를 다음 노드로 이동
        if self.front:  # front가 None이 아니면
            self.front.prev = None  # 새로운 front의 prev를 None으로 설정
        else:
            self.rear = None  # 덱이 비어 있으면 rear도 None으로 설정
        return temp.data

    # 덱의 뒤에서 삭제
    def pop_back(self):
        if self.is_empty():  # 덱이 비어 있을 때
            return
        temp = self.rear
        self.rear = self.rear.prev  # rear 포인터를 이전 노드로 이동
        if self.rear:  # rear가 None이 아니면
            self.rear.next = None  # 새로운 rear의 next를 None으로 설정
        else:
            self.front = None  # 덱이 비어 있으면 front도 None으로 설정
        return temp.data

    # 덱의 앞을 반환
    def get_front(self):
        if self.is_empty():
            return None
        return self.front.data

    # 덱의 뒤를 반환
    def get_rear(self):
        if self.is_empty():
            return None
        return self.rear.data

    # 덱을 출력
    def display(self):
        if self.is_empty():
            print("Deque is empty")
            return
        current = self.front
        while current:
            print(current.data, end=" ")
            current = current.next
        print()
```
