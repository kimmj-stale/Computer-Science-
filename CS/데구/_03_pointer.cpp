/**
 * 포인터
 * 자료가 저장된 장소의 주솟값을 표현하는 방법
 * 자룟값이 저장된 메모리 공간을 indexing 하는 방법
*/
/*
모든 변숫값은 임의의 주소값을 가지며 임의의 메모리 할당 공간에 저장된다.
*(asterisk) 는 곱셈 , 포인터로 사용된다.
*/

/*자료값 포인터
#include <iostream>
using namespace std;
int main() {
    int a = 5;
    int* ptr;

    ptr = &a;
    cout << ptr;            -> ptr값은 주소값 0x16da9f32c 에 저장
    cout << *ptr;           -> *ptr값은 포인터에 포인터를 한 것이므로 a 값을 호출
}
*/

/*배열 포인터
#include <iostream>
using namespace std;
int main() {
    char arr[6] = {"hello"};
    char* ptr;
    ptr = &arr[0];

    cout << ptr;
    cout << *ptr;
}
*/
