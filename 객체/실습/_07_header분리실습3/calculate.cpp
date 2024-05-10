#include <iostream>
using namespace std;

#include "calculate.hpp"

calculate :: calculate() {
    num1 = 1;
    num2 = 1;
}

calculate :: calculate(int a , int b) {
    num1 = a;
    num2 = b;
}

int calculate :: add() {
    return num1 + num2;
}

int calculate :: sub() {
    return num1 - num2;
}

int calculate :: mul() {
    return num1 * num2;
}

int calculate :: div() {
    return num1 / num2;
}