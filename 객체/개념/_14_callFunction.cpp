/**
 * 함수 중복
 * 동일한 함수명을 여러개 생성 가능(C언어에선 불가능) - function overloading
 * 동일한 함수명을 사용하면 함수 구분자를 기억할 필요가 없어 호출 실수가 줄어든다
*/

/**
 * 함수 중복이 가능한 범위
 * 일반 함수
 * 동일 class내의 멤버들 간
 * 상속 관계의 기본 class와 파생 class의 멤버 함수들 간

 * !!함수명이 중복될 경우 다른 리턴값이나 다른 매개변수를 가져야 함!!
 * 리턴 타입은 함수 중복과 무관

ex - 
int sum(int a , int b , int c) {
    return a + b + c;
}

double sum(double a , double b) {   //  매개변수의 자료형이 다르다.
    return a + b;
}

int sum(int a , int b) {        //  리턴값의 자료형은 기존과 동일 , 하지만 매개 변수의 갯수가 다름
    return a + b;
}

double sum(double a , double b , double c) {        //  기존 함수와 이 함수 중 어떤 함수를 호출해야 될지 구분할 수 없어 에러가 발생한다.
    return a + b + c;
}
*/


/*ex 
#include <iostream>
using namespace std;

//a와 b 중 큰 수를 리턴한다.
int big(int a , int b) {
    if (a > b) return a;
    else return b;
}
//배열과 배열의 크기를 입력받아 배열의 원수 중 가장 큰 수를 리턴한다.
int big(int a[] , int size) {
    int res = 0;
    for (int i = 1; i < size; i++) {
        if (res < a[i]) res = a[i];
    }
    return res;
} 

int main() {
    int array[5] = {1 , 9 , -2 , 8 , 6};
    cout << big(2 , 3) << '\n';         //  숫자 두개가 입력된 경우 첫 번째 big 함수를 호출
    cout << big(array , 5) << '\n';     //  배열이 입력된 경우 두 번째 big 함수를 호출
}
*/

/**
 * 디폴트 매개 변수
 * 매개 변수에 갑이 넘어오지 안는 경우 디폴트 값을 받도록 선언된 매개 변수
 * '매개 변수 = 디폴트 값' 형태로 선언
 * 
 * 디폴트 매개 변수는 보통 매개 변수 앞에 선언될 수 없다. 뒷 쪽으로 몰려 선언되어야 함

ex - 
void star(int a = 5)  //    디폴트 매개변수를 이용해 a = 5 미리 지정

star()  //  매개변수 a에 디폴트 값 5가 전달됨
star(10)    //  매개 변수 a에 10을 전달
*/

/*
#include <iostream>
using namespace std;

//디폴트 매개 변수 사용 후 함수를 별도 지정하는 경우도 가능하다.
함수 선언과 동시에 매개변수 입력보단 디폴트 매개변수 지정 후 함수 선언하는 편이 더 확실하다.
void star(int a = 5);
void msg(int id , string text = "");

void star(int a) {
    for (int i = 0; i < a; i++) {
        cout << '*';
    }
    cout << '\n';
}

void msg(int id , string text) {
    cout <<id << '\n';
}

void star(int a = 5) {
    for (int i = 0; i < a; i++) {
        cout << '*';
    }
    cout << '\n';
}

void msg(int id , string text = "") {
    cout <<id << '\n';
}

int main() {
    star();
    star(10);

    msg(10);
    msg(10 , "Hello");
}
*/

/*
#include <iostream>
using namespace std;
void f(char c = ' ' , int line = 1) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < 10; j++) {
            cout << c;
        }
        cout << '\n';
    }
}

int main() {
    f();
    f('%');
    f('@' , 5);
}
*/

/*
#include <iostream>
using namespace std;

void fillLine(int n = 25 , char c = '*') {
    for (int i = 0; i < n; i++) {
        cout <<c;
    }
    cout << '\n';
}

int main() {
    fillLine();
    fillLine(10 , '%');
}
*/


