#pragma once

/* 파일로부터 그래프 구성하는 함수 */
bool construct_graph_from_file(Graph* graph, FILE* fp) {
	/*
		INPUT:
			Graph* graph: 그래프 구조체 포인터
			FILE* fp: 파일 포인터

		OUTPUT:
			bool: 그래프 구성 성공 여부

		DESCRIPTION:
			이 함수는 파일로부터 그래프를 구성하는 함수입니다.
			파일 포인터로부터 파일 내용을 읽어서 그래프에 노드와 엣지를 추가합니다.
			hint : insert_node, insert_edge 함수 사용
	*/

	char line[100];		// 파일 한 줄을 저장할 버퍼
	char* token;		// strtok 함수를 위한 포인터
	int v1, v2;			// 노드 번호 (v1: 출발 노드, v2: 도착 노드)
	double cost;		// 엣지의 가중치

	/* ==================== FILL YOUR CODE ==================== */
    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, " ");
        if (token != NULL) {
            v1 = atoi(token);
            token = strtok(NULL, " ");
            if (token != NULL) {
                v2 = atoi(token);
                token = strtok(NULL, " ");
                if (token != NULL) {
                    cost = atof(token);
                    // 노드와 엣지를 그래프에 추가
                    insert_node(graph, v1);
                    insert_node(graph, v2);
                    insert_edge(graph, v1, v2, cost);
                }
            }
        }
    }
	/* ================= YOUR CODE ENDS HERE ================== */
	return true;
}


/* 노드 추가 함수 */
bool insert_node(Graph* graph, int node) {
	/*
		INPUT:
			Graph* graph: 그래프 구조체 포인터
			int node: 추가할 노드 번호

		OUTPUT:
			bool: 노드 추가 성공 여부

		DESCRIPTION:
			이 함수는 그래프에 노드를 추가하는 함수입니다.
			hint: graph->is_node 배열과 graph->n 변수 사용

	*/

	// 노드 번호가 유효한지, 이미 존재하는 노드인지 확인
	if (node < 0 || node >= MAX_NODE || graph->is_node[node] == true)
		return false;

	/* ==================== FILL YOUR CODE ==================== */
	graph -> is_node[node];
	graph -> n++;
	/* ================= YOUR CODE ENDS HERE ================== */
	return true;
}


/* 노드 제거 함수 */
bool delete_node(Graph* graph, int node) {
	/*
		INPUT:
			Graph* graph: 그래프 구조체 포인터
			int node: 제거할 노드 번호

		OUTPUT:
			bool: 노드 제거 성공 여부

		DESCRIPTION:
			이 함수는 그래프에서 노드를 제거하는 함수입니다.
			노드를 제거할 경우, 해당 노드와 연결된 엣지도 모두 제거되어야 합니다.
	*/

	// 노드 번호가 유효한지, 존재하는 노드인지 확인
	if (node < 0 || node >= MAX_NODE || graph->is_node[node] == false)
		return false;

	// 해당 노드와 연결된 엣지 제거를 위한 변수 선언
	GraphPointer curr, prev;

	/* ==================== FILL YOUR CODE ==================== */
	GraphPointer temp;
	curr = graph->adj_list[node];
	while (curr != NULL) {
		temp = curr;
		curr = curr->link;
		free(temp);
	}
	graph->adj_list[node] = NULL;

	// 다른 노드들의 인접 리스트에서 해당 노드로의 엣지 제거
	for (int i = 0; i < MAX_NODE; i++) {
		if (graph->is_node[i]) {
			curr = graph->adj_list[i];
			prev = NULL;
			while (curr != NULL) {
				if (curr->node == node) {
					if (prev == NULL) {
						graph->adj_list[i] = curr->link;
					} else {
						prev->link = curr->link;
					}
					free(curr);
					break;
				}
				prev = curr;
				curr = curr->link;
			}
		}
	}
	/* ================= YOUR CODE ENDS HERE ================== */
	graph->is_node[node] = false;
	graph->n--;
	return true;
}


/* 엣지 추가 함수 */
bool insert_edge(Graph* graph, int v1, int v2, double cost) {
	/*
		INPUT:
			Graph* graph: 그래프 구조체 포인터
			int v1: 출발 노드 번호
			int v2: 도착 노드 번호
			double cost: 엣지의 가중치

		OUTPUT:
			bool: 엣지 추가 성공 여부

		DESCRIPTION:
			이 함수는 그래프에 엣지를 추가하는 함수입니다.
			adj_list로 구현된 배열에 엣지를 추가할 경우,
			오름차순으로 정렬된 상태로 유지해야 합니다.
			hint: insert_ordered_list 함수 사용

	*/

	// 노드 번호가 유효한지, 이미 존재하는 엣지인지 확인
	if (v1 < 0 || v1 >= MAX_NODE ||
		v2 < 0 || v2 >= MAX_NODE ||
		graph->is_node[v1] == false ||
		graph->is_node[v2] == false ||
		graph->adj_mat[v1][v2] != INF)
		return false;
	/* ==================== FILL YOUR CODE ==================== */
	// 새로운 엣지를 생성
    GraphPointer new_edge = (GraphPointer)malloc(sizeof(GraphNode));
    if (!new_edge) return false; // 메모리 할당 실패 시

    new_edge->node = v2;
    new_edge->cost = cost;
    new_edge->link = NULL;

    // adj_list에 오름차순으로 삽입
    insert_ordered_list(&graph->adj_list[v1], new_edge , cost);

    // 인접 행렬에 엣지 추가
    graph->adj_mat[v1][v2] = cost;
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* 엣지 제거 함수 */
bool delete_edge(Graph* graph, int v1, int v2) {
	/*

		INPUT:
			Graph* graph: 그래프 구조체 포인터
			int v1: 출발 노드 번호
			int v2: 도착 노드 번호

		OUTPUT:
			bool: 엣지 제거 성공 여부

		DESCRIPTION:
			이 함수는 그래프에서 엣지를 제거하는 함수입니다.

	*/

	// 노드 번호가 유효한지, 존재하는 엣지인지 확인
	if (v1 < 0 || v1 >= MAX_NODE ||
		v2 < 0 || v2 >= MAX_NODE ||
		graph->is_node[v1] == false ||
		graph->is_node[v2] == false ||
		graph->adj_mat[v1][v2] == INF)
		return false;

	// 해당 엣지를 찾기 위한 변수 선언
	GraphPointer curr, prev;

	/* ==================== FILL YOUR CODE ==================== */
	curr = graph->adj_list[v1];

	prev = NULL;
	while (curr != NULL) {
		if (curr->node == v2) {
			if (prev == NULL) {
				graph->adj_list[v1] = curr->link;
			} else {
				prev->link = curr->link;
			}
			free(curr);
			graph -> adj_mat[v1][v2] = INF;
			return true;
		}
		prev = curr;
		curr = curr -> link;
	}
	/* ================= YOUR CODE ENDS HERE ================== */
	return true;
}


/* DFS - 반복문 버전 */
void DFS_iterative(Graph* graph, int start_node) {
	/*

		INPUT:
			Graph* graph: 그래프 구조체 포인터
			int start_node: DFS 탐색을 시작할 노드 번호

		DESCRIPTION:
			이 함수는 DFS 탐색을 반복문으로 구현한 함수입니다.
			DFS 탐색을 시작할 노드 번호를 입력받아, 해당 노드를 시작으로
			DFS 탐색을 수행합니다.
			DFS 탐색을 수행한 결과는 visited 배열에 저장됩니다.

	*/

	// 방문 여부를 저장하는 배열 및 스택 선언
	bool visited[MAX_NODE] = { false, };
	Stack stack;
	init_stack(&stack);

	/* ==================== FILL YOUR CODE ==================== */
    while (!push(&stack , start_node)) {
        int current_node = pop(&stack);

        if (!visited[current_node]) {
            visited[current_node] = true;
            printf("%d ", current_node); // 방문한 노드 출력

            // 현재 노드의 인접 노드들을 스택에 추가
            GraphPointer adj = graph->adj_list[current_node];
            while (adj != NULL) {
                if (!visited[adj->node]) {
                    push(&stack, adj->node);
                }
                adj = adj->link;
            }
        }
    }
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* DFS - 재귀 버전 */
void DFS_recursive(Graph* graph, int node, bool visited[]) {
	/*

		INPUT:
			Graph* graph: 그래프 구조체 포인터
			int node: DFS 탐색을 시작할 노드 번호
			bool visited[]: 방문 여부를 저장하는 배열

		DESCRIPTION:
			이 함수는 DFS 탐색을 재귀로 구현한 함수입니다.
			DFS 탐색을 시작할 노드 번호를 입력받아, 해당 노드를 시작으로
			DFS 탐색을 수행합니다.
			DFS 탐색을 수행한 결과는 visited 배열에 저장됩니다.

	*/

	/* ==================== FILL YOUR CODE ==================== */
    visited[node] = true;
    printf("%d ", node); // 방문한 노드 출력

    for (GraphPointer adj = graph->adj_list[node]; adj != NULL; adj = adj->link) {
        if (!visited[adj->node]) {
            DFS_recursive(graph, adj->node, visited);
        }
    }
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* BFS */
void BFS(Graph* graph, int start_node) {
	/*
		INPUT:
			Graph* graph: 그래프 구조체 포인터
			int start_node: BFS 탐색을 시작할 노드 번호

		DESCRIPTION:
			이 함수는 BFS 탐색을 구현한 함수입니다.
			BFS 탐색을 시작할 노드 번호를 입력받아, 해당 노드를 시작으로
			BFS 탐색을 수행합니다.
			BFS 탐색을 수행한 결과는 visited 배열에 저장됩니다.

	*/

	// 방문 여부를 저장하는 배열 및 큐 선언
	bool visited[MAX_NODE] = { false, };
	Queue queue;
	init_queue(&queue);

	/* ==================== FILL YOUR CODE ==================== */
// 시작 노드를 큐에 추가하고 방문 표시
    visited[start_node] = true;

    while (!enqueue(&queue , start_node)) {
        int current_node = dequeue(&queue);
        printf("%d ", current_node); // 방문한 노드 출력

        // 현재 노드의 인접 노드들 방문
        GraphPointer adj = graph->adj_list[current_node];
        while (adj != NULL) {
            if (!visited[adj->node]) {
                enqueue(&queue, adj->node);
                visited[adj -> node] = true;
            }
            adj = adj -> link;
        }
    }
	/* ================= YOUR CODE ENDS HERE ================== */
}


/* Dijkstra 함수 */
PathInfo dijkstra(Graph* graph, int start, int end) {
	/*

		INPUT:
			Graph* G: 그래프 구조체 포인터
			int start: 시작 노드 번호
			int end: 도착 노드 번호

		OUTPUT:
			PathInfo: 시작 노드로부터 다른 노드까지의 최단 경로 정보
				path: 최단 경로를 저장하는 배열
				dist: 시작 노드로부터 다른 노드까지의 최단 거리
				A: 다익스트라 알고리즘에서는 사용되지 않음

		DESCRIPTION:
			이 함수는 Dijkstra 알고리즘을 구현한 함수입니다.
			시작 노드 번호를 입력받아, 해당 노드를 시작으로
			Dijkstra 알고리즘을 수행합니다.
			최단 경로 정보는 스택을 이용해 result->path 배열에 저장됩니다.
			만약, 경로가 없는 경우 result->path[0]에 IMPOSSIBLE이 저장되어야 합니다.

	*/

	// 최단 경로 정보를 저장하는 구조체 선언
	PathInfo result;
	for (int i = 0; i < MAX_NODE; i++) {
		for (int j = 0; j < MAX_NODE; j++)
			result.A[i][j] = INF;
		result.dist[i] = INF;
		result.path[i] = IMPOSSIBLE;
	}

	// 다익스트라 알고리즘을 위한 변수 선언
	double dist[MAX_NODE];
	int pred[MAX_NODE];
	bool visited[MAX_NODE] = { false, };

	// 초기화
	for (int i = 0; i < MAX_NODE; i++) {
		visited[i] = false;
		dist[i] = graph->adj_mat[start][i];
		if (dist[i] != INF)
			pred[i] = start;
		else
			pred[i] = -1;
	}
	visited[start] = true;
	dist[start] = 0;
	pred[start] = -1;

	// 경로 저장을 위한 스택 선언
	Stack stack;
	init_stack(&stack);

	/* ==================== FILL YOUR CODE ==================== */
    for (int count = 0; count < MAX_NODE - 1; count++) {
        // 현재 방문하지 않은 노드 중에서 가장 가까운 노드를 선택
        int min_index = -1;
        double min_dist = INF;

        for (int i = 0; i < MAX_NODE; i++) {
            if (!visited[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                min_index = i;
            }
        }

        // 더 이상 갈 수 있는 노드가 없으면 종료
        if (min_index == -1) {
            break;
        }

        // 선택한 노드를 방문 처리
        visited[min_index] = true;

        // 선택한 노드의 인접 노드들에 대해 최단 거리 업데이트
        for (int i = 0; i < MAX_NODE; i++) {
            if (!visited[i] && graph->adj_mat[min_index][i] != INF &&
                dist[min_index] + graph->adj_mat[min_index][i] < dist[i]) {
                dist[i] = dist[min_index] + graph->adj_mat[min_index][i];
                pred[i] = min_index;
            }
        }
    }

    for (int i = 0; i < MAX_NODE; i++) {
        result.dist[i] = dist[i];
    }

    // 최단 경로 추적
    int node = end;
    while (node != -1) {
        push(&stack, node);
        node = pred[node];
    }

    int path_index = 0;
    if (!push(&stack , NULL) && pop(&stack) == start) {
        result.path[path_index++] = start;
        while (!push(&stack , NULL)) {
            result.path[path_index++] = pop(&stack);
        }
    } else {
        result.path[0] = IMPOSSIBLE;
    }
	/* ================= YOUR CODE ENDS HERE ================== */
	return result;
}


/* Bellman-Ford 함수 */
PathInfo bellman_ford(Graph* graph, int start, int end) {
	/*

		INPUT:
			Graph* G: 그래프 구조체 포인터
			int start: 시작 노드 번호
			int end: 도착 노드 번호

		OUTPUT:
			PathInfo: 시작 노드로부터 다른 노드까지의 최단 경로 정보
				path: 최단 경로를 저장하는 배열
				dist: 시작 노드로부터 다른 노드까지의 최단 거리
				A: 벨만-포드 알고리즘에서는 사용되지 않음

		DESCRIPTION:
			이 함수는 Bellman-Ford 알고리즘을 구현한 함수입니다.
			시작 노드 번호를 입력받아, 해당 노드를 시작으로
			Bellman-Ford 알고리즘을 수행합니다.
			최단 경로 정보는 스택을 이용해 result->path 배열에 저장됩니다.
			만약, 경로가 없는 경우 result->path[0]에 IMPOSSIBLE이 저장되어야 합니다.

	*/

	// 최단 경로 정보를 저장하는 구조체 선언
	PathInfo result;
	for (int i = 0; i < MAX_NODE; i++) {
		for (int j = 0; j < MAX_NODE; j++)
			result.A[i][j] = INF;
		result.dist[i] = INF;
		result.path[i] = IMPOSSIBLE;
	}

	// 벨만-포드 알고리즘을 위한 변수 선언
	double dist[MAX_NODE];
	int pred[MAX_NODE];

	// 초기화
	for (int i = 0; i < MAX_NODE; i++) {
		dist[i] = graph->adj_mat[start][i];
		if (dist[i] != INF)
			pred[i] = start;
		else
			pred[i] = -1;
	}
	dist[start] = 0;
	pred[start] = -1;

	// 경로 저장을 위한 스택 선언
	Stack stack;
	init_stack(&stack);

	/* ==================== FILL YOUR CODE ==================== */
    // 그래프의 모든 간선에 대해 반복 (노드 수 - 1)번 수행
    for (int i = 0; i < MAX_NODE - 1; i++) {
        for (int u = 0; u < MAX_NODE; u++) {
            if (dist[u] == INF) continue;
            for (GraphPointer edge = graph->adj_list[u]; edge != NULL; edge = edge -> link) {
                int w = edge->node;
                double weight = edge->cost;
                if (dist[u] + weight < dist[w]) {
                    dist[w] = dist[u] + weight;
                    pred[w] = u;
                }
            }
        }
    }

    // 음수 사이클 체크
    for (int u = 0; u < MAX_NODE; u++) {
        if (dist[u] == INF) continue;
        for (GraphPointer edge = graph->adj_list[u]; edge != NULL; edge = edge->link) {
            int v = edge->node;
            double weight = edge->cost;
            if (dist[u] + weight < dist[v]) {
                // 음수 사이클이 존재함을 나타내기 위해 예외 처리 또는 특정 값 반환
                result.dist[0] = IMPOSSIBLE;
                return result;
            }
        }
    }

    // 결과 저장
    for (int i = 0; i < MAX_NODE; i++) {
        result.dist[i] = dist[i];
    }

    // 최단 경로 추적
    int node = end;
    while (node != -1) {
        push(&stack, node);
        node = pred[node];
    }

    int path_index = 0;
    if (!push(&stack , NULL) && pop(&stack) == start) {
        result.path[path_index++] = start;
        while (!push(&stack , NULL)) {
            result.path[path_index++] = pop(&stack);
        }
    } else {
        result.path[0] = IMPOSSIBLE;
    }
	/* ================= YOUR CODE ENDS HERE ================== */
	return result;
}


/* Floyd-Warshall 함수 */
PathInfo floyd_warshall(Graph* graph) {
	/*

		INPUT:
			Graph* G: 그래프 구조체 포인터

		OUTPUT:
			PathInfo: 시작 노드로부터 다른 노드까지의 최단 경로 정보
				path: 플로이드-워셜 알고리즘에서는 사용되지 않음
				dist: 플로이드-워셜 알고리즘에서는 사용되지 않음
				A: 플로이드-워셜 알고리즘에서 사용되는 2차원 배열

		DESCRIPTION:
			이 함수는 Floyd-Warshall 알고리즘을 구현한 함수입니다.
			그래프를 입력받아, 모든 노드 쌍에 대한 최단 경로를 구합니다.
			최단 경로 정보는 A 배열에 저장됩니다.

	*/

	// 최단 경로 정보를 저장하는 구조체 선언
	PathInfo result;
	for (int i = 0; i < MAX_NODE; i++) {
		for (int j = 0; j < MAX_NODE; j++)
			result.A[i][j] = INF;
		result.dist[i] = INF;
		result.path[i] = IMPOSSIBLE;
	}

	// A 배열 초기화
	double A[MAX_NODE][MAX_NODE];
	for (int i = 0; i < MAX_NODE; i++)
		for (int j = 0; j < MAX_NODE; j++)
			A[i][j] = graph->adj_mat[i][j];
	/* ==================== FILL YOUR CODE ==================== */
    // Floyd-Warshall 알고리즘 수행
    for (int k = 0; k < MAX_NODE; k++) {
        for (int i = 0; i < MAX_NODE; i++) {
            for (int j = 0; j < MAX_NODE; j++) {
                if (A[i][k] != INF && A[k][j] != INF && A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
	/* ================= YOUR CODE ENDS HERE ================== */
	// 결과 저장
	for (int i = 0; i < MAX_NODE; i++)
		for (int j = 0; j < MAX_NODE; j++)
			result.A[i][j] = A[i][j];

	return result;
}