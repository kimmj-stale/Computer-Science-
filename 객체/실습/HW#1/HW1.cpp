//코드 출력 결과 스크린샷 찍어서 같이 업로드

#include <iostream>
#include <string>

using namespace std;

class Bank
{
private:
    string name;
    string account;
    string pwd;
    int num;
    int my_money = 0;
public:
    Bank(string n , string a , string p);
    int money() {return this -> my_money;}
    bool check(string acc , string pass);
    void person();
    void in(int money);
    void out(int money);
};

Bank::Bank(string n , string a , string p) {
    name = n;
    account = a;
    pwd = p;
}

bool Bank :: check(string acc , string pass) {
    if (acc != this -> account || pass != this -> pwd) {
        return false;
    }
    else {
        return true;
    }
}

void Bank :: person() {
    cout << "회원명 : " << name << endl;
    cout << "계좌번호 : " << account << endl;
    cout << "비밀번호 : ";
    for (int i = 0; i < pwd.size(); i++) {
        cout << '*';
    }
    cout << endl;
}
//입금 구현부
void Bank :: in(int money) {
    this -> my_money += money;
    cout << "잔액 : " << my_money << "원" << '\n';
}
//출금 구현부
void Bank :: out(int money) {
    if (my_money < money) {
        cout << "잔액이 부족합니다. 잔액을 확인해 주세요." << '\n';
        cout << "잔액 : " << my_money << "원" << '\n';
    }
    else {
        this -> my_money -= money;
        cout << "계좌에 남은 잔액 : " << my_money << "원" << '\n';
    }
}

int main() {
    int input_number , money_in , money_out;
    string usr_name, usr_account , usr_pwd;
    bool close_tmp = true;

    Bank bk("김연세" , "111-1111" , "1234");
    while (close_tmp == true) {
        cout << "************************" << '\n';
        cout << "** 은행 관리 프로그램 **" << '\n';
        cout << "************************" << '\n';

        cout << "1. 회원 보기   2. 입금     3. 출금     4. 잔액     5.  나가기" << '\n';

        cout << "번호 입력 : ";
        cin >> input_number;

        switch (input_number)
        {
        case 1:
            bk.person();
            break;

        case 2:
            cout << "입금할 계좌를 입력해주세요 : ";
            cin >> usr_account;
            cout << "비밀번호를 입력해주세요 : ";
            cin >> usr_pwd;

            if (bk.check(usr_account , usr_pwd) == true) {
                cout << "입금할 금액 : ";
                cin >> money_in;
                bk.in(money_in);
            }
            else {
                cout << "계좌 혹은 비밀번호를 잘못 입력하셨습니다." << '\n';
                cout << "처음 화면으로 돌아갑니다. "<< '\n';
            }
            break;

        case 3:
            cout << "출금할 계좌를 입력해주세요 : ";
            cin >> usr_account;
            cout << "비밀번호를 입력해주세요 : ";
            cin >> usr_pwd;

            if (bk.check(usr_account , usr_pwd) == true) {
                cout << "출금할 금액 : ";
                cin >> money_out;
                bk.out(money_out);
            }
            else {
                cout << "계좌 혹은 비밀번호를 잘못 입력하셨습니다." << '\n';
                cout << "처음 화면으로 돌아갑니다." << '\n';
            }
            break;

        case 4:
            cout <<"계좌에 보유한 잔액 " << bk.money() << "원" << '\n';
            break;

        case 5: 
            cout << "프로그램을 종료합니다. 이용해주셔서 감사합니다.";
            close_tmp = false;
            break;

        default:
            cout << "잘못 입력하셨습니다. 다시 한번 입력해주세요" << '\n';
            break;
        }
        cout << '\n';
    }
}