/**
 * 얕은 복사와 깊은 복사

 * 얕은 복사
 * 객체 복사 시 객체 멤버를 1대 1로 복사함
 * 객체 복사본이 객체의 멤버 변수의 동적 메모리를 동시에 할당받는 문제가 발생할 수 있음

 * 깊은 복사
 * 객체 복사 시 객체의 멤버를 1대1로 복사
 * 객체가 멤버 변수의 동적 메모리를 할당받은 경우 깊은 복사는 별도로 동일한 크기의 메모리 장소를 할당받음
 * 별도 할당받은 장소에 변수의 복사본을 넣음
 * 메모리 충돌이 일어날 것을 방지
*/

/**
 * 복사 생성자
 * 객체의 복사 생성 시 호출되는 특별한 생성자
 * 한 클래스에 오직 하나만 선언 가능 , 클래스 내에서 중복 선언 가능
*/

/* 복사 생성자 예시
#include <iostream>
using namespace std;
class Circle {
private:
    int radius;
public:
    Circle(const Circle& c); // 복사 생성자 선언
    Circle() { radius = 1; }
    Circle(int radius) { this->radius = radius; }
    double getArea() { return 3.14*radius*radius; }
}; 

Circle :: Circle(const Circle& c) {     //  복사 생성자 생성
    this -> radius = c.radius;
    cout << "복사 생성자 실행 radius : " << radius << '\n';
}

int main() {
    Circle src(30);
    Circle dest(src);       //  복사 생성자를 호출하여 src(30)을 그대로 받아옴

    cout << "원본의 면적 = " << src.getArea() << endl;
    cout << "사본의 면적 = " << dest.getArea() << endl;
}
*/

/**
 * 디폴트 복사 생성자
 * 복사 생성자를 별도로 생성하지 않은 경우 컴파일러가 디폴트 복사 생성자가 호출한다.
*/

/*디폴트 복사 생성자 예시
#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <cstring>
using namespace std;

class Person { // Person 클래스 선언
    char* name;
    int id;
public:
    Person(int id, const char* name); // 생성자
    ~Person(); // 소멸자
    void changeName(const char *name);
    void show() { cout << id << ',' << name << endl; }
};

Person :: Person(int id , const char* name) {
    this -> id = id;
    int len = strlen(name);
    this -> name = new char(len + 1);
    strcpy(this -> name , name);
}

//------------------------------------------------------
Person::Person(const Person& person) { // 별도 복사 생성자 선언하는 경우 (깊은 복사)
    this->id = person.id; // id 값 복사
    int len = strlen(person.name);// name의 문자 개수
    this->name = new char [len+1]; // name을 위한 공간 핟당
    strcpy(this->name, person.name); // name의 문자열 복사
    cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << endl;
}
//------------------------------------------------------

Person :: ~Person() {
    if (name) {
        delete[] name;
    }
}

void Person :: changeName(const char* name) {
    if (strlen(name) > strlen(this -> name)) {
        return;
    }
    strcpy(this -> name , name);
}

int main() {
    Person father(1 , "Kitae");
    Person daughter(father);

    cout << "daughter 객체 생성 직후 ----- " << '\n';
    father.show();
    daughter.show();

    daughter.changeName("Grace");
    cout << "daughter 이름은  Grace로 변경한 후 ---- " << '\n';
    father.show();
    daughter.show();

    return 0;
}
*/
