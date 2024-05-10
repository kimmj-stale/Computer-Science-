/**
 * 배열
 * 동일한 datatype의 자료형을 하나의 단위로 나타내고 다루기 위해 연결된 메모리
 * (자료 유형) (배열 이름)[(배열 크기)] = {요소};
 * 각자 자료형을 담는 칸마다 메모리가 할당되어 있음, 적은 메모리 사용을 위해 배열 지정할 때 따로 요소 지정을 해주는 편이 좋음
*/

/*ex
#include <iostream>
using namespace std;
int main() {
    int arr[] = {0 , 1 , 2 , 3 , 4};            -> 정수 자료형의 요소들이 들어가는 배열
    double d_arr[10];                           -> 정해지지 않은 10개의 실수가 들어가는 배열
}
*/

/**
 * 2차원 배열
 * 두가지 자료형을 하나의 단위로 나타내기 위해 연결된 메모리
 * (자료 유형) (배열 이름)[(1번째 배열 크기)][(2번째 배열 크기)];
*/

/*ex
#include <iostream>
using namespace std;
int main() {
    int arr[10][10];

    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 1; j <= 10; j++) {
            arr[i][j] = j * 2;
        }
    }
}
*/

/**
 * 함수
 * 함수를 별도로 지정하여 원하는 동작을 하는 내장함수가 아닌 함수를 지정할 수 있다.
 * 
 * (자료형) (함수명)((함수에 사용될 매개변수)) {
 * //////////////동작할 프로세스////////////////
 * return (반환할 값);
 * }
*/

/*ex
#include <iostream>
using namespace std;
int add(int a , int b) {
    int sum = a + b;
    return sum;
}

int main() {
    int x , y;
    cin >> x >> y;
    cout << add(x , y) << '\n';
}
*/

/**
 * 함수 호출 주의 사항
 * 별도로 지정할 함수는 항상 main 함수보다 위에 존재해야 한다.
 * 리턴값이 없는 경우 자료형 값에 void를 사용한다.
 * 지정된 자료형 이외의 자료형을 사용하면 안된다.
*/

/*
#include <iostream>
using namespace std;
void adder(int a , int b) {     ->      return값을 발생하지 않으므로 void를 사용한다.
    int sum = a + b;
    cout << sum << '\n';
}
int main() {
    char x , y;
    cin >> x >> y;
    adder(x , y);               ->      다른 자료형의 요소를 넣으면 오류 발생
}
*/

/**
 * 함수 원형 , 함수 프로토타입
 * 변수 선언이나 함수 형식만 선언한 것을 함수 프로토타입이라 한다.
*/

/*ex
#include <iostream>
using namespace std;
int def_num(int a = 1 , int b = 5)      ->      별도 동작을 요청하지 않고 자료형만 지정시킨다.
int main() {
    cout << a << b;
}
*/

/*ex2
#include <iostream>
using namespace std;
int def_size(int arr[] , int size) 
int main() {
    int n[] = {1 , 2 , 3 , 4 , 5};
    def_size(n , 5);            ->          배열을 그대로 전달 , 즉 arr[]과 n[]은 같은 배열이다.(동일 포인터를 가짐)
}
*/
