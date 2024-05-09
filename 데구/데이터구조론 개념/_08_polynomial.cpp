/**
 * polynomial (다항식)
 * 각 항마다 계수와 지수로 형성되어 있으므로 계수 ai , 지수 xi로 구성된 순서쌍 <ai , xi>로 순서대로 나열할 수 있다.
 * 희소 다항식 (항과 항간의 차수가 많이 차이나는 경우)
 *  >>  array를 만들어 계수가 0이 아닌 항의 차수와 계수를 저장
*/


/* operators
• Stack* create() : 공백 스택 생성 연산
• int isFull(Stack* S) : 스택이 가득찼는지 검사하는 연산
• int isEmpty(Statck* S) : 스택이 비어있는지 검사하는 연산
• void push(Stack* S, element x) : 스택에 요소 추가
• element pop(Stack* S) : 스택에서 마지막에 저장된 요소 삭제 및 반환
• element peek(Stack* S) : 스택에서 마지막에 저장된 요소 반환. 삭제 X
*/

/*
//polynomial node 형성
typedef struct PolyNode {
    float coef;                 >>      항의 계수
    int exp;                    >>      지수의 차수
    struct Node* link;          >>      다음 항의 node
}Node;

typedef struct PolyList {
    Node* head;   
    Node* last;             >>      브루트 포스 알고리즘처럼 다항식의 첫 번째 항부터 마지막 항까지 모두 훑으면서 탐색
}polyList;
*/