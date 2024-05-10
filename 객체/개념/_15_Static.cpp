/**
 * Static 멤버
 * 변수와 함수에 대한 기억
 * 생명 주기 - 프로그램 시작 시 생성, 종료 시 소멸
 * 사용 범위 - 선언된 범위
 * 클래스 당 하나만 생성
 * 클래스의 모든 객체가 공유하는 멤버

 * non static 멤버
 * 객체의 생성과 함깨 생성 , 객체 마다 생성됨
 * 인스턴스 멤버라고 부르기도 함
*/

/*
Static vs non - Static
//static
- static 멤버는 객체 내부가 아닌 별도의 공간에 생성
- 클래스 멤버라고 부름
- 동일 클래스의 모든 객체들에 의해 공유
- 클래스 멤버이기 때문에 범위 지정 연산자(::)로 접근 가능
- 객체 호출로 지정도 가능

- 프로그램과 생명을 같이함
- 객체가 사라져도 여전히 존재 , 프로그램이 종료될 때 함께 소멸

//non - static
- 객체마다 별도 생성
- 인스턴스 멤버라고 부름
- 지정 접근 연산자로 접근 불가능

- 객체와 생명을 같이함
- 객체 소멸 시 같이 소멸

- 다른 객체들과 공유되지 않음
*/

/**
 * static의 활용
1, 
 * 전역 변수나 전역 함수를 클래스에 캡슐화
 * - 전역 변수나 전역 함수를 가능한 사용하지 않도록 권장
2, 
 * 객체 사이에 공유 변수를 만들고자 할 때
 * - static 멤버를 선언하여 모든 객체들이 공유
*/

/*
#include <iostream>
using namespace std;
class Person {
    public:
        int money; // 개인 소유의 돈
        void addMoney(int money) {
        this->money += money;
    }
    static int sharedMoney; // 공금 - 모든 객체들과 공유하는 멤버 변수
    static void addShared(int n) {  //  모든 멤버들이 공유하는 공통 함수
        sharedMoney += n;
    }
};

// static 변수 생성. 전역 공간에 생성
//static 변수에 미리 10이란 값을 선언
int Person::sharedMoney=10;

int main() {
    Person han;
    han.money = 100; // han의 개인 돈=100
    han.sharedMoney = 200; // static 멤버 접근, 공금=200
    Person lee;
    lee.money = 150; // lee의 개인 돈=150
    lee.addMoney(200); // lee의 개인 돈=350
    lee .addShared(200); // static 멤버 접근, 공금=400
    cout << han.money << ' ' << lee.money << endl;
    cout << han.sharedMoney << ' ' << lee.sharedMoney << endl;
}
*/

/* static 멤버 범위 지정 연산자로 접근
#include <iostream>
using namespace std;
class Person {
    public:
        int money; // 개인 소유의 돈
        void addMoney(int money) {
        this->money += money;
    }
    static int sharedMoney; // 공금
    static void addShared(int n) {
        sharedMoney += n;
    }
};
// static 변수 생성. 전역 공간에 생성
int Person::sharedMoney=10; // 10으로 초기화
// main() 함수
int main() {
    Person::addShared(50);
    cout << Person :: sharedMoney <<'\n';

    Person han;
    han.money = 100; // han의 개인 돈=100
    // Person :: money는 static 멤버가 아니라 불가능
    han.sharedMoney = 200; // static 멤버 접근, 공금=200

    //지정 접근 연산자를 이용해 접근
    Person :: sharedMoney = 300;
    Person :: addShared(100);
    //han.addShared(100)으로도 연산됨
    //static 멤버는 지정 접근 연산자나 객체 생성 후 호출이나 상관 없음
    cout << han.money << ' ' << Person :: sharedMoney << '\n';
}
*/

/**
 * static 멤버 주의사항
- static 멤버는 non - static 멤버에 접근 할 수 없다.
- non - static 멤버는 static 멤버에 접근 가능함
- 객체가 생성되지 않은 시점에서 static 멤버 함수가 호출된 수 없기 때문
- static 멤버 함수는 this 사용이 불가능하다.
!! 객체 생성 이전부터 존재하는 변수 / 함수이기 때문에 사용이 불가능하다. !!

//static 멤버 함수가 접근 할 수 있는 것
1, static 멤버 함수
2, static 멤버 변수
3, 함수 내의 지역 변수
*/

