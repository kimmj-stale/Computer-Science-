/**
 * circular linked list (원형 리스트)
 * linkedlist의 마지막 값이 head가 가리키는 곳을 가리키는 형태를 갖는다.
*/

/*
linkedlist의 마지막 node가 가리키는 곳이 L -> head와 같다.
*/

/**
 * doubly linked list
 * 양방향 node로 순회할 수 있도록 짜여진 코드 
 * node는 3개의 칸으로 구성 , 1번은 앞 node를 지칭 , 2번은 data 값 , 3번은 뒤 node를 치징
 * 선형 리스트의 경우 head값을 지칭하는 첫 번째 node는 1번이 null, 맨 마지막 node의 3번이 null이다
 * 원형 리스트의 경우 기존 원형 리스트와 동일하다
*/

/**
 * 노드 구조체
*/

/*
//node 형성
typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *llink, *rlink;     >   llink = 왼쪽 node 주소값, rlink = 오른쪽 node 주소값
}listNode;

//head 형성
typedef struct LinkedList {
    listNode* head;
    int length;
}linkedList;
*/

/*
//공백 리스트 작성 (initlist)
linkedList* initList{
    linkedList* L;
    L = (linkedList*)malloc(sizeof(linkedList));
    L->head = NULL;
    L->length = 0;
    return L;
}

//getlength 연산
int getLength(linkedList* L) {
    return L->length;
}
*/

/*
//insertion
void insert(linkedList* L, listNode* pre, element x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;
    if(L->head == NULL) {
        newNode->rlink = NULL;
        newNode->llink = NULL;
        L->head = newNode;
    }
    else if(pre == NULL)
        insertFirst(L, x);
    else {
        newNode->rlink = pre->rlink;
        pre->rlink = newNode;                       >>      앞 node의 rlink에 newnode주소를 저장한다
        newNode->llink = pre;                       >>      앞 node를 지칭한다
        if(newNode->rlink != NULL)                  >>      newnode의 rlink가 지칭값이 없다면 뒷 node가 없는 경우 이므로 
//                                                          마무리 하면 된다. 
            newNode->rlink->llink = newNode;        >>      newnode의 rlink(뒷 node)의 llink 값이 newnode를 지칭한다
    }
    L->length++;
}
*/

/*
//deletion
int delete(linkedList* L, listNode* p) {
    if(L->head == NULL) return FALSE;
    if(p == NULL) return FALSE;
    if(p->llink == NULL)
        L->head = p->rlink;
    else
        p->llink->rlink = p->rlink;
    if(p->rlink != NULL)
        p->rlink->llink = p->llink;
    free(p);
    L->length--;
    return TRUE;
}
*/
