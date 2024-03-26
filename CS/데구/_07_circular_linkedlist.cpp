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
        if(newNode->rlink != NULL)                  >>      newnode의 rlink가 지칭값이 없다면 뒷 node가 없는 경우 이므로 마무리 하면 된다. 
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

/**
 * polynomial (다항식)
 * 각 항마다 계수와 지수로 형성되어 있으므로 계수 ai , 지수 xi로 구성된 순서쌍 <ai , xi>로 순서대로 나열할 수 있다.
 * 희소 다항식 (항과 항간의 차수가 많이 차이나는 경우)
 *  >>  array를 만들어 계수가 0이 아닌 항의 차수와 계수를 저장
*/

/*
//polynomial node 형성
typedef struct PolyNode {
    float coef;                 >>      항의 갯수
    int exp;                    >>      지수의 차수
    struct Node* link;          >>      다음 항의 node
}Node;

typedef struct PolyList {
    Node* head;   
    Node* last;             >>      브루트 포스 알고리즘처럼 다항식의 첫 번째 항부터 마지막 항까지 모두 훑으면서 탐색
}polyList;
*/