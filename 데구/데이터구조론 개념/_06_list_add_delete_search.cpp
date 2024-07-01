/**
 * list append at middle indx
*/

/*
void insert(linkedList* L, listNode* pre, element x){
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));      //   새로운 node의 주소값
    newNode->data = x;
    if(L->head == NULL){        //   head에 넣는 경우
        newNode->link = NULL;   //   head이자 last node이기에 마지막 주소값 영역에는 null을 넣는다.
        L->head = newNode;      //   head값에는 x의 주소를 넣는다.
    }
    else if (pre == NULL) {     //   가장 마지막에 넣는 경우
        newNode->link = L->head;    
        L->head = newNode;
    }
    else{
        newNode->link = pre->link;  //   앞서 지칭하던 주소값을 newnode가 뒤 값을 지칭하는 자리에 넣는다.
        pre->link = newNode;    //   선행하는 node의 주소값을 newnode를 지칭하는 주소값으로 변경한다.
    }
    L->length++;
}
*/

/**
 * list append at first indx
*/

/*
void insertFirst(linkedList* L, element x){
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;
    newNode->link = L->head;
    L->head = newNode;      //   list의 head값에 newnode를 지칭하는 주소값을 넣는다.
}
*/

/**
 * list append at last indx
*/

/*
void inserLastNode(linkedList* L, element x){
    listNode *newNode, *temp;       //   현재 지칭하고 있는 node의 주소값인 temp를 따로 생성한다
    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;
    newNode->link = NULL;
    if(L->head == NULL) L->head = newNode;      //   list의 마지막 값이 head인 경우 (list가 빈 경우)
    else{
        temp = L->head;     >   temp값이 처음부터 (head값) 시작
        while(temp->link != NULL) temp = temp->link;        //   temp값이 head부터 last값까지 넘어감
        //!! 별도로 last값을 지정할 수 없어 따로 찾아야 함 !!//
        temp->link = newNode;
    }
    L->length++;
}
*/

/**
 * list deletion
*/

/*
int delete(linkedList* L, listNode* p){
    listNode* pre;
    if(L->head == NULL) return FALSE;       //   리스트가 공백인 경우
    if(p == NULL) return FALSE;             //   삭제할 리스트가 존재하지 않는 경우
    if(L->head == p) {
        L->head = p->link;                  //   삭제할 노드가 하나만 있는 경우 (삭제할 node가 head인 경우)
        free(p);    />  pointer p 가 가리키는 node를 삭제하는 방법
    }
    else {
        pre = L->head;
        while(pre->link != p) {
            pre = pre->link;
            if(pre == NULL) return FALSE;       //   특정 node 삭제
        }
        pre->link = p->link;
        free(p);
    }
    L->length--;            //   node를 하나 삭제했으므로 길이 - 1
    return TRUE;
}
*/

/**
 * list search
*/

/*
listNode* search(linkedList* L, element x){
    listNode* temp = L->head;   //   node값을 하나씩 증가하면서 변동
    while(temp != NULL) {       //   현재 지칭 주소값이 null(끝값)이 아닌 경우
        if(temp->data == x)     //   현재 지칭 자료값이 특정 자료값 x인 경우 (data 값이 x 인 경우를 찾기)
            return temp;
        else
            temp = temp->link;  //   temp의 data값이 x가 아닌 경우 다음을 지칭하여 넘어감
    }
    return temp;
}
*/

/**
 * displaylist 연산
*/

/*
void displayList(linkedList* L) {
    listNode* p;
    printf(“L=(”);
    p = L->head;
    while(p != NULL){               //   끝값에 도달한 경우 출력 종료
        printf(“%d”, p->data);      //   list p의 모든 요소값을 지칭하기 위해 pointer 사용
        p = p->link;
        if(p != NULL) printf(“,”);  //   끝값(NULL)이 아닌 경우 출력 유지(,) , NULL인 경우 (,) 출력 종료
    }
    printf(“)\n”);
}
*/

