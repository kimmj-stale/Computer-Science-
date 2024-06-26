/**
 * Spanning Tree(신장 트리)
 * 정점이 n개인 트리 G에 대하여 간선의 갯수가 n - 1개인 트리
*/

/*
//Spanning Tree 의 특징
- 모든 정점이 포함되어야 한다.
- 모든 정점이 연결되어있어야 한다.
- 사이클을 포함하지 않아야 함 (시작점과 도착점이 연결됨 = 사이클)
*/

/**
 * 최소 비용 신장 트리
 * 무방향 가중치 그래프에서 최소 비용을 갖는 신장트리
*/

/* Kruskal algorithm I
// 가중치가 높은 간선을 제거하면서 최소 비용 신장 트리를 만드는 방법 
(1) 그래프 G의 모든 간선을 가중치에 따라 내림차순으로 정렬
(2) 그래프 G에서 가중치가 가장 높은 간선 제거 
(정점을 그래프에서 분리시키는 간선은 제거할 수 없으므로 이런 경우 그 다음으로 가중치가 높은 간선 제거)
(3) 그래프 G에 간선이 n-1개만 남을 때까지 (2) 반복
(4) 그래프에 간선이 n-1개만 남으면 최소 비용 신장 트리 완성
*/

/* Kruskal algofithm II
// 가중치가 낮은 간선을 삽입하면서 최소 비용 신장 트리를 만드는 방법
(1) 그래프 G의 모든 간선을 가중치에 따라 오름차순으로 정리
(2) 그래프 G에서 가중치가 가장 낮은 간선 삽입
(사이클을 형성하는 간선은 삽입할 수 없음. 이런 경우 그 다음으로 가중치가 낮은 간선 삽입)
(3) 그래프 G에 간선이 n-1개가 삽입될 때까지 (2) 반복
(4) 그래프에 간선이 n-1개가 되면 최소 비용 신장 트리 완성

*/

/* Prim algorithm
// 간선을 정렬하지 않고 하나의 정점에서 시작하여 트리를 확장해나감 (Prim algorithm)
(1) 그래프 G에서 시작 정점 선택
(2) 선택한 정점에 부속된 모든 간선 중에서 가중치가 가장 낮은 간선을 연결하여 트리 확장
(3) 이전에 선택한 정점과 새로 확장된 정점에 부속된 간선 중에서 가중치가 가장 낮은 간선 삽입
(단, 사이클을 형성하는 간선은 삽입할 수 없으므로 이런 경우에는 그 다음으로 가중치가 낮은 간선 선택)
(4) 그래프 G에 간선이 n-1개가 삽입될 때까지 (3) 반복
(5) 그래프 G의 간선이 n-1개가 되면 최소 비용 신장 트리 완성
*/

/**
 * Shortest Path Algorithm(최단 경로 알고리즘)
 * 최단 경로를 구하는 알고리즘
 * 최단 경로를 구하는 과정에서 경로의 가중치를 저장
*/

/*
//Dijkstra Algorithm
- 최단 거리를 구하는 알고리즘 중 가장 많이 사용됨
- 무방향 / 방향 그래프 모두에 사용됨
v ----------> u ------------> w
- v에서 w로 가는 경로 dist[w]는 
dist[w] = dist[u] + cost[u][w]
dist[w]로 축약하여 표현하면서 반복 , 최단 거리를 구한다.
*/

/*
ex - 
A 에서 C까지 가는 dijkstra 알고리즘을 구현할 때,
A -> C vs A -> B -> C 두 가지 경로 중 가중치 합의 최솟값을 선택
즉, !! dist[C] = min(dist[C] , dist[B] + cost[B][C]) !!
이 때, 이전 direction의 값을 pred data table에 저장하여 판단 , 최단 거리 dist의 값을 지속적으로 갱신
위에서 구한 경로들로만 이루어진 경로들로 map을 구성
*/

