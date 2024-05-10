/**
 * this 포인터
 * 객체 자신을 지칭하는 포인터
 * 동일 class 내의 멤버 함수에서만 허용
 * !!개발자 자신이 선언한 변수가 아닌 컴파일러가 직접 선언한 변수!!
 * 컴파일러가 묵시적으로 매개변수 자리에 호출 함수를 생성

 * this가 필요한 경우
    매개변수의 이름과 멤버 변수의 이름이 같은 경우
    멤버 함수가 객체 자신의 주소를 리턴할 때 - 연산자가 중복될 때 매우 필요!

 * this의 제약
    멤버 함수가 아닌 다른 함수에서 this 사용 불가능
    !!static 멤버 함수에서 this 사용 불가!! - 객체 생성 전 static함수의 호출이 있을 수 있기 때문
*/

/* ex
#include <iostream>
using namespace std;
class Circle
{
    int radius;
public:
    Circle() {this -> radius = 1;}   // 
    Circle(int n) {this -> radius = n;}
    void setRadius(int n) {this -> radius = n;}
    double getArea() {return 3.14 * radius * radius;}
};

int main() {
    Circle cir;
    int n;
    cin >> n;
    cir.setRadius(n);
    cout << "원의 넓이는 " << cir.getArea() << '\n';
}
*/

/**
 * string header
 * 문자열 조작이 가능하도록 함수들을 저장해 놓은 header 파일
*/

/*
#include <iostream>
#include <string>

using namespace std;
int main() {
    string str;
    string address = "서울시 성북구 삼선동 389";
    string copyAddress(address);        //  copyAddress라는 새로운 string 문자열을 생성 후 붙여넣기

    char text[] = {'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0'};
    string title(text);

    cout << str << '\n';
    cout << address << '\n';
    cout << copyAddress << '\n';
    cout << title << '\n';
}
*/
