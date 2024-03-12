/**
 * 00. 배열
 * stack과 memory 구조를 잘 알고 있다면 array의 구동 방식을 알기는 쉽다.
 * list는 순서를 가지는 자료형의 모임
 * set은 순서가 없이 모인 자료형들의 집합을 말한다.
*/

/*
list의 기능들
• insertFirst(list, item) : 맨 앞에 요소(item) 삽입
• insertLast(list, item) : 맨 끝에 요소(item) 삽입
• Insert(list, pos, item) : pos 위치에 요소(item) 삽입
• delete(list, pos) : pos 위치의 요소(item) 삭제
• clear(list) : 모든 요소 삭제
• replace(list, pos, item) : pos 위치의 요소를 item으로 교체
• isList(list, item) : item이 리스트에 있는지 검사
• getItem(list, pos) : pos 위치의 요소를 반환
• getLength(list) : 리스트의 길이(항목의 개수)를 구함
• isEmpty(list) : 리스트가 비었는지 검사
• isFull(list) : 리스트가 꽉 찼는지 검사
• display(list) : 리스트의 모든 요소를 표시
*/

/**
 * list elements array
 * 리스트의 elements가 나가거나 들어오면서 다른 elements들의 물리적인 위치가 달라진다.
 * 일반적인 array의 경우 뒤에서 부터 elements가 움직여야 한다.
 * 1 2 3 4 5 7 8 9 - > 6 삽입
 * 1 2 3 4 5 6 7 8 9 - > 9부터 이동하면서 7까지 이동한다.
 * 1 2 3 .... k-1 k+1 .... n-1 n -> k삽입
 * 1 2 3 ... k .... n -> elements들의 이동 횟수는 (n - k + 1)번이다.
 * 삭제 메커니즘 역시 삭제된 elements 바로 뒤의 숫자부터 이동한다.이 때 (n - k)번 이동한다.
*/

/**
 * 리스트 구조체(list struct)
 * 여러 자료형들의 집합을 구조체(structure)라 한다.
*/

/*
#include <iostream>
using namespace std;
int main() {
    typedef int element;
    typedef struct
    {
        int list[10];
        int length;
    }ArrayListType;         ->        struct의 지칭명을 만들어 추후에 호출이 쉽도록 해준다.
}
*/

/*리스트 초기화
void init(ArrayListType* L){
    L->length = 0;
}
*/

/*isEmpty 연산
int isEmpty(ArrayListType* L){
    return L->length == 0;
}   
*/

/*isFull 연산
int isFull(ArrayListType* L){
    return L->length == MAX_SIZE;
}
*/

/*insert 연산
void insert(ArrayListType *L, int pos, element item){
    int i;
    if( isFull(L) ) error(“List is Full!”)  -> 배열이 포화상태인지 검사
    else if( (pos < 0) || (pos > L->length) ) error(“Index Error”)  -> 삽입 부분이 올바른지 검사
    else{
        for( i=(L->length-1); i>=pos; i--)
        {
            L->list[i+1] = L->list[i];      ->  빈 자리 생성
        }
        L->list[pos] = item;
        L->length++;        ->  삽입 리스트의 길이 증가
    }
}
*/

/*delete 연산
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