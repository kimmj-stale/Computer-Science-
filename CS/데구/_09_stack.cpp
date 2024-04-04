/**
 * Stack (스택)
 * 스택 자료 구조는 메모리에 아래부터 쌓는 자료 구조이다.
 * a , b , c , d , e , f , ....순으로 쌓아 올렸다면 , 가장 먼저 빠져나가는 자료는 쌓아 넣은 자료 순서의 반대이다.
 * 이를 후입선출이라 한다. 가장 나중에 들어온 자료를 자료 상단(top)이라 한다.
*/

/**
 * pop() & push()
 * pop은 리스트에서 마지막 넣은 자료형을 빼내는 함수
 * push는 리스트의 마지막에 자료형을 넣는 함수
*/

/**
 * stack구현
*/

/*
stack[MAX_SIZE]을 이용
가장 나중에 들어온 자료를 top이라고 하며, top을 초기화 하기 위해 top = -1로 초기화(그래야 다음 들어오는 자료의 위치가 0이 됨)

typedef int element;
typedef struct ArrayStack {
    element stack[MAX_SIZE];
    int top;
}Stack;

//공백 스택 생성
void create(Stack* S){
    S->top = -1;
}
//isFull 연산
int isFull(Stack *S){
    return S->top == MAX_SIZE-1;
}
//isEmpt 연산
int isEmpty(Stack *S){
    return S->top == -1;
}
//push 연산
void push(Stack* S, element x) {
    if( isFull(S) ) {
        printf(″[ERROR] Stack is FULL!!\n″);
        return;
    }
    else {
        S->top += 1;
        S->stack[S->top] = x;
    }
}
//pop 연산
element pop(Stack* S) {
    if( isEmpty(S) ) {
        printf(″[ERROR] Stack is EMPTY!!\n″);
        return ERROR;
    }
    else {
        element e = S->stack[S->top];
        S->top -= 1;
        return e;
    }
}
//peek 연산
element peek(Stack* S) {
    if( isEmpty(S) ) {
        printf(″[ERROR] Stack is EMPTY!!\n″);
        return ERROR;
    }
    else {
        return S->stack[S->top];
    }
}
*/

/**
 * linkedlist를 이용한 stack node
*/

/*
//stack node의 구조체

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode* link;
}stackNode;

//마지막에 추가된 자료

typedef struct LinkedStack {
    stackNode* top;
}Stack;

//creat 연산
Stack* create() {
    Stack* S;
    S = (Stack*)malloc(sizeof(Stack));
    S->top = NULL;
    return S;
}

//isEmpty 연산
int isEmpty(Stack* S){
    return S->top == NULL;
}

//isFull 연산
int isFull(Stack* S){
    return 0;
}

//push 연산
void push(Stack* S, element x) {
    stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
    newNode->data = x;
    newNode->link = S->top;
    S->top = newNode;
}

//pop 연산
element pop(Stack* S) {
    stackNode *temp; element e;
    if( isEmpty(S) ){
        printf(″[ERROR] Stack is EMPTY!!\n″);
        return ERROR;
    } else {
        temp = S->top;
        e = temp->data;
        S->top = temp->link;
        free(temp);
        return e;
    }
}

//peek 연산
element pop(Stack* S) {
    element e;
    if( isEmpty(S) ){
        printf(″[ERROR] Stack is EMPTY!!\n″);
        return ERROR;
    }
    else return S->top->data;
}
*/

/**
 * stack 표기법

 * 중위 표기법
 * 연산자를 피연산자 가운데에 표기하는 방법

 * 전위 표기법
 * 연산자를 피연산자들 앞에 표기하는 방법

 * 후위 표기법
 * 괄호를 사용하지 않는 연산자를 피연산자들 뒤에 표기하는 방법 (컴퓨터에 가장 유리한 표기법)
 * 사용자가 중위 표기법으로 작성하면 컴퓨터가 알아서 후위 표기법으로 전환 후 입력된다.
 * 뒤부터 입력되어(stack) 수가 나오면 연산된다.
*/

/* ex 중위 표기법을 후위 표기법으로 고치는 과정
 A * B – C / D ➔ ((A * B) – (C / D)) -> ((A * B) - (C / D)) ➔ ((A B) * (CD) / ) – ->  AB*CD/–
*/


