/**
* basic C VS basic C++
*/

/*

*/
// classic C++
/*
#include <iostream>
//헤더파일 불러오기
using namespace std;
//std class를 미리 불러오기, std class의 내장함수를 빠르게 불러오기 위해 사용
//대표적으로 cin(입력) , cout(출력) 이 있다.
int add (int x , int y) {
    //별도 함수 지정 가능
}
/*
int main() {
//main 함수 사용
    int a;
    // 변수 선언 방식
    //int string size_t , ......같은 변수 명 선언 후 사용
    cin >> a;
    //scanf("%d" , &a);     //입력
    cout << a;
    //printf("%d" , a)      //출력
*/

    /*
    !! cin , cout 은 scanf와 printf 보다 더 많은 역할이 가능하다. !!
    */


/**
 * C / C++ 의 기본적인 구조의 차이점
 * 기본적인 구조는 C 와 큰 차이가 없음 , 객체 지정이 가능하냐 불가능 하냐의 차이
 * C++에서는 기본적으로 .h(head)를 붙일 필요가 없어졌음 , 다만 기본적인 C의 문법은 전부 이해 가능
 * 기존의 자료형에 bool 자료형까지 인식 가능
*/

/*ex
#include <iostream>
using namespace std;

int add(int x , int y) {
    return (x + y);
}

int main() {
    int a , b;
    cout << "두 정수를 입력하세요" << endl;
    cin >> a >> b;
    cout << "정답은 " << add(a , b) << " 입니다." << endl;
}
*/

/**
 * 연산자
(1) a + b/3 * 3         a + b
(2) b << 2              b = 2
(3) a != b              a is not b
(4) b % a               b / a .... last
(5) (a>b)?a:b           a > b ==> a , a << b ==> b
(6) sizeof(a)           size of a
(7) c = a++; 이후의 c 값        c = a + 1
(8) a += b; 이후의 a 값         a = a + b
(9) a & b                     a and b
(10) c = (a + b, a – b);      c opt

/**
 * 단항으로 쓰이는 연산자 << , & , * 등은 메모리를 나타내는 연산자로 쓰임
*/

/**
 * 조건문
 * if - else if - else 문
 * switch - case 문
*/

/*ex
#include <iostream>
using namespace std;
int main() {
    int score;
    cout << "점수를 입력하세요" << '\n';
    cin >> score;
    if (score < 0 || score > 100) {
        cout << "잘못 입력하셨습니다." << '\n';
        return 0;
    }
    if (score >= 90) {
        cout << 'A';
    }
    else if (score >= 80)  {
        cout << 'B';
    }
    else if (score >= 70) {
        cout << 'C';
    }
    else if (score >= 60){
        cout << 'D';
    }
    else {
        cout << 'F';
    }
    return 0;
}
*/

/**
 * 반복문
 * for , while , do - while문 사용
*/
