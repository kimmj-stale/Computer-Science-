/**
 * 이진 탐색 트리 (Binary search Tree)
 * 탐색을 효율적으로 하기 위한 트리

 * 이진 트리 모양으로 서로 다른 고유한 key 값을 갖는다.
 * !! L -> key 값 < V -> key 값 < R -> key 값 !! 의 구조를 갖고 있다.
 * 값을 자체적으로 정렬하고 있기에 탐색에 용이하도록 구현되었음
*/

/*
Binary Search Tree ADT
• BinTree* searchBST(BinTree* bt, BTData x) : 데이터 x 노드 탐색
• void insertBST(BinTree* bt, BTData x) : 데이터 x 저장 (노드 생성과정 포함)
• void deleteBST(BinTree* bt, BTData x) : 데이터 x 노드 삭제
*/

/**
 * 탐색할 키값 x를 찾을 경우
 * - 현재 노드값과 키 값의 크기를 비교해 왼쪽으로 이동 or 오른쪽으로 이동 알고리즘을 구현

 * 현재 노드 값과 키 값이 일치하는 경우 -> 탐색 성공
 * 현재 노드 값보다 키 값이 작은 경우 -> 왼쪽 노드로 이동
 * 현재 노드 값보다 키 값이 큰 경우 -> 오른쪽 노드로 이동 
*/

/*
탐색 연산 구현 (함수 자체 구현)
BinTree* searchBST(BinTree* bt, BTData x) {
    BinTree* p = bt;
    while(p != NULL) {
        if(x == p->key) return p;       //  현재 노드의 값과 일치할 경우 p값을 return
        if(x < p->key) p = p->left;     //  작다면 왼쪽 노드로 이동
        else p = p->right;              //  크다면 오른쪽 노드로 이동
    }
    printf(″ERROR: 찾는 키가 없습니다.\n″);
    return NULL;
}

탐색 연산 구현 (재귀적 구현)
BinTree* searchBST(BinTree* bt, BTData x) {
    BinTree* p = bt;
    if(p == NULL) {
        printf(″ERROR: 찾는 키가 없습니다.\n″);
        return NULL;
    }
    if(x == p->key) return p;
    if(x < p->key) return searchBST(p->left, x);
    else return searchBST(p->right, x);
}

삽입 연산 구현
void insertBST(BinTree* bt, BTData x) {
    BinTree* p = bt;
    BinTree* parent = NULL;

    while(p != NULL) {      //  삽입할 노드 탐색
        if(x == p->key) {           //  노드 값은 중복 없이 고유한 값이어야 하기 때문에
            printf(″ERROR: 이미 같은 키가 있습니다.\n″);
            return;
        }
        parent = p;
        if(x < p->key) p = p->left;
        else p = p->right;
    }
    BinTree* newNode = (BinTree*)malloc(sizeof(BinTree));

    newNode->key = x;       //  삽입할 노드 생성
    newNode->left = NULL;
    newNode->right = NULL;

    if(bt == NULL) bt = newNode;                    //  삽입 위치 확정 후 연결
    if(x < parent->key) parent->left = newNode;
    else parent->right = newNode;
}

삭제 연산 구현
void deleteBST(BinTree* bt, BTData x) {
	// Fill your cod
	BinTree *p, *parent, *child;
	BinTree *succ, *succ_parent;
	
	parent = NULL;
	p = bt;
	
	while((p != NULL) && (p->key) != x) {
		parent = p;
		if(x < p->key) p = p->left;
		else p= p->right;
	} 
	
	if(p == NULL) {
		printf("ERROR: 삭제할 노드가 없습니다.\n");
		return;
	}
	if((p->left == NULL) && (p->right == NULL)) {       //  삭제할 노드의 차수가 0인 경우 (자식 노드가 없는 경우)
		if(parent != NULL) {        //  좌/우의 노드를 비교하여 삭제하면 됨
			if(parent->left == p) parent->left = NULL;
			else parent->right = NULL; 
		}
		else bt = NULL;
	}
	else if((p->left == NULL) || (p->right == NULL)) {	//  삭제할 노드의 차수가 1인 경우
		if(p->left != NULL) child = p->left;
		else child = p->right;
		
		if(parent != NULL) {
			if(parent->left == p) parent->left = child;
			else parent->right = child; 
		}
		else bt = child;
	}
	else {      //  삭제할 노드의 차수가 2인 경우 (일반적으로 차수가 2인 경우가 대부분)
		succ_parent = p;
		succ = p->left;
		while(succ->right != NULL) {        //  오른쪽 subTree에서 가장 작은 값 탐색 (삭제 후 바뀔 가능성이 가장 높은 값)
			succ_parent = succ;
			succ = succ->right;
		} 
		
		if(succ_parent->left == succ) succ_parent->left = succ->left;   //  왼쪽 subTree에서 가장 큰 값 (삭제 후 바뀔 가능성이 가장 높은 값)

        else succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ; 
	}
	free(p);
}
*/

/**
 * general Tree (일반 트리)
 * 각 노드의 자식 노드의 갯수 제한이 없는 트리
*/