/**
 * Binary Tree (트리 배열)
 * n개의 노드를 가지는 트리에 대하여 해당 노드의 index를 i라 할 때,
 * 
 * parent[i]
 * leftChhild[i] = 2 * i
 * rightChild[i] = 2 * i + 1
 * 
*/

/*
//struct 구조
typedef int BTData;
typedef struct BinaryTreeNode {
    BTData data;
    struct BinaryTreeNode *left, *right;
}BinTree;           //  부모 노드로 가기가 어려워 struct에 부모 노드로 가는 linkfeild를 추가함
*/

/**
 * 이진 트리의 순회
 * 트리에 있는 모든 노드를 한 번씩만 방문 , 완쪽 서브 트리는 오른쪽보다 항상 먼저 방문함
 * 중앙의 node를 V , 왼쪽의 node를 L , 오른쪽의 node를 R이라 할 때,
 * LVR(중위 순회) , LRV(후위 순회) , VLR(전위 순회) 가 있다. (책마다 LCR , LNR 등으로 다르게 표현된 경우가 있지만 모두 같은 뜻임)
*/

/*
//  LVR(중위 순회)
void inorderTraverse(BinTree* bt) {
    if (bt != NULL) [
        inorderTraverse(bt -> left);
        printf("[%d]" , bt -> data);        //  data값에 도달( =root에 방문)
        inorderTraverse(bt -> right);
    ]
}

//VLR(전위 순회)
void preorderTraverse(BinTree* bt) {
    if (bt != NULL) {
        printf("[%d]" , bt -> data);
        preorderTraverse(bt -> left);
        preorderTraverse(bt -> right);
    }
}

//LRV(후위 순회)
void postorderTraverse(BinTree* bt) {
    if (bt != NULL) {
        postorderTraverse(bt -> left);
        postorderTraverse(bt -> right);
        printf("[%d]" , bt -> data);
    }
}
*/

/**
 * 수식 트리
 * 중위 표기법을 바로 수식 트리로 전환하는 것은 매우 어렵다
 * 중위 -> 후위 -> 수식 트리로 전환하는 과정이 필요하다.
*/

/*
//  createExpTree 구현
BinTree* createExpTree(char exp[]){
    Stack* S = createStack();   //  계산에 사용할 stack 생성
    BinTree* bNode;
    int expLen = strlen(exp);
    for(int i=0; i<expLen; i++) {
        bNode = createBT();
        if(isdigit(exp[i]))
            setData(bNode, exp[i]-′0′);     //  ASCII로 인식되기 때문에 - '0'(48)을 해줘야 원래 숫자로 변환된다.
        else {
            makeRSubtree(bNode, pop(S));
            makeLSubtree(bNode, pop(S));
            setData(bNode, exp[i]);
        }
        push(S, bNode);
    }
    return pop(S);
}

//  수식 트리로 부터의 계산
int evalExpTree(BinTree* bt){
    int op1, op2;

    op1 = getData(getLSubtree(bt));
    op2 = getData(getRSubtree(bt));     //  좌 / 우 subTree의 data값을 불러온다

    switch(getData(bt)) {               //  사칙연산을 switch - case 문으로 구현
        case ′+′:
            return op1 + op2;
        case ′-′:
            return op1 - op2;
        case ′*′:
            return op1 * op2;
        case ′/′:
            return op1 / op2;
    }
    return 0;
}
*/