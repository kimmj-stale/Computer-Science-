/**
 * inline함수
 * inline 키워드로 선언된 함수
 * 자주 호출되는 함수를 내포하고 있어 프로그램 실행 속도를 향상시킴
 * 컴파일러에 의해 자동으로 실행됨
 * 짧은 함수를 사용할 때만 사용하는 것을 권장
 * 최대 30%까지 속도 향상, 보통 자동으로 inline되어짐


 * 별도 함수 호출에 필요한 메모리 오버클럭이 심해질 수 있다.
 * 간단한 기능인 경우 행위를 반복하는 경우 보다 호출 - 행위의 반복 프로세스는 붎필요하게 메모리를 잡아먹을 수 있다.
*/

/*
#include <iostream>
using namespace std;

inline int odd(int x) {
    return (x%2);
}

int main() {
    int sum = 0;
    for(int i=1; i<=10000; i++) {
        if(odd(i))                  //  실행 횟수가 많아질수록 오버플로우가 발생(불필요하게 호출 - 실행을 반복해야 함)
                                    //  inline으로 호출했으므로 함수 사용할 때 마다 호출하지 말고 자동으로 main 함수에 삽입
            sum += i;
    }
    cout << sum;
}
*/

/*
class Circle {
    private:
    int radius;
    public:
        Circle() { // 자동 인라인 함수
        radius = 1;
    }
        Circle(int r);
        double getArea() { // 자동 인라인 함수 선언
        return 3.14*radius*radius;
        }
    };
    Circle::Circle(int r) {
        radius = r;
    }
*/
