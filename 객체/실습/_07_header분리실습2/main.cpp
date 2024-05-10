#include <iostream>
using namespace std;

#include "Circle.hpp"

int main() {
    Circle donut;
    double area = donut.getArea();
    cout << " donut의 면적은 " << area << "\n";

    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza의 면적은 " << area << "\n";
}