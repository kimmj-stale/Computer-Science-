/**
 * C++의 기본 구조론
 * C++의 기본 구조틀은 기존의 C와 아주 유사하다.
 * 객체 언어이기에 별도의 함수마다 개별 연산하는 것이 아닌 객체를 호출하여 연산한다.
 * ex / main  , 별도 생성 함수 , using , ....../
*/

/*
#include <iostream>
//iostream = Input & Output stream
표준 입/출력과 객체 , 기본 함수등이 미리 선언되어 있는 전처리기(header).//
using namespace std;

int main() {
main 함수는 기존 헤더가 가지는 가장 기본적인 객체, 주된 자료들의 input & output 등을 담당한다.
    char a;
    cin >> a;
    //입력한 데이터를 char 자료형의 변수 a에 담는다.
    // >> 는 기존 시프트 연산자에서 스트림 삽입 연산자로 재정의된 것 
    cout << a;
    //char 자료형의 변수 a를 출력한다.
    // << 는 기존 시프트 연산자에서 스트립 출력 연산자로 재정의된 것
    // << 는 함수를 호출하거나 연산 호출도 가능하다.
}
*/

/**
 * 주석문
 *  주석을 다는 이유는 팀 프로젝트에 용이하기 때문, 해당 코드마다 의도를 작성해야 하기 때문
*/

/**
 * 자료형
 * int , double , float ,  string , char , boolean(bool) , size_t , ....등이 있다.
*/

/*ex
#include <iostream>
using namespace std;
//namespace를 미리 지정하여 std를 굳이 쓰지 않아도 함수의 namespace를 자동으로 사용해 준다.
int main() {
    int a = 3;
    float b = 1.5;
    double c = 3.33;
    char d = '#';
    bool e = true;
    string f = "hello";

    bool *ptr = &e;
    string *pt = &f;
    cout << pt << ' ' << *pt << '\n';   
    cout << ptr << ' ' << *ptr << '\n';     ->      bool 이나 string도 pointer로 지정 가능 , 메모리 값을 가진다.
}
*/

/*ex
#include <iostream>
using namespace std;
double arrea(int r);
double arrea(int r) {
    return 3.14 * r * r;
}
int main() {
    double a;
    char c = '#';
    cin >> a;
    cout << c << 5.5 << '-' << a << "hello" << true << '\n';
    cout << a + 5 << '\n';
    cout << "면적은" << arrea(a) << '\n';
}
*/

/**
 * namespace
 * 동일한 함수명이나 변수명을 다른 객체나 파일에 사용한 경우 충돌이 일어난다.
 *  이를 방지하기 위해 개발자가 별도의 공간을 형성할 수 있도록 namespace를 설정할 수 있도록 만들었다.
*/

/*
#include <iostream>
using namespace std;
using namespace k
{
    int a = 1;
    char b;
}; // namespace k
//////////////////////////////
#include <iostream>
#include "k"            ->          위 파일의 k header를 가져와서 사용한다.
using namespace std;
using namespace j
{
    int a = 2;
    char b;
};// namespace j

다른 두 파일에 있는 객체를 가져와서 사용하기 위해 겹치는 변수명 , 객체명 , ....등이 없어야 한다. 이를 방지하기 위해 
다른 namespace를 사용하여 충돌을 방지한다.
*/

/**
 * 문자열
 * <string> header을 사용하여 간단하게 생성 가능
 * C++은 문자열 끝에 초기화 변수 /0이 존재한다.
*/

/*ex
#include <iostream>
#include <string>
using namespace std;
int main() {
    char name1[5] = "hello";
    char name2[6] = "hello";            ->      array형으로 받아야 함
    string name3 = "hello";
    char name4[6] = {'h' , 'e' , 'l' , 'l' , 'o' , '\0'};

    cout << name1[1] << ' ' << name2[6] << ' ' << name3 << ' ' << name4[6] << '\n';
}

#include <iostream>
#include <string>
using namespace std;
int main() {
    char name1[5] = {'h' , 'e' , 'l' , 'l' , 'o'};
    cout << name1[3] << '\n';
}
*/