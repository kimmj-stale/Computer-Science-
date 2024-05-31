/**
 * 오버라이딩과 범위 지정 연산자
 * 범위 지정 연산자(::)를 사용하여 기본 클래스의 가상 함수를 정적 바인딩으로 호출이 가능하다
ex) class Circle
Circle :: circle() {    //  Circle 클래스의 circle 호출
    ~~~
}
*/

/*
#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw() {
        cout << "-- Shape --";
    }
};

class Circle : public Shape {
public :
    virtual void draw() {
        Shape :: draw();
        cout << "Circle" << '\n';
    }
};

int main() {
    Circle circle;
    Shape* pShape = &circle;

    pShape -> draw();
    pShape -> Shape :: draw();
}
*/

/**
 * 가상 소멸자
 * 소멸자를 virtual 키워드로 묶어서 선언 가능
 * 소멸자가 호출될 때 동적 바인딩이 발생한다.
- 파생 클래스의 소멸자가 자신의 코드를 실행 후 기본 클래스의 소멸자를 자동으로 호출하도록 가상 소멸자를 생성 (= 동적 바인딩)
*/

/* 가상 소멸자 예제

*/
#include <iostream>
using namespace std;

class Base {
public :
    virtual ~Base() {
        cout << "~B" << '\n';
    }
};

class Derived : public Base {
public:
    virtual ~Derived() {
        cout << "~D" << '\n';
    }
};

int main() {
    Derived *dp = new Derived();
    Base* bp = new Derived();

    delete dp;
    delete bp;
}
