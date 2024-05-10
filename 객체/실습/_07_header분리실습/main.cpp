#include <iostream>
using namespace std;

#include "Circle.hpp"

int main() {
    Circle donut;
    double area = donut.getArea();
    cout << "면적은 " << area << '\n';

    Circle pizza;
    area = pizza.getArea();
    cout << "면적은 " << area << '\n';
}