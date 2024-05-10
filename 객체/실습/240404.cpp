/*3

*/
#include <iostream>
using namespace std;

class nton
{
public:
    nton();
    int num;
    int doubling();

};

int main() {
    int n , t;
    cout << "출력을 시작하고자 하는 범위를 입력하시오(1 to 9): ";
    cin >> n;
    while (n < 1 || n > 9 || t < 1 || t > 9) {
        cout << "출력을 시작하고자 하는 범위를 입력하시오(1 to 9): ";
        cin >> t;
    }

    nton nineArray[n][10];

    for (int i = n; i <= t; i++) {
        for (int j = 0; j < 10; j++) {
            nineArray[i][j] = i * j;
        }
    }
    for (int i = n; i < t; i++) {
        for (int j = 0; j < 10; j++) {
            cout << nineArray[i][j] << '\n';
        }
    }
}