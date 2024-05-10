/**
 * structure (구조체)
 * 기존의 C의 구조체 개념과 동일하다. 객체 언어인 C++은 굳이 필요 없지만 C와의 호환성을 위해 남겨두었다.
 * 
 * 구조체 객체를 생성 가능하고 struct 선언문이 굳이 필요하지 않게 되었다.
*/

/* 예제
#include <iostream>
using namespace std;
struct StructCircle {                 //      struct도 class와 동일한 수행이 가능하다.
    private:
        int radius;
    public:
        StructCircle(int r) {
            radius = r;
        }
        double getArea();
};

double StructCircle ::getArea() {
    return 3.14 * radius *radius;
}
int main() {
    StructCircle Waffle(3);
    cout << "면적은 " << Waffle.getArea() << "입니다" << '\n';
}
*/

/**
 * 바람직한 C++ 작성법

 * class마다 분리하여 저장
 *    ->  class 수정이나 재사용, 선언할 때도 용이하다. 추후에 구현하기 위한 수정이 매우 편하다.

 * main 로직이 있는 파일과 호출이 필요한 다른 함수들을 모아둔 파일을 분리 저장
*/

//헤더 분리 실습파일 참조