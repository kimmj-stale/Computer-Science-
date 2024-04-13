/**
 * 함수와 참조, 복사 생성자

 * 인자 전달 방식
 *  1 , 값에 의한 호출(call by value)
    - 함수가 호출되면 매개 변수가 스택에 생성됨
    - 코드에서 호출되어 넘어온 값은 코드에서 매개변수에 복사됨
 *  2 , 주소에 의한 호출(call by address)
    - 함수와 복사 받는 매개변수는 모두 포인터 타입
    - 호출하는 코드에서는 값으로 주소값을 넘겨줌 
        !! 기존 타입의 변수나 객체의 경우 주소를 전달 , 배열의 경우 배열의 이름 전달 !!
    - 넘어온 주소값이 매개 변수에 저장됨
*/

/*
//ex1 - 결과 = 1  5

#include <iostream>
using namespace std;

void swap(int a , int b) {
    int tmp = a;
    a = b; 
    b = tmp;
}
int main() {
    int a = 1;
    int b = 5;
    swap(a , b);                //  두 수를 변환 후 저장한 메모리 스택을 반환시키기 때문에 바뀐 두 수가 저장된 스택이 사라져 바뀌지 않는다.
    cout << a << ' ' << b << '\n';
}

//ex2 - 결과  5 1

#include <iostream>
using namespace std;

void swap(int *a , int *b) {
    int tmp = *a;
    *a = *b; 
    *b = tmp;
}
int main() {
    int a = 1;
    int b = 5;
    swap(&a , &b);              //  두 값이 직접 포인터로 지정되어 주소값이 바귀었기 때문에 두 수가 정상적으로 바뀌었다.
    cout << a << ' ' << b << '\n';
}
*/

/**
 * 객체 전달
 * 함수를 호춣하는 쪽에서 객체 전달 - 객체 이름으로 호출
 * 함수의 매개변수 객체 생성
 * 
 * 객체 치환
 * 동일한 class 타입의 객체끼리 치환 가능
 * 객체의 모든 데이터가 복사되어짐
 * 
    Circle c1(5);
    Circle c2(30);
    c1 = c2; // c2 객체를 c1 객체에 비트 단위 복사. c1의 반지름 30됨

 *  객체 리턴
    
*/

/*
#include <iostream>
using namespace std;
class Circle
{
    int radius;
public:
Circle() { radius = 1; }
Circle(int radius) { this->radius = radius; }
void setRadius(int radius) { this->radius = radius; }
double getArea() { return 3.14*radius*radius; }
};

Circle getCircle() {
    Circle tmp(30);
    return tmp;         //  tmp객체의 복사본이 return된다
}
int main() {
    Circle c;
    cout << c.getArea() << '\n';

    c = getCircle();            //  c 객체에 tmp객체를 return 하여 overlap했다. (radius = 30)
    cout << c.getArea() << '\n';
}
*/

/**
 * 참조 변수
 * 참조자(&) 의 도입 , 이미 존재하는 변수에 대한 다른 이름을 선언
 * 참조 변수는 새로운 공간을 할당하지 않으며 이름만 생성된다.
 * !!포인터 변수는 포인터 이름과 해당 주소값이 저장된 공간이 존재한다. 
 *          하지만 참조 변수는 별도로 공간이 존재하지 않는 것이 차이점이다 !!

 * int n=2;
    int &refn = n; // 참조 변수 refn 선언. refn은 n에 대한 별명

    Circle circle;
    Circle &refc = circle; // 참조 변수 refc 선언. refc는 circle에 대한 별명
*/

/*
#include <iostream>
using namespace std;
int main() {
    int inputNumber = 1;
    int outputNumber = 2;
    int &n = inputNumber;
    int &o = outputNumber;      //  n 과 o로 참조 변수를 생성
    n++;
    o++;
    cout << n << ' ' << o << '\n';

    int *p = &n;
    *p = 20;                    //  *p로 n을 받기
    cout << n << ' ' << o << '\n';  
}
*/

/*

*/
#include <iostream>
using namespace std;
class Circle {
    int radius;
public:
    Circle() { radius = 1; }
    Circle(int radius) { this->radius = radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14*radius*radius; }
};  
int main() {
    Circle cir;
    Circle &c = cir;
    c.setRadius(10);
    cout << c.getArea() << '\n';
}



