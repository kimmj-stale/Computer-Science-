/**
 * search (탐색)
 * 컴퓨터 내에 있는 데이터를 찾는다
*/

/*  //검색 방식
- 내부 탐색
- 외부 탐색
*/

/**
 * 순차 검색
 * 정렬되어있지 않은 자료를 순차적으로 검색
 * 키 값과 일치하는 값을 찾으면 값을 리턴하고 종료

 * 평균 탐색은 (n + 1) / 2번 , 시간 복잡도는 O(n)이다
*/

/**
 * 색인 순차 탐색
 * 정렬되어있는 자료에 대하여 index table을 추가하여 탐색 효율을 높인 순차 탐색 알고리즘
 * 특정 차이만큼 index table을 구성한 후 키 값이 특정 범위에 존재함을 탐색 후 범위 특정
*/


/* index table 구현
iTable* makeIndexTable(element a[], int size) {
	int i, n;
	n = size / INDEX_SIZE;					// 인덱스 테이블에 들어가는 배열 원소의 간격 계산
	if (size % INDEX_SIZE > 0)  n++;
	for (i = 0; i < INDEX_SIZE; i++) {		// 인덱스 테이블의  채우기
		indexTable[i].index = i * n;
		indexTable[i].key = a[i * n];
	}
	return indexTable;
}
*/

/*  색인 순차 탐색 구현
void indexSearch(iTable indexTable[], element a[], int n, element key) {
	int i, begin, end;
	if (key < a[0] || key > a[n - 1])
		printf("\n찾는 키가 없습니다. 검색 실패! \n");

	// 인덱스 테이블을 검색하여 검색 범위 결정
	for (i = 0; i < INDEX_SIZE; i++){
		if ((indexTable[i].key <= key) && (indexTable[i + 1].key > key)) {
			begin = indexTable[i].index;
			end = indexTable[i + 1].index;
			break;
		}
		if (i == INDEX_SIZE) {
			begin = indexTable[i - 1].index;
			end = n;
		}
	}
	sequentialSearch3(a, begin, end, key);	// 검색 범위에 대한 순차검색 수행
}
*/

/**
 * binary search (이진 탐색)
 * 자료의 가운데에 존재하는 pivot 값을 기준으로 table을 나눈 뒤 다음 검색 위치를 특정 후 탐색을 반복하는 방법
 * iff (key < pivot)? -> 왼쪽 table 탐색 
 * else ? -> 오른쪽 table 탐색
*/

/* 이진 탐색 구현
// 재귀적 구현
int cnt=0;	// 이진 검색의 연산 횟수

void binarySearch(element a[], int begin, int end, element key) {
	int middle;
	cnt++;						// 이진 검색 연산 횟수 1 증가
	if (begin == end) {			// 검색 범위가 한 개인 경우
		if (key == a[begin]) printf("%3d번째에 검색 성공!\n", cnt);
		else printf("%3d번째에 검색 실패! \n", cnt);
		return;
	}

	middle = (begin + end) / 2;  // 검색 범위가 이진 분할되는 기준 위치 설정
	if (key == a[middle])  printf("%3d번째에 검색 성공!\n", cnt);
	else if (key < a[middle] && (middle - 1 >= begin))
		binarySearch(a, begin, middle - 1, key);
	else if (key > a[middle] && (middle + 1 <= end))
		binarySearch(a, middle + 1, end, key);
	else printf("%3d번째에 검색 실패! \n", cnt);
}
*/

/**
 * Binary Search Tree
*/

/*
데구 예제 BST 파일 참조
*/