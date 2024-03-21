/**
 * encapsulation(캡슐화)
 * 객체의 기본적인 특성
 * 객체를 둘러싸고 있어 객체의 내부를 볼 수 없도록 함
 * 보안 , 보호 , 외부 접근 제한 등의 이유로 사용함
 * 객체의 일부 요소들을 외부로 공개된다 - ex) 함수의 사용처 , 사용법 , 사용명 ....
 * 객체는 멤버 변수 , 멤버 함수로 구성된다.
*/

/*
멤버 변수
ex/
boolean on = true;
int channel = 8;
int volume = 16;
.
.
.
.

멤버 함수
ex/
def channalUpper;
def volumeDown;
def mute;
.
.
.
.
*/

/**
 * class (클래스)
 * 객체를 형성하기 위한 기본적인 틀
 * class만으론 객체를 형성할 수 없다
 * 멤버 변수 && 멤버 함수 선언
*/

/*
class declaration (클래스 선언)

*/

/**
 * 객체
 * class의 구성 형태를 그대로 가져옴
 * 멤버 함수와 멤버 변수를 포함하고 있고 객체 생성 시 이 값들이 메모리에 저장된다. = instance(실체)
 * 하나의 클래스 틀에서 여러 객체를 생성 가능하다. 서로 다른 객체들은 다른 저장 공간에 저장된다.
*/

/*
#include <iostream>
using namespace std;
class Circle//(클래스 명)
{
public:     //클래스에 지정할 변수
    int radius;
    double get_area();
};
    double Circle :: get_area() {       //클래스에서 사용할 함수 지정
        return 3.14 * radius * radius;
    }

int main() {
    Circle app;     //객체 생성 && 객체명 지정
    int r;
    cin >> r;
    app.radius = r; //class의 변수를 main 함수에서 사용할 변수로 지정
    double area = app.get_area();   //출력값으로 받을 값을 지정
    cout << area << '\n';

    Circle add;     //객체 생성 && 객체명 지정
    int d;
    cin >> d;
    add.radius = d;
    double area2 = add.get_area();  
    cout << area2 << '\n';
}
*/
