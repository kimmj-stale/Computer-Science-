/* 예제 1
#include <iostream>
using namespace std;
class Rectangular
{
public:             >       변수 설정
    int height;
    int width;
    int get_area();
};

int Rectangular::get_area()         >       함수 설정
{
    return width * height;
}

int main() {
    Rectangular rect;       >   class의 객체 설정
    int a , b;
    cin >> a >> b;
    rect.width = a;         >   class에서 설정한 변수 받기
    rect.height = b;
    cout << rect.get_area() << '\n';
}
*/

/**
 * 생성자(constructor)
 * class가 생성될 때 자동으로 호출되는 함수
 * !! class의 이름과 동일한 함수명으로 작성해야 한다. !!
 * !! 리턴 타입이 없다 !!
 * 각 객체마다 생성자가 실행된다. 객체 안에서 다른 class의 여러 생성자를 사용 가능하다.
 * 생성자는 하나의 class에 여러개 호출이 가능하다. 단 하나씩만 실행 가능하다.(여러개 호출 불가능)
 * 생성자가 미리 생성되었다면 자동으로 생성되지 않음
*/

/**
 * 생성자의 목적
 * compiler가 자동으로 생성자를 생성해 준다. 다만 별도의 조작이 들어간 생성자가 필요하거나 여러개의 생성자가 필요할 때 생성 가능하다.
*/

/* 예제 2
#include <iostream>
using namespace std;
class Circle
{
public:
    int radius;
    Circle();
    Circle(int r);
    double get_area(); 
};

Circle::Circle()
{
    radius = 1;
    cout << "반지름이 " << radius << " 인 원의 넓이" << '\n';
}

double Circle::get_area()
{
    return 3.14 * radius * radius;
}

int main() {
    Circle cir;
    cir.radius = 1;
    cout << "넓이는 " << cir.get_area() << '\n'; 
}
*/

/**
 * 위임 생성자
 * 미리 생성된 생성자를 위임하여 간단히 표현하는 방법
*/

/*
Circle::Circle()
{
    radius = 1;
}

Circle::Circle(int r)
{
    radius = r;                 >>      미리 받은 radius값을 넣으려면 두번 써야 해서 복잡하기 때문에 위임 생성자 호출
}
-------------------------------
Circle::Circle() : Circle(1){   >>      앞에서 r값을 미리 받아 뒤의 생성자에 위임
}
Circle :: Circle(int r)
{
    radius = r;
}

*/

/*예제 3
#include <iostream>
using namespace std;
class Rectangular
{
public:
    int x , y;
    int ifCorrect();
};

int Rectangular::ifCorrect()
{
    int height = x;
    int width = y;
    if (height == width) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    Rectangular rect;
    int a , b;
    cin >> a >> b;
    rect.x = a;
    rect.y = b;
    if (rect.ifCorrect() == 1) {
        cout << "정사각형이 맞습니다." << '\n';
    }
    else {
        cout << "정사각형이 아닙니다." << '\n';
    }
}
*/

/*예제4
#include <iostream>
using namespace std;
class Rectangle
{
public:
    int a , b;
    Rectangle();
    Rectangle(int x , int y);
    Rectangle(int z);
    bool isSquare();
};

Rectangle::Rectangle()
{
    a = b = 1;
}
Rectangle :: Rectangle(int x , int y) {
    x = a;
    y = b;
}
Rectangle :: Rectangle(int z) {
    a = z;
    b = z;
}
bool Rectangle :: isSquare() {
    if (a == b) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    Rectangle rect1;
    Rectangle rect2(3 , 5);
    Rectangle rect3(3);

    if (rect1.isSquare()) cout << "rect1은 정사각형입니다." << '\n';
    if (rect2.isSquare()) cout << "rect2은 정사각형입니다." << '\n';
    if (rect3.isSquare()) cout << "rect3은 정사각형입니다." << '\n';
}
*/
