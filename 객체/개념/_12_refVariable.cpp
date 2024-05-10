/**
 * 참조 변수 사용 예재
*/

/*ex
#include <iostream>
using namespace std;
class Circle {
private:
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    double getArea() { return 3.14*radius*radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() {
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int radius) {
    this->radius = radius;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
    cout << "소멸자 실행 radius = " << radius << endl;
}

void increaseCircle(Circle &c) {    //  Circle 의 참조 변수를 생성
    int r = c.getRadius();
    c.setRadius(r+1);
}

int main() {
    Circle waffle(30);      //  radius의 길이를 지정
    increaseCircle(waffle);     //  참조 변수를 이용하여 increaseCircle을 사용
    cout << waffle.getRadius() << endl;
}
*/

/*
#include <iostream>
using namespace std;

char& find(char[] s , int idx) {
    return s[idx];
}

int main() {
    char name[] = "Mike";
    cout << name << '\n';

    find(name , 0) = 'S';
    cout << name << '\n';

    char& ref = find(name , 2);
    ref = 't';
    cout << name << '\n';
}
*/

/*
#include <iostream>
using namespace std;

char& find(char s[], int index) {
    return s[index]; // 참조 리턴
}

int main() {
    char name[] = "Mike";
    cout << name << endl;
    find(name, 0) = 'S'; // name[0]='S'로 변경
    cout << name << endl;
    char& ref = find(name, 2);
    ref = 't'; // name = "Site"
    cout << name << endl;
}
*/
