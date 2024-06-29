/**
 * Linked list
 * 일반적인 배열(Linear list) 와 달리 순서가 상관 없는 배열 자료형이다.
 * 각 자료형이 연결된 것 처럼 생겼고 이 배열은 다음 자료형이 저장된 공간을 지칭하는 주소값을 포함하고 있다.
 * linked list 에는 node를 갖는다.
 * node는 데이터값을 가지는 공간 + 다음 값을 지칭하는 주소값 공간으로 구성된다.
 * Head = 리스트의 첫번째 노드를 가리키는 변수
*/

/*
 * linked list 사용 함수
- L = 시작 node의 포인터 값
- x = 해당 node의 element 값
• linkedList* initList() : 공백 리스트 생성
• void insertFirst(linkedList* L, element x) : 리스트의 첫 번째 노드로 삽입
• void insertLast(linkedList* L, element x) : 리스트의 마지막 노드로 삽입
• void insert(linkedList* L, listNode* pre, element x) : 리스트 L 중간에 x(data) 노드삽입 (pre: 삽입할 위치의 앞 노드)
• int delete(linkedList* L, listNode* p) : 리스트에서 p 노드 삭제
• listNode* searchNode(linkedList* L, element x) : data로 x가 저장되어 있는 노드를 검색
• int getLength(linkedList* L) : 리스트의 길이(항목의 개수)를 구함
• void displayList(linkedList* L) : 리스트의 모든 요소를 표시
*/


/**
 * linked list struct
*/

/*
typedef struct {
    //받을 자료형들을 모두 작성
};
*/

/**
 * delete && insertion && search
*/

/*
void insertion(linkedlist *L , listnode *pre , element x)
element x를 삽입할 때,
(head = x1의 주소값) - (x1) - (x2의 주소값) - (x2) - (x3의 주소값)- (x3) - (null)
-->
(head = x1의 주소값) - (x1) - (x2의 주소값) - (x2) - (x3의 주소값)- (x3) - (null)
                                    [(x)삽입]
-->
(head = x1의 주소값) - (x1) - [(x의 주소값) -(x)] - (x2의 주소값) - (x2) (x3의 주소값)- (x3) - (null)
head에 넣는 경우 head 의 linkfield를 , last에 넣는 경우 마지막 값의 linkfield가 null인 점을 이용하면 빠르게 찾을 수 있다.
*/

/*
void delete(linkedlist *L , listnode *p)

(head = x1의 주소값) - (x1) - (x2의 주소값) - (x2) - (x3의 주소값) - (x3) - (null)
=> (x2 삭제)
(head = x1의 주소값) - (x1) - (x3의 주소값으로 변경) - [(x2) - (x3의 주소값)] - (x3) - (null)
=> (x2 메모리 해제)
(head = x1의 주소값) - (x1) - (x3의 주소값으로 변경) - (x3) - (null)
*/

/*
listNode *search(linkedlist *L , element x)
tmp = head값을 시작으로 하여 각 element값을 탐색 , 원하는 탐색값이 나온다면 탐색 종료
*/

/**
 * Node 구조체
 * linkedlist를 structure 형식으로 저장하는 법
*/

/*
//head// 
!!값을 저장하고 있음!!
typedef struct LinkedList {
    listNode* head;             ->      리스트 노드의 head 값을 저장 , element의 첫번째 linkfield값을 저장하고 있음
    int length;                 ->      리스트의 길이를 담고 있음
}linkedList;


//element node//
typedef int element;
typedef struct ListNode {
    element data;               ->      리스트 노드의 element
    struct ListNode* link;      ->      리스트 노드의 linkfield
}listNode;
*/

/*
head 생성
//공백 리스트 작성//
linkedlist *initlist {
    linkedlist *L;
    L = (linkedlist*)malloc(sizeof(linkedlist));    ->  메모리 공간 할당
    L -> head = NULL;       ->      head값을 비워둠
    L -> length = 0;        ->      head값이 비었으므로 길이 역시 0
    return L;
}

int getlength(linkedlist *L) {
    return L -> length;
}
*/
