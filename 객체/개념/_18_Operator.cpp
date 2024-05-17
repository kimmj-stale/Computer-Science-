/**
 * Operator Overloading (연산자 중복)
 * 기호를 문자와 숫자에 적용시켜 간결한 표현을 위해 쓰임
 * 높은 가독성을 보여줄 수 있다
*/

/**
 * 연산자 중복의 특징
- C++에 본래 있는 연산자만 중복 가능
- 피 연산자 타입이 다른 새로운 연산은 미리 정의해야 함
- 연산자는 함수 형태로 구현됨 , 내장 연산자를 제외하면 별도로 함수로 선언해야 함
- 연산자 선언시 반드시 class와 연결되어야 함
- 피연산자의 갯수는 바꿀 수 없고 연산의 우선 순위는 변경되지 않는다.

 * 연산자 선언
- 연산자 함수 구현 방법
1, 클래스의 멤버 함수로 구현
2, 외부 함수로 구현 후 클래스에 함수로 선언
- 연산자 함수 형식
!!
    (return type) operator (연산자 명) (매개 변수 리스트) {
    연산자의 연산
}
!!
*/

/**
 * Infix Operator (이항 연산자)
 * 대부분의 연산은 이항 연산자기 때문에 연산 과정에서 일어나는 방식을 알아야 한다.
*/

/*
c = a + b 연산
c = a. + (b) (+ 라는 operator가 class에 선언되어있음)
class Power {
    int kick;
    int punch;
public:
    .................
    Power operator+ (Power op2);    //  변수 (b)가 선언된 op2에 들어감
};

Power Power::operator+(Power op2) {
    Power tmp;
    tmp.kick = this->kick + op2.kick;
    tmp.punch = this->punch + op2.punch;
    return tmp;
}
*/

/* ex 1)
#include <iostream>
using namespace std;

class Power {
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0) {
        this -> kick = kick;
        this -> punch = punch;
    };
    void show();
    Power operator + (Power op2);   //  연산자 선언
};

void Power :: show() {  //  (kick , punch) 값을 보여주는 함수
    cout << "kick = " << kick << " , " << "punch = " << punch << '\n';
}

Power Power :: operator+ (Power op2) {  //  연산자의 연산을 선언
    Power tmp;
    tmp.kick = this -> kick + op2.kick;
    tmp.punch = this -> punch + op2.punch;
    return tmp;
}

int main() {
    Power a(3 , 5) , b(4 , 6) , c;
    c = a + b;
    a.show();
    b.show();
    c.show();
}
*/

/*ex 2)
#include <iostream>
using namespace std;

class Power {
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0) {
        this -> kick = kick;
        this -> punch = punch;
    };
    void show();
    bool operator == (Power op2);   //  bool type의 연산자 선언
};

void Power :: show() {  //  (kick , punch) 값을 보여주는 함수
    cout << "kick = " << kick << " , " << "punch = " << punch << '\n';
}

bool Power :: operator == (Power op2) {  //  연산자의 연산을 선언
    if (kick == op2.kick && punch == op2.punch) return true;
    else return false;
}

int main() {
    Power a(3 , 5) , b(4 , 6);
    a.show();
    b.show();

    if (a == b) cout << "==" << '\n';
    else cout << "!=" << '\n';
}
*/

/*ex 3)
#include <iostream>
using namespace std;

class Power {
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0) {
        this -> kick = kick;
        this -> punch = punch;
    };
    void show();
    Power& operator += (Power op2);   //  연산자 선언
};

void Power :: show() {  //  (kick , punch) 값을 보여주는 함수
    cout << "kick = " << kick << " , " << "punch = " << punch << '\n';
}

Power& Power :: operator += (Power op2) {  //  연산자의 연산을 선언
    kick = kick + op2.kick;
    punch = punch + op2.punch;
    return *this;   //  해당 연산자의 연산 결과 값의 주소를 리턴
}

int main() {
    Power a(3 , 5) , b(4 , 6) , c;
    a.show();
    b.show();
    c.show();

    c = a += b;
    a.show();       //  a와 c 모두 바뀜
    b.show();
    c.show();
}
*/

/**
 * 단항 연산자
 * 피연산자가 한 개인 연산자
 * 
*/

/*ex 1 - 전위 ++ 연산자
#include <iostream>
using namespace std;
class Power {
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0) {
        this->kick = kick; 
        this->punch = punch;
    }
    void show();
    Power& operator++ (); // 전위 ++ 연산자 함수 선언
};

void Power::show() {
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power& Power::operator++() {    //  전위 ++ 연산자 멤버 함수 구현
    kick++;
    punch++;
    return *this; // 변경된 객체 자신의 참조 리턴
}

int main() {
    Power a(3,5), b;
    a.show();
    b.show();
    b = ++a; // 전위 ++ 연산자 호출
    a.show();
    b.show();
}
*/

/*ex 2 - 후위 ++ 연산자
#include <iostream>
using namespace std;
class Power {
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0) {
        this -> kick = kick;
        this -> punch = punch;
    }
    void show();
    Power operator++ (int x);
};

void Power::show() {
    cout << "kick = " << kick << "punch = " << punch << '\n';
}

Power Power :: operator++ (int x) { //  문법적인 약속 때문에 x를 선언함 , 실제 사용 X
    Power tmp = *this;
    kick++;
    punch++;
    return tmp;
}

int main() {
    Power a(3 , 5) , b;
    a.show();
    b.show();
    b = a++;
    a.show();
    b.show();
}
*/

/*ex 3 - 전위 + 후위 연산자 동시 사용
#include <iostream>
using namespace std;
class Power {
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0) {
        this -> kick = kick;
        this -> punch = punch;
    }
    void show();
    Power operator++ (int x);
    Power& operator++ (); // 전위 ++ 연산자 함수 선언
};

void Power::show() {
    cout << "kick = " << kick << "punch = " << punch << '\n';
}

Power Power :: operator++ (int x) { //  문법적인 약속 때문에 x를 선언함 , 실제 사용 X
    Power tmp = *this;
    kick++;
    punch++;
    return tmp;
}

Power& Power::operator++() {    //  전위 ++ 연산자 멤버 함수 구현
    kick++;
    punch++;
    return *this; // 변경된 객체 자신의 참조 리턴
}

int main() {
    Power a(3 , 5) , b;
    a.show();
    b.show();
    //kick = 3punch = 5
    //kick = 0punch = 0

    b = a++;
    a.show();
    b.show();
    //kick = 4punch = 6
    //kick = 3punch = 5

    b = ++a;
    a.show();
    b.show();
    //kick = 5punch = 7
    //kick = 5punch = 7
}
*/

