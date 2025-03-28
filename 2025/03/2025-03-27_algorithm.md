# 알고리즘
---
## 좌표만 있을때 최소신장트리 구하기

프림 알고리즘은 한 정점을 기준으로 가장 짧은 거리의 정점을 고른 뒤 그 정점에서 앞의 행위를 반복한다

가중치가 미리 주어지지 않았을 때는 최소값을 갱신해가며 정점을 선택하고 모든 경로를 확인했다면 최소값이었던 정점과의 거리를 다시 계산해서 거리를 확정한다

여기서 필요한 것은 방문 배열, 좌표 배열, 최소거리 배열

다음과 같이 작성할 수 있다

```c++
// 최대값
const double INF = INFINITY;

// main
// 방문배열
vector<bool> visited(N, false);
// 최소거리 배열
vector<double> minDist(N, INF);
// 좌표 배열
vector<double> posX(N), posY(N);

// 정점 순회
// 0번 정점부터 시작
minDis[0] = 0;
for (int i = 0; i < N; i++) {
    int target = -1;
    double minCost = INF;
    for (int j = 0; j < N; j++) {
        // 방문하지 않은 정점이면서 해당 정점의 최소 거리가 현재 최소 거리보다 작으면 업데이트
        if (!visited[j] && minDist[j] < minCost) {
            minCost = minDist[j];
            target = j;
        }
    }
    // target 정점으로 확정
    // 이 시점에 비용을 추가하면 됨
    visited[target] = true;
    result += minCost;
    
    // target 정점부터 방문하지 않은 다른 점과의 거리를 계산하여 최소 거리를 업데이트함
    for (int v = 0; v < N; v++) {
        if (!visited[v]) {
            // 피타고라스의 정리 : a^2 + b^2 = c^2
            double dx = posX[target] - posX[v];
            double dy = posY[target] - posY[v];
            double cost = sqrt(dx * dx + dy * dy);
            // 기존보다 더 짧은 거리면 업데이트
            if (cost < minDist[v]) {
                minDist[v] = cost;
        }
    }
}
```

## 위상정렬

위상정렬은 순서가 있는 작업이 있을 때 순서를 결정해주는 알고리즘이다

예를들어 A, B, C, D 작업이 있고, D 작업을 하기 위해서는 B, C 작업을 완료해야 하고 B, C 작업을 하기 위해서는 A 작업을 완료해야 한다고 할 때, 작업을 전부 완료하기 위해서는 A-B-C-D 혹은 A-C-B-D 순서로 작업을 해야 하는 것

위상정렬을 위해 필요한 것들은 다음과 같음

진입차수 배열, (큐 or 스택 or 힙), 그래프 배열

위상정렬은 설계방식에 따라 출력 순서가 달라질 수 있다

또한 사이클이 존재하거나 진입차수가 0인 정점이 존재하지 않는다면 위상정렬은 불가능함

작동 방식은 다음과 같은 순서로 이루어짐

1. 진입차수가 0인 a정점을 가져옴

2. a정점과 연결된 간선을 제거 -> 진입차수 감소시킴

3. 1과 2를 반복

우선순위 큐를 이용한 위상정렬 코드 예시

```c++
// main
// 우선순위 큐 
priority_queue<int, vector<int>, greater<int>> pq;
// 그래프 배열
vector<vector<int>> graph(N + 1, vector<int>());
// 진입차수 배열
vector<int> degree(N + 1, 0);

// 간선 입력
while (M--) {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    degree[b]++;
}
// 진입차수가 0인 정점을 큐에 넣음
for (register int i = 1; i <= N; i++) {
    if (degree[i] == 0) {
        pq.push(i);
    }
}
// 큐가 빌때까지 반복
while (!pq.empty()) {
    int u = pq.top(); pq.pop();
    printf("%d ", u);
    // 연결되어 있는 간선 제거
    for (auto nxt : graph[u]) {
        degree[nxt]--;
        // 진입차수가 0이라면 큐에 넣음
        if (degree[nxt] == 0) {
            pq.push(nxt);
        }
    }
}
```

## 크루스칼 vs 프림

크루스칼은 간선을, 프림은 정점을 기준으로 경로를 찾는다

장단점이 있는데 알고리즘 문제 풀이에서는 어떤 것이 빠를지 빠르게 판단하는게 중요함

가장 빠르게 판단하는 방법은 다음과 같음

좌표만 주어진다 -> 프림

그 외의 경우 -> 크루스칼

그 외의 경우에서 좀더 자세히 나눠보자면..

주어지는 간선의 개수가 정점 개수의 제곱이라면 프림이 더 빠를 것이다

예를들어 정점이 100개, 간선이 10000개라면 프림이 더 빠른 것인데 문제는 보통 저렇게 안나오니까 좌표만 주어지는 게 아니면 웬만해서는 크루스칼로 풀면 된다
