/*1
#include <iostream>
using namespace std;
int main() {
    int n;
    while (1) {
        cout << "Enter the size (1 to 10): ";
        cin >> n;
        if (n >= 1 && n <= 10) {
            break;
        }
    }

    int num;
    int array[10] = {0};
    cout << "Enter " <<  n << " integer(s): ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        array[i] = num;
    }
    cout << "Integer(s) in reversed order:";
    for (int i = n - 1; i >= 0; i--) {
        cout << ' ' << array[i];
    }
}
*/

/*2
#include <iostream>
using namespace std;
int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < 5; i++) {
        cout << arr[i] * 2 << ' ';
    }
    cout << '\n';
}
*/

/*3

*/

