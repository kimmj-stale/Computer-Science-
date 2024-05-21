/**
 * 정렬(sort)
순서 없이 배열된 자료를 작은 것부터 큰 것 순서인 오름차순(Ascending)이나 큰 것부터 작은 것 순서인 내림차순(Descending)으로 재배열하는 것
키(Key) - 자료를 정렬하는데 사용하는 기준이 되는 특정 값
*/

/**
 * 선택 정렬(selection sort)
전체 원소들 중에서 기준 위치에 맞는 원소를 선택하여 자리를 교환하는 방식으로 정렬

- 수행 방법
전체 원소 중에서 가장 작은 원소를 찾아 첫 번째 원소와 자리를 교환
두 번째로 작은 원소를 찾아 선택하여 두 번째 원소와 자리를 교환
세 번째로 작은 원소를 찾아 선택하여 세 번째 원소와 자리를 교환
이 과정을 반복하면서 정렬을 완성
*/

/*
// 선택 정렬하는 연산
void SelectionSort(int a[], int size) {
    int i, j, t, min;
    element temp;
    printf("\n정렬할 원소 : ");
    for (t = 0; t<size; t++) printf("%d ", a[t]); // 정렬 전의 원소 출력
        printf("\n\n<<<<<<<<<< 선택 정렬 수행 >>>>>>>>>>\n");
    for (i = 0; i<size - 1; i++) {
        min = i;
        for (j = i + 1; j<size; j++) {
            if (a[j]<a[min]) min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        printf("\n%d단계 : ", i + 1);
        for (t = 0; t<size; t++) printf("%d ", a[t]);
    }
}
*/

/**
 * Bubble sort(버블 정렬)
인접한 두 개의 원소를 비교하여 자리를 교환하는 방식
- 첫 번째 원소부터 마지막 원소까지 반복하여 한 단계가 끝나면 가장 큰 원소가 마지막 자리로 정렬
- 첫 번째 원소부터 인접한 원소끼리 계속 자리를 교환하면서 맨 마지막 자리로 이동
- 물 속에서 물 위로 올라오는 물방울 모양과 같다고 하여 버블(bubble) 정렬이라 함.
*/

/*
최선의 경우 : 자료가 이미 정렬되어있는 경우
비교횟수 : i번째 원소를 (n-i)번 비교하므로, 𝑛(𝑛−1) / 2번
자리교환횟수 : 자리교환이 발생하지 않음

최악의 경우 : 자료가 역순으로 정렬되어있는 경우
비교횟수 : i번째 원소를 (n-i)번 비교하므로, 𝑛(𝑛−1) / 2번
자리교환횟수 : i번째 원소를 (n-i)번 교환하므로, 𝑛(𝑛−1) / 2번

최선의 경우와 최악의 경우에 대한 평균 시간 복잡도를 빅-오 Big Oh 표기법 으로 나타내면 O(n^2)이 됨
*/

/*
// Bubble Sort(버블 정렬)
void bubbleSort(element a[], int size) {
    int i, j, t;
    element temp;
    printf("\n정렬할 원소 : ");
    for (t = 0; t<size; t++) printf("%d ", a[t]);
        printf("\n<<<<<<<<<< 버블 정렬 수행 >>>>>>>>>>");
    for (i = size - 1; i>0; i--) {
        printf("\n %d단계>>", size - i);
        for (j = 0; j < i; j++) {
            if (a[j]>a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
            printf("\n\t");
            for (t = 0; t<size; t++) printf("%3d ", a[t]);
        }
    }
}
*/

/**
 * 퀵 정렬(quick sort)
정렬할 전체 원소에 대해서 정렬을 수행하지 않고,기준값을 중심으로 왼쪽 부분 집합과 오른쪽 부분 집합으로 분할하여 정렬하는 방법
왼쪽 부분 집합에는 기준 값보다 작은 원소들을 이동시키고, 오른쪽 부분집합에는 기준 값보다 큰 원소들을 이동시킴

기준 값 : 피봇(pivot)
− 일반적으로 전체 원소 중에서 가운데에 위치한 원소를 선택
*/

/*
Quick sort 연산 시간
- 최선의 경우
피봇에 의해서 원소들이 왼쪽 부분 집합과 오른쪽 부분 집합으로 정확히 n/2개씩 2등분이 되는 경우가 반복되어 수행 단계 수가 최소가 되는 경우

- 최악의 경우
피봇에 의해 원소들을 분할하였을 때 한개와 n-1개로 한쪽으로 치우쳐 분할되는 경우가 반복되어 수행 단계 수가 최대가 되는 경우
최악의 경우 시간 복잡도가 O(N^2)까지 커지므로 이상적인 알고리즘은 아니다

- 평균 시간 복잡도 : O(nlog2n)
같은 시간 복잡도를 가지는 다른 정렬 방법에 비해서 자리 교환 횟수를 줄임으로써 더 빨리 실행되어 실행 시간 성능이 좋은 정렬 방법 
평균 시간 복잡도가 O(nlogn)인 merge sort가 더 좋은 알고리즘이다.
*/

/*
//  Quick Sort(퀵 정렬)
void quickSort(element a[], int begin, int end) {
    int p;
    if (begin<end) {
        p = partition(a, begin, end);
        // 피봇의 위치에 의해 분할 위치 결정
        quickSort(a, begin, p - 1);
        // 피봇의 왼쪽 부분집합에 대해 퀵 정렬을 재귀호출
        quickSort(a, p + 1, end);
        // 피봇의 오른쪽 부분집합에 대해 퀵 정렬을 재귀호출
    }
}

// 주어진 부분집합 안에서 피봇의 위치를 확정하여 분할 위치를 정하는 연산
int partition(element a[], int begin, int end) {
    int pivot, L, R, t;
    element temp;
    L = begin;
    R = end;

    pivot = (int)((begin + end) / 2.0); // 중간에 위치한 원소를 피봇 원소로 선택
    printf("\n [%d단계 : pivot=%d ] \n", ++i, a[pivot]);

    while (L<R) {
        while ((a[L]<a[pivot]) && (L<R)) L++;
        while ((a[R] >= a[pivot]) && (L<R)) R--;
        if (L<R) { // L과 R 원소의 자리 교환
            temp = a[L];
            a[L] = a[R];
            a[R] = temp;
            if (L == pivot) // L이 피봇인 경우,
                pivot = R; // 변경된 피봇의 위치(R)를 저장
            } // if(L<R)
        }
        // (L=R)이 된 경우, 더 이상 진행할 수 없으므로 R 원소와 피봇 원소의 자리를 교환하여 마무리
    temp = a[pivot];
    a[pivot] = a[R];
    a[R] = temp;
    for (t = 0; t<size; t++) printf(" %d", a[t]); // 현재의 정렬 상태 출력
    printf("\n");
    return R; // 정렬되어 확정된 피봇의 위치 반환
}
*/