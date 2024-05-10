/**
 * 객체 포인터
 * 해당 특정 객체들의 주소를 가지는 포인터
 * 해당 객체 내의 멤버들을 지칭할 때 (객체 포인터) -> (멤버 이름)
*/

/*
Circle donut;
double d = donut.getArea();

Circle *p   =>  해당 객체를 지칭하는 객체 포인터 선언
p = &donut; =>  해당 객체의 주소값 저장
d = p -> getArea();     =>  객체의 멤버를 호출
*/

/* 예제 1
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }    
    Circle(int r) { radius = r; }
    double getArea();
    };

double Circle::getArea() {
    return 3.14*radius*radius;
}

int main() {
    Circle donut;
    Circle pizza(30);

    Circle *p;

    p = &donut;
    cout << (*p).getArea() << '\n';         //  객체를 불러올 때의 방식
    cout << p -> getArea() << '\n';

    p = &pizza;
    cout << (*p).getArea() << '\n';
    cout << p -> getArea() << '\n';
}
*/

/**
 * 객체 배열
 * 해당 class의 객체를 저장할 수 있는 배열을 생성 가능하다.
    매개변수가 없는 생성자를 호출해야 객체 배열을 사용할 수 있다.
    !!(매개변수가 있는 생성자를 호출하다가 기본 생성자를 까먹을 수 있으니 그냥 생성해 놓는 것을 추천)!!

 * 객체 배열 초기화
    배열의 각 원소 객체당 생성자를 지정할 수 있다.
    Circle circleArray[3] = { Circle(10), Circle(20), Circle() };  =>   객체 마다 호출
*/

/*
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }    
    Circle(int r) { radius = r; }
    void setRadius(int r) {
        radius = r;
    }
    double getArea();
    };

double Circle::getArea() {
    return 3.14*radius*radius;
}

int main() {
    Circle circleArray[3];          //  배열 선언

    circleArray[0].setRadius(10);
    circleArray[1].setRadius(20);
    circleArray[2].setRadius(30);

    for (int i = 0; i < 3; i++) {
        cout << i << "번째 원의 넓이는 " << circleArray[i].getArea() << '\n';
    }

    Circle *p;                      //배열 포인터 선언
    p = circleArray;                //포인터로 circleArray 지칭
    for (int i = 0; i < 3; i++) {
        cout << i << "번째 원의 넓이는 " << p -> getArea() << '\n';     //  객체 포인터로 circleArray를 지칭한 후 getArea를 불러옴
        p++;        //  다음 array로 넘어감
    }
}
*/

/*
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }    
    Circle(int r) { radius = r; }
    void setRadius(int r) {
        radius = r;
    }
    double getArea();
    };

double Circle::getArea() {
    return 3.14*radius*radius;
}

int main() {
    Circle circleArray[3] = {Circle(10) , Circle(20) , Circle()};   //  객체 초기화

    for (int i = 0; i < 3; i++) {
        cout << i << "번째 원의 넓이는 " << circleArray[i].getArea() << '\n';
    }
    
    Circle *p;
    p = circleArray;
    for (int i = 0; i < 3; i++) {
        cout << i << "번째 원의 넓이는 " << p -> getArea() << '\n';
        p++;
    }
}
*/

/*
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }    
    Circle(int r) { radius = r; }
    void setRadius(int r) {
        radius = r;
    }
    double getArea();
    };

double Circle::getArea() {
    return 3.14*radius*radius;
}

int main() {
    Circle circleArray[2][3];
    circleArray[0][0].setRadius(1);
    circleArray[0][1].setRadius(2);
    circleArray[0][2].setRadius(3);
    circleArray[1][0].setRadius(4);
    circleArray[1][1].setRadius(5);
    circleArray[1][2].setRadius(6);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << circleArray[i][j].getArea() << '\n';
        }
    }
}
*/
