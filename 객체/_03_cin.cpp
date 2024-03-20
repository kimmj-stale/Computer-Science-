/**
 * string class
 * 문자열 관련 함수가 내장된 header이다.
 * 문자열 크기에 제약이 없음 , 객체 지향적이고 문자열 크기에 따라 buffer를 자동적으로 조절한다.
*/

/*
#include <iostream>
#include<string>
using namespace std;
int main() {
    string sent("Hello World!");
    string start("C++");
    string end;

    cout << "what lang do you use" << '\n';
    getline(cin , end);         ->         
    if (end == start) cout << "correct";
    else cout << "incorrect";
}
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s = "hello";
    string ans = strcpy(s);
    cout << ans;
}