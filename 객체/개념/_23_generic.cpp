/**
 * generic function(제너릭 함수)
 * 함수나 클래스를 일반화시키고, 매개 변수 타입을 지정하여 틀에서 찍어 내듯이 함수나 클래스 코드를 생산하는 기법
 * template 키워드로 함수나 클래스 선언
- 변수나 매개 변수의 타입만 다르고, 코드 부분이 동일한 함수를 일반화시킴
*/

/*
template <class T>  //  generic type T를 선언
void myswap(T & a, T & b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

//  후에 선언 시 T = int or  double or ..... 로 선언해도 상관 없음
*/

/*1
#include <iostream>
using namespace std;

template <class T>
T bigger(T a, T b) { // 두 개의 매개 변수를 비교하여 큰 값을 리턴
    if(a > b)
        return a;
    else
        return b;
}
int main() {
    int a=20, b=50;
    char c='a', d='z';
    //선언자가 int 에서 char로 변경 됨
    cout << "bigger(20, 50)의 결과는 " << bigger(a, b) << endl;
    cout << "bigger('a', 'z')의 결과는 " << bigger(c, d) << endl;
}
*/

/*2
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 1) {
        this -> radius = radius;
    }
    int getRadius() {return radius;}
};

template <class T>
void myswap(T& a , T& b) {  //  T로 선언하여 함수에 선언자 범용성을 부여
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a=4, b=5;
    myswap(a, b);
    cout << "a=" << a << ", " << "b=" << b << endl;
    
    double c=0.3, d=12.5;
    myswap(c, d);
    cout << "c=" << c << ", " << "d=" << d << endl;
    
    Circle donut(5), pizza(20);
    myswap(donut, pizza);
    cout << "donut반지름=" << donut.getRadius() << ", ";
    cout << "pizza반지름=" << pizza.getRadius()<< endl;
}
*/

/**
 * 템플릿의 장점
 * - 높은 소프트웨어 생산성 & 유용성
 * 단점
 * - 컴파일 오류 메시지 빈약으로 디버깅에 어려움이 발생
*/

/**
 * generic class (제네릭 클래스)
 * 제네릭 함수와 동일한 쓰임새
*/

/*
#include <iostream>
using namespace std;

template <class T>
class MyStack {
    int tos;// top of stack
    T data [100]; // T 타입의 배열. 스택의 크기는 100
public:
    MyStack();
    void push(T element); // element를 data [] 배열에 삽입
    T pop(); // 스택의 탑에 있는 데이터를 data[] 배열에서 리턴
};

template <class T>
MyStack<T>::MyStack() { // 생성자
    tos = -1; // 스택은 비어 있음
}
template <class T>
void MyStack<T>::push(T element) {
    if(tos == 99) {
        cout << "stack full";
        return;
    }
    tos++;
    data[tos] = element;
}

template <class T>
T MyStack<T>::pop() {
    T retData;
    if(tos == -1) {
        cout << "stack empty";
        return 0; // 오류 표시
    }
    retData = data[tos--];
    return retData;
}

int main() {
    MyStack<int> iStack; // int 만 저장하는 스택
    iStack.push(3);
    cout << iStack.pop() << endl;

    MyStack<double> dStack; // double 만 저장하는 스택
    dStack.push(3.5);
    cout << dStack.pop() << endl;

    MyStack<char> *p = new MyStack<char>(); // char만 저장하는 스택
    p->push('a');
    cout << p->pop() << endl;
    delete p;
}
*/

/**
 * iterator (반복자)
 * 컨테이너의 원소를 가리키는 포인터로 사용
 * iterator 변수를 지정하여 컨테이너의 해당 원소에 대한 포인터
*/

/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v; // 정수 벡터 생성
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int>::iterator it; // 벡터 v의 원소에 대한 포인터 it 선언

    for(it=v.begin(); it != v.end(); it++) { // iterator를 이용하여 모든 원소 탐색
        int n = *it; // it가 가리키는 원소 값 리턴
        n = n*2; // 곱하기 2
        *it = n; // it가 가리키는 원소에 값 쓰기
    }
    for(it=v.begin(); it != v.end(); it++) // 벡터 v의 모든 원소 출력
        cout << *it << ' ';
        cout << endl;
    }
}
*/

/**
 * map (맵)
 * java의 map<> table = new ~의 쓰임새와 동일하다
 * key - value의 한 쌍으로 묶인다
*/

/**
 * lambda function (람다식)
 * 수학 함수로 정의된 함수를 단순하게 표현하는 방식
 * [식에서 사용하려는 변수 목록](매개 변수) -> 리턴 타입{식의 함수 코드}
*/

/* 람다식 예제
f(x , y) = x + y
== (x , y) -> x + y
== (x , y) -> x + y(2 , 3) ->> 5가 출력
*/