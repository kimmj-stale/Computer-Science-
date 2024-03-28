/**
 * 소멸자 (destructor)
 * 객체가 선언된 후 사라지지 않고 계속 메모리를 잡아먹기 때문에 소멸자가 선언되어야 함
 * 별도로 선언할 필요 없이 자동으로 선언 됨
 * 별도로 실행 도중 동적으로 할당받은 메모리 값을 해제하거나 파일 저장 및 닫기, 네트워크 닫기 등에 쓰인다
*/

/*
#include <iostream>
using namespace std;
class Circle
{
public:
    int radius;

    Circle();
    Circle(int r);
    ~Circle();          //  생성자가 소멸할 때 한번 호출된다. 원할 때 임의로 호출 불가능
                        //  기존 생성자가 차지한 메모리가 해제될 때 한번 호출됨, 굳이 선언하지 않아도 자동으로 선언됨
    double geetArea();
};

Circle::Circle()
{
    radius = 1;
    cout << "반지름이 " << radius << "인 원 생성" << '\n'; 
}

Circle :: Circle(int r) {
    radius = r;
    cout << "반지름이 " << radius << "인 원 생성" << '\n'; 
}

Circle::~Circle()
{
    cout << "반지름이 " << radius << "인 원 소멸" << '\n'; 
}
double Circle :: geetArea() {
    return 3.14 * radius * radius;
}
int main() {
    Circle donut;
    Circle pizza(30);

    cout << donut.geetArea() << '\n';
    cout << pizza.geetArea() << '\n';
}
*/

/**
 * 생성자 / 소멸자 실행 순서
 * 지역 객체 - 함수 내에 선언된 객체로 함수 종료와 함께 소멸된다.
 * 전역 객체 - 함수 바깥에서 선언된 객체로 프로그램 종료시에 소멸된다.
 * 
 * 전역 객체는 프로그램에 선언된 순서대로 생성됨, 지역 객체는 함수가 호출되는 순간에 순서대로 생성
 * 지역 객체와 전역 객체는 생성된 순서의 역순으로 소멸
 * 
 * new - 객체 생성
 * delete - 객체 소멸
*/

/*
#include <iostream>
using namespace std;
class Circle
{
public:
    int radius;

    Circle();
    Circle(int r);
    ~Circle();          //  생성자가 소멸할 때 한번 호출된다. 원할 때 임의로 호출 불가능
                        //  기존 생성자가 차지한 메모리가 해제될 때 한번 호출됨, 굳이 선언하지 않아도 자동으로 선언됨
    double getArea();
};

Circle::Circle()
{
    radius = 1;
    cout << "반지름이 " << radius << "인 원 생성" << '\n'; 
}

Circle :: Circle(int r) {
    radius = r;
    cout << "반지름이 " << radius << "인 원 생성" << '\n'; 
}

Circle::~Circle()
{
    cout << "반지름이 " << radius << "인 원 소멸" << '\n'; 
}
double Circle :: getArea() {
    return 3.14 * radius * radius;
}

Circle globalDonut(1000);               
Circle globalPizza(2000);                   //      전역 객체 생성

void f() {
    Circle fDonut(100);
    Circle fPizza(200);                     //      지역 객체 생성
}
int main() {
    Circle donut;
    Circle pizza(30);
    f();

    cout << donut.getArea() << '\n';
    cout << pizza.getArea() << '\n';
    cout << globalDonut.getArea() << ' ' << globalPizza.getArea() << '\n';
    //  소멸 순서는 pizza , donut , globalPizza , globalDonut
}
*/

/**
 * 접근 지정자
*/

/**
 * 캡슐화의 목적
 * 캡슐화는 객체의 보호, 보안을 위한 것임
 * 중요한 멤버를 다른 class나 객체에서 접근할 수 없도록 보호, 접근 가능한 일부 멤버를 형성
 * 
 * private - 동일한 클래스의 멤버 함수에만 제한함
 * public - 모든 다른 클래스에 허용
 * protected - class 자신과 상속받은 자식 클래스에만 허용
*/

/*
#include <iostream>
using namespace std;
class PrivateAccessError {
    private:
        int a;
        void f();
        PrivateAccessError();
    public:
        int b;
        PrivateAccessError(int x);
        void g();
    };
    PrivateAccessError::PrivateAccessError() {
        a = 1; // (1)
        b = 1; // (2)
    }
    PrivateAccessError::PrivateAccessError(int x) {
        a = x; // (3)
        b = x; // (4)
    }
    void PrivateAccessError::f() {
        a = 5; // (5)
        b = 5; // (6)
    }
    void PrivateAccessError::g() {
        a = 6; // (7)
        b = 6; // (8)
    }
int main() {
    PrivateAccessError objA; // (9)         RrivateAccessError()는 private에 존재하므로 호출할 수 없다
    PrivateAccessError objB(100); // (10)
    objB.a = 10; // (11)                    int a값은 private에 존재하므로 임의로 변경할 수 없다
    objB.b = 20; // (12)
    objB.f(); // (13)                       f()는 private에 존재하므로 호출할 수 없다
    objB.g(); // (14)
}
*/

/**
 * 별도 함수 호출에 필요한 메모리 오버클럭이 심해질 수 있다.
*/