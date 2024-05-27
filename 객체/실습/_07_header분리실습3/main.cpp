#include <iostream>
using namespace std;
#include "calculate.hpp"

int main() {
    int a , b;
    char s;
    cout << "숫자를 입력하세요";
    cin >> a >> b;

    calculate cal(a , b);
    cout << "계산 방식을 선택하세요";
    cin >> s;
    
    if (s == '+') {
        cout << cal.add() << '\n';
    }
    else if (s == '-') {
        cout << cal.sub() << '\n';
    }
    else if (s == '*') {
        cout << cal.mul() << '\n';
    }
    else if (s == '/') {
        cout << cal.div() << '\n';
    }
    else {
        cout << "잘못 입력하셨습니다" << '\n';
    }
}
