/*
#include <iostream>
using namespace std;
class Calculate
{
private:
    int n1 , n2;
    char p;
public:
    Calculate();
    int setValue(int a , int b , char c) {this -> n1 = a , this -> n2 = b , this -> p = c;}
    int calculate();
};
Calculate::Calculate() {
    n1 = 0;
    n2 = 0;
    p = ' ';
}

int Calculate::calculate()
{
    if (p == '+') {
        return n1 + n2;
    }
    else if (p == '-') {
        return n1 - n2;
    }
    else if (p == '*') {
        return n1 * n2;
    }
    else if (p == '/') {
        return n1 / n2;
    }
    else {
        return false;
    }
}
int main() {
    int a , b;
    char c;
    cout << "두 정수와 연산자를 입력하세요: ";
    cin >> a >> b >> c;
    Calculate cal;
    cal.setValue(a , b  ,c);
    if (cal.calculate() == false) {
        cout << "연산자를 잘못 입력하셨습니다." << '\n';
    }
    else {
        cout << cal.calculate() << '\n';
    }
}
*/
#include <iostream>
using namespace std;
class FruitBuyer
{
private:
    int numOfApples , myMoney;
public:
    FruitBuyer();
    int InitMembers(int num) {this -> myMoney = num;}
    int ShowBuyResult();
    int BuyApples(FruitSeller , int price);
};

FruitBuyer::FruitBuyer(/* args */)
{
}

int FruitBuyer::BuyApples(FruitSeller , int price) {
    
}

class FruitSeller
{
private:
    int numOfApples , myMoney , APPLE_PRICE;
public:
    FruitSeller();
    int InitMembers(int a , int b , );
    int SalesApples();
};

FruitSeller::FruitSeller()
{
    return numOfApples;
}



int main() {

}