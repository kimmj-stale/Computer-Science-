#include <iostream>
using namespace std;
#include "Circle.hpp"

// Clrcle 클래스 구현. 모든 멤버 함수를 작성한다.

Circle::Circle() {
    radius = 1;
    cout << "반지름 " << radius << " 원 생성\n";
}

Circle::Circle(int r) {
    radius = r;
    cout << "반지름 " << radius << " 원 생성\n";
}

double Circle::getArea() {
    return 3.14*radius*radius;
}