/**
 * Circular queue
 * 논리적인 배열의 처음과 끝이 연결되어 연속적인 queue
 * front에서 rear로 이동할 때 mod 연산자(%)를 사용한다.
 * 공백상태 / 포화상태 표현을 위해 항상 한 자리는 빈채로 남겨둔다

 *                        삽입 위치                              삭제 위치
 *  일반 큐 =>          rear = rear + 1                     front = front + 1
    원형 큐 =>   rear = (rear + 1) mod MAX_SIZE     front = (front + 1) mod MAX_SIZE

 *  공백상태 : front = rear
 *  포화상태 : (rear + 1) mod MAX_SIZE = front
 * //포화 상태에서 rear이 7인 경우 , (7 + 1) % 8 = 0이므로 포화상태를 나타낼 수 있다
*/

/*
//Circular Queue 구조체
typedef int element;
typedef struct CircularQueue {
    element queue[MAX_SIZE];
    int front, rear;
}Queue;

//Queue Creat 연산
Queue* create(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = 0;                               //  값 표현을 위한 front , rear을 생성
    Q->rear = 0;
    return Q;
}

//isFull 연산
int isFull(Queue* Q){
    return (Q->rear+1)%MAX_SIZE == Q->front;
}

//isEmpty 연산
int isEmpty(Queue* Q){
    //front == rear인 경우 비어있음을 나타내기 때문
    return Q->front == Q->rear;
}
*/

/*
//enqueue 연산
void enqueue(Queue* Q, element x) {
    if( isFull(Q) ) {
        printf(″[ERROR] Queue is FULL!!\n″);
        return;
    }
    else {
        //data가 들어갈 때 rear부터 들어가기 때문에 다음 값을 넣기 위해선 rear + 1을 해줘야 함
        Q->rear = (Q->rear+1) % MAX_SIZE;
        Q->queue[Q->rear] = x;
    }
}

//dequeue 연산
element dequeue(Queue* Q) {
    if( isEmpty(Q) ) {
        printf(″[ERROR] Queue is EMPTY!!\n″);
        return ERROR;
    }
    else {
        //data가 나갈 때는 front부터 나가기 때문에 front + 1 을 한다. 
        Q->front = (Q->front+1) % MAX_SIZE;
        return Q->queue[Q->front];
    }
}

//peek 연산 - 가장 앞(front)의 값을 반환하는 연산
element peek(Queue* Q) {
    if( isEmpty(Q) ) {
        printf(″[ERROR] Queue is EMPTY!!\n″);
        return ERROR;
    }
    else {
        //가장 앞 0번은 상태 표현을 위해 비어있으므로 front + 1을 반환한다.
        return Q->queue[(Q->front+1) % MAX_SIZE];
    }
}
*/

/**
 * Queue 구현 - 단순 연결 리스트 사용
 * linked list를 이용하여 Queue 구현
 * front와 rear을 별도로 지칭할 수 있는 구조체를 선언
*/

/*
//Queue 구조체 선언
typedef int element;
typedef struct QueueNode {
    element data;
    struct QueueNode* link;
}queueNode;

//Queue의 front / rear 지칭 구조체 선언
typedef struct LinkedQueue {
queueNode *front, *rear;
}Queue;

//creat 연산
Queue* create() {
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

//isEmpty 연산
int isEmpty(Queue* Q){
    return Q->front == NULL;
}

//isFull 연산
int isFull(Queue* Q){
    return 0;   //  linked list로 구현한 경우 queue의 크기 제한이 없으므로 isFull 연산은 항상 거짓이다.
}
*/

/*
//enqueue 연산
void enqueue(Queue* Q, element x) {
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    newNode->data = x;
    newNode->link = NULL;
    if( isEmpty(Q) ) {
        Q-> front = newNode;
        Q->rear = newNode;
    }
    else 
        Q->rear->link = newNode;
    Q->rear = newNode;
}

//dequeue 연산
element dequeue(Queue* Q) {
    queueNode* temp;
    element e;
    if( isEmpty(Q) ){
        printf(″[ERROR] Queue is EMPTY!!\n″);
        return ERROR;
    }
    else {
        temp = Q->front;
        e = temp->data;
        Q->front = temp->link;
        free(temp);

        if( Q->front == NULL) Q->rear = NULL
        return e;
    }
} 

//peek 연산
element peek(Queue* Q) {
    if( isEmpty(Q) ){
        printf(″[ERROR] Queue is EMPTY!!\n″);
        return ERROR;
    }
    else
        return Q->front->data;
}
*/
