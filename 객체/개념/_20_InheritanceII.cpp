/*
#include <iostream>
using namespace std;

class Adder {
protected:
    int add(int a , int b) {return a + b;}
};

class Subtractor {
protected:
    int minus(int a , int b) {return a - b;}
};

//다중 상속
class Calculator : public Adder, public Subtractor {
public:
    int calc(char op , int a , int b);
};

int Calculator :: calc(char op , int a , int b) {
    int res = 0;
    switch(op) {
        case '+':
            res = add(a , b);
            break;
        case '-':
            res = minus(a , b);
            break;
    }
    return res;
}

int main() {
    Calculator handCalculator;
    cout << "2 + 4 = " << handCalculator('+' , 2 , 4) << '\n';
    cout << "100 - 8 = " << handCalculator('-' , 100 , 8) << '\n';
}
*/

/*
#include <iostream>
using namespace std;

class Base {
    public:
    void f() {
        cout << "Base :: f() called " << '\n';
    }
};

class Derived : public Base {
public:
    void f() {
        cout << "Derived :: f() called " << '\n';
    }
};

int main() {
    Derived d, *pDer;
    pDer = &d;
    pDer -> f();

    Base* pBase;
    pBase = pDer;
    pBase -> f();
}
*/