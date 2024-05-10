#include <iostream>
using namespace std;

#include "Circle.hpp"

Circle::Circle() {
    radius = 1;
    cout << "반지름이 " << radius << "인 원 생성" << '\n';
}

Circle::Circle(int r) {
    radius = r;
    cout << "반지름이 " << radius << "인 원 생성" << '\n';
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}