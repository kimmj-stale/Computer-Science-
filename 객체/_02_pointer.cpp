/**
 * 포인터
 * 실행중인 메모리의 주소를 나타내는 변수(값)
*/

/*ex
#include <iostream>
using namespace std;
int main() {
    int a = 3;
    int *ptr;               ->          포인터로 받을 정수형 변수를 생성

    ptr = &a;                   ->      !!a가 존재하는 메모리의 주소를 ptr로 받음!!
    cout << ptr << '\n';        ->      포인터로 받은 자료 a의 주소
    cout << *ptr << '\n';       ->      포인터로 받은 주소에 존재하는 자료형 a
}
*/

/*ex2
#include <iostream>
using namespace std;
int main() {
    int a = 3;
    char b = '!';
    string c = "hello";

    int *ptr1 , *ptr2 , *ptr3;
    ptr1 = &a;
    ptr2 = &b;
    ptr3 = &c;
    cout << ptr1 << '\n';
    cout << ptr2 << '\n';           ->      char값은 char로 포인터를 받아야 함
    cout << ptr3 << '\n';           ->      string도 마찬가지
}
*/

/**
 * 포인터로 배열 접근
 * 배열의 각 칸에도 메모리 할당값이 존재, 포인터로 이를 지칭할 수 있음
 * 
*/

/*
#include <iostream>
using namespace std;
int main() {
    int n[10]= {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
    int *a = n;

    cout << *a << ' ' << a << '\n';     ->  별도로 지정하지 않는다면 n[0]을 나타냄
    cout << *n << ' ' << n << '\n';     ->  위와 동일한 지정값을 가짐
    cout << *(a + 5) << ' ' << a + 5 << '\n';   ->  n[0 + 5]를 나타냄
    cout << *(n + 5) << ' ' << n + 5 << '\n';   ->  위와 동일한 지정값을 가짐
}
*/

/*ex
#include <iostream>
using namespace std;
    bool equalArray(int* p, int* q, int size); // 함수의 원형 선언
        int main() {
        int a[] = {1,2,3,4,5};
        int b[] = {1,2,3,4,5};
        if(equalArray(a, b, 5)) cout << "arrays equal" << "\n";
        else cout << "arrays not equal" << "\n";
    }
    bool equalArray(int* p, int* q, int size) {
        int i;
    for(i=0; i<size; i++) {
        if(*p != *q) return false;
    p++; // p는 배열의 다음 원소를 가리킴
    q++; // q도 배열의 다음 원소를 가리킴
    }
    return true;
} 
*/
