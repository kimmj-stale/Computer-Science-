/**
 * Graph Traversal(그래프 순회)
 * 하나의 정점에서 시작하여 모든 정점을 한번씩 방문하여 처리하는 연산
*/

/*
//깊이 우선 탐색(Depth - first - search)
- DFS는 stack을 사용한 그래프 순회 방식이다.
정점 방문 - 다음 이동 가능한 경로상의 정점으로 이동 - 이동 불가능 한 경우 최근 이동한 경로상의 정점으로 이동 - 반복
- 시작 정점에서 가까운 정점보다 먼 정점에 먼저 도달할 수도 있다.

//너비 우선 탐색(Breadth - first - search)
- BFS는 queue를 사용한 그래프 순회 방식이다.
정점 방문 - 이동 가능한 주변의 모든 정점에 방문 - 새로 방문한 정점에 인접한 모든 정점에 방문 - 반복 
- 시작 정점에서 가까운 정점이 먼 정점보다 먼저 도달한다.
*/