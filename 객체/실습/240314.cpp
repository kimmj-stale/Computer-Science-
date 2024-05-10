/*
조교님 : 김민승
창조관 259호 , 14:00 ~ 18:00(화/목 만 가능)
kms903@yonsei.ac.kr
*/

/*
#include <iostream>
using namespace std;
int main(void) {
    int hour , pay;
    double sum1 = 0.00 , sum2 = 0.00;
    cout << "업무 시간을 입력하세요 = ";
    cin >> hour;
    cout << "시간당 급여를 입력하세요 = ";
    cin >> pay;
    if (hour > 40) {
        sum1 += hour * pay;
        sum2 += (hour - 40) * (pay * 0.3);
    }
    else {
        sum1 = pay * hour;
    }
    cout << "일반 급여 = " << sum1 << '\n' << "초과 근무에 대한 급여 = " << sum2 <<'\n' << "전체 급여 = " << (double) sum1 + sum2 << '\n';
}
*/

/*
#include <iostream>
using namespace std;
int main(void) {
    int score;
    do
    {
        cout << "0~100점의 범위에 있는 정수를 입력하세요: ";
        cin >> score;
    } while (score > 100 || score < 0);
    switch (score / 10)
    {
    case 10:
        cout << "학점 = " << 'A' << '\n';
        break;

    case 9:
        cout << "학점 = " << 'A' << '\n';
        break;

    case 8:
        cout << "학점 = " << 'B' << '\n';
        break;

    case 7:
        cout << "학점 = " << 'C' << '\n';
        break;

    case 6:
        cout << "학점 = " << 'D' << '\n';
        break;

    default:
        cout << "학점 = " << 'F' << '\n';
        break;
    }
}
*/

/*
#include <iostream>
using namespace std;
int main() {
    int column , row;
    cout << "행의 수를 입력하세요: ";
    cin >> column;
    cout << "열의 수를 입력하세요: ";
    cin >> row;
    for (int i = 1; i <= column; i++) {
        for (int j = i; j <= i + row - 1; j++) {
            cout << j;
        }
        cout << '\n';
    }
}
*/
