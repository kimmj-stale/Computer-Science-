/**
 * Priority Queue (우선순위 큐)
 * 자료가 들어간 순서에 상관 없이 우선 순위를 근거로 dequeue 연산이 진행됨
 * 삽입 후에도 주어진 우선 순위 데이터 구조를 유자해야 함

 * array를 사용하거나 linked list , heap을 사용함
    !!array 나 linked list는 우선순위 근거 (입력 순서 X)하므로 비효율적인 방법이다.
 * linked list의 시간 복잡도는 작성에는 O(1) 삭제 모두 O(N)의 시간 복잡도를 가짐
 * heap을 사용하는 경우 작성과 삭제 모두 O(logN)을 가진다.
*/

/**
 * Heap 자료 구조
 * 완전 이진트리 구조로 구현된 자료 구조
 * 
 * max heap
 * 각 노드의 키 값이 자식 노드의 키 값보다 항상 크거나 같은 완전 이진트리
 * 키 값이 큰 노드가 가장 우선 순위가 높음

 * min heap
 * 각 노드의 키 값이 자식 노드의 키 값보다 항상 작거나 같은 완전 이진트리
 * 키 값이 작은 노드가 가장 우선 순위가 높음
*/

/*
//heap 구현
typedef struct {
    HData heap[MAX_SIZE];
    int numOfData;
}Heap;
*/

/*
힙 삽입 연산 구현
void insertHeap(Heap* h, HData x) {
    if(h->numOfData == MAX_SIZE) {
        printf(″ERROR: Heap is FULL!!\n″);
        return;
    }
    int idx = h->numOfData + 1;     //  마지막 노드의 값 + 1에 노드 생성 , 항상 마지막에 들어온 값을 마지막 노드에 투입
    while(idx != 1) {
        if(x > h->heap[getParentIdx(idx)]) {
            h->heap[idx] = h->heap[getParentIdx(idx)];      
            idx = getParentIdx(dix);            //  부모 노드와 교환 , while 문으로 계속 반복
        }
        else break;
    }
    h->heap[idx] = x;
    h->numOfData++;
}
*/

/*
힙 삭제 연산 구현
HData deleteHeap(Heap* h) {
    if(isEmpty(h)) {
        printf(″ERROR: Heap is EMPTY!!\n″);
        return 0;
    }
    HData item = h->heap[1];
    HData lastVal = h->heap[h->numOfData];

    int parentIdx = 1;
    int childIdx = 2;

    항상 먼저 삭제되는 노드는 root노드이다.
    while(childIdx <= h->numOfData) {
        if((childIdx < h->numOfData) && (h->heap[childIdx] < h->heap[childIdx+1]))
            childIdx++;     //  다음 값이 tree의 배열 규칙에 만족한다면 다음 노드로 넘어감
        if(lastVal >= h->heap[childIdx]) break;     //  규칙에 만족하는 마지막 경우에 도달하면 while문 종료
        else {
            h->heap[parentIdx] = h->heap[childIdx];
            parentIdx = childIdx;
            childIdx = childIdx * 2;        //  규칙에 만족하지 않는 값이 나온다면 부모 노드와 자식 노드 교체
        }
    }
    h->heap[parentIdx] = lastVal;
    h->numOfData--;
    return item;
}
*/
