/**
 * Priority Queue (우선순위 큐)
 * 자료가 들어간 순서에 상관 없이 우선 순위를 근거로 dequeue 연산이 진행됨
 * 삽입 후에도 주어진 우선 순위 데이터 구조를 유자해야 함

 * array를 사용하거나 linked list , heap을 사용함
    !!array 나 linked list는 우선순위 근거 (입력 순서 X)하므로 비효율적인 방법이다.
 * linked list의 시간 복잡도는 작성에는 O(1) 삭제 모두 O(N)의 시간 복잡도를 가짐
 * heap을 사용하는 경우 작성과 삭제 모두 O(logN)의 시간 복잡도를 가진다.
*/

/**
 * Heap 자료 구조
 * 완전 이진트리 구조로 구현된 자료 구조
 
 * max heap
 * 각 노드의 키 값이 자식 노드의 키 값보다 항상 크거나 같은 완전 이진트리
 
 * min heap
 * 각 노드의 키 값이 자식 노드의 키 값보다 항상 작거나 같은 완전 이진트리
*/

/*
//heap 구현
typedef struct {
    HData heap[MAX_SIZE];
    int numOfData;
}Heap;
*/
