import sys

class Node:
    def __init__(self, data):
        self.data = data  # 노드에 저장할 데이터
        self.prev = None  # 이전 노드를 가리키는 포인터
        self.next = None  # 다음 노드를 가리키는 포인터

class Deque:
    def __init__(self):
        self.front = None  # 덱의 앞
        self.rear = None  # 덱의 뒤
        self.cnt = 0

    # 덱이 비어 있는지 확인
    def is_empty(self):
        return self.front is None

    # 덱의 앞에 삽입
    def push_front(self, x):
        new_node = Node(x)
        if self.is_empty():  # 덱이 비어 있을 때
            self.front = self.rear = new_node  # front와 rear가 동일한 노드를 가리킴
            self.cnt += 1
        else:
            new_node.next = self.front  # 새로운 노드의 next가 기존 front를 가리킴
            self.front.prev = new_node  # 기존 front의 prev가 새로운 노드를 가리킴
            self.front = new_node  # front 포인터를 새 노드로 변경
            self.cnt += 1

    # 덱의 뒤에 삽입
    def push_back(self, x):
        new_node = Node(x)
        if self.is_empty():  # 덱이 비어 있을 때
            self.front = self.rear = new_node  # front와 rear가 동일한 노드를 가리킴
            self.cnt += 1
        else:
            self.rear.next = new_node  # 기존 rear의 next가 새 노드를 가리킴
            new_node.prev = self.rear  # 새로운 노드의 prev가 기존 rear를 가리킴
            self.rear = new_node  # rear 포인터를 새 노드로 변경
            self.cnt += 1

    # 덱의 앞에서 삭제
    def pop_front(self):
        if self.is_empty():  # 덱이 비어 있을 때
            return -1
        temp = self.front
        self.front = self.front.next  # front 포인터를 다음 노드로 이동
        self.cnt -= 1
        if self.front:  # front가 None이 아니면
            self.front.prev = None  # 새로운 front의 prev를 None으로 설정
        else:
            self.rear = None  # 덱이 비어 있으면 rear도 None으로 설정
        return temp.data

    # 덱의 뒤에서 삭제
    def pop_back(self):
        if self.is_empty():  # 덱이 비어 있을 때
            return -1
        temp = self.rear
        self.rear = self.rear.prev  # rear 포인터를 이전 노드로 이동
        self.cnt -= 1
        if self.rear:  # rear가 None이 아니면
            self.rear.next = None  # 새로운 rear의 next를 None으로 설정
        else:
            self.front = None  # 덱이 비어 있으면 front도 None으로 설정
        return temp.data

    # 덱의 앞을 반환
    def get_front(self):
        if self.is_empty():
            return -1
        return self.front.data

    # 덱의 뒤를 반환
    def get_rear(self):
        if self.is_empty():
            return -1
        return self.rear.data
    
    def get_count(self):
        return self.cnt


n = int(input())
my_deque = Deque()

for _ in range(n):
    cmd = sys.stdin.readline().rstrip()
    if cmd[0] == '1':
        my_deque.push_front(cmd[2:])
    elif cmd[0] == '2':
        my_deque.push_back(cmd[2:])
    elif cmd == '3':
        print(my_deque.pop_front())
    elif cmd == '4':
        print(my_deque.pop_back())
    elif cmd == '5':
        print(my_deque.get_count())
    elif cmd == '6':
        print(1 if my_deque.is_empty() else 0)
    elif cmd == '7':
        print(my_deque.get_front())
    elif cmd == '8':
        print(my_deque.get_rear())