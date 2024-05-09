힙 삽입 연산
void insertHeap(Heap* h, HData x) {
    if(h->numOfData == MAX_SIZE) {
        printf(″ERROR: Heap is FULL!!\n″);
        return;
    }
    int idx = h->numOfData + 1;
    while(idx != 1) {
        if(x > h->heap[getParentIdx(idx)]) {
            h->heap[idx] = h->heap[getParentIdx(idx)];
            idx = getParentIdx(dix);
        }
        else break;
    }
    h->heap[idx] = x;
    h->numOfData++;
}