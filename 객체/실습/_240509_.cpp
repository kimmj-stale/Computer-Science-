/*

#include <iostream>
using namespace std;

class Circle
{
public:
    int radius;
    double getParameter(int r) {this -> radius = r;}
    double getArea();
    double getPerimeter() {
        return 2 * 3.14 * radius;
    }
};

double Circle :: getArea() {
    return radius * radius * 3.14;
}

class Square
{
public:
    int length;
    double getParameter(int s) {this -> length = s;}
    double getArea();
    double getPerimeter() {
        return 4 * length;
    };
};

double Square :: getArea() {
    return length * length;
}


int main() {
        cout << "************************" << '\n';
        cout << "** 도형 계산 프로그램 **" << '\n';
        cout << "************************" << '\n';
        cout << "1. 원      2. 정사각형     3. 나가기" << '\n';
        int n , radi;
        cout << "번호 입력: ";
        cin >> n;
    while (1) {
        int loop = 1;
        switch (n)
        {
        case 1:
            cout << "원의 반지름을 입력하세요: ";
            cin >> radi;
            cout << '\n';

            Circle cir;
            cir.getParameter(radi);
            cout << "원의 넓이: " << cir.getArea() << '\n';
            cout << "원의 둘레: " << cir.getPerimeter() << '\n';
            break;
        case 2:
            cout << "변의 길이를 입력하세요: ";
            cin >> radi;
            cout << '\n';

            Square sqr;
            sqr.getParameter(radi);
            cout << "정사각형의 넓이: " << sqr.getArea() << '\n';
            cout << "정사각형의 둘레: " << sqr.getPerimeter() << '\n';
            break;
        default:
            cout << "도형 계산이 종료됩니다." << '\n';
            loop = 0;
            break;
        }
        if (loop == 0) break;
    }
}
*/
