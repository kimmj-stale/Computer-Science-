/**
 * linear list 구조체
*/

/*
<linear list 구조체>
typedef int element;
typedef struct {
    //선언할 자료형을 모두 작성
}ArrayList;

<리스트 초기화>
void init(ArrayList *L) {
    L -> length = 0;
}

<isEmpty 연산>
int isEmpty(ArrayList* L) {
    return L -> length == 0;
}

<isFull 연산>
int isFull(ArrayList* L) {
    return L -> length == (max_size 값);
}
*/

/*
<insert 연산>
void insert(ArrayListType *L, int pos, element item){
    int i;
    if( isFull(L) )
        error(“List is Full!”)
    else if( (pos < 0) || (pos > L->length) )
        error(“Index Error”)
    else{
        for( i=(L->length-1); i>=pos; i--)
            L->list[i+1] = L->list[i];
        L->list[pos] = item;
        L->length++;
    }
}
*/

/*
<delete 연산>   
element delete(ArrayListType *L, int pos){
    int i;
    element item;
    if( isEmpty(L) )
        error(“List is Empty!”)
    else if( (pos < 0) || (pos >= L->length) )
        error(“Index Error”)
    else{
        item = L->list[pos];
        for( i=pos; i<L->length-1; i++)
            L->list[i] = L->list[i+1];
        L->length--;
        return item;
    }
}
*/

