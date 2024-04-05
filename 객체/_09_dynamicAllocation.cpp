/**
 * 동적 할당
   필요 할당량이 정해지지 않은 경우 사용하는 메모리 할당 방법
   C언어에선 보통 malloc , free로 메모리 할당
   C++에선 보통 new , delete를 사용

    new  = malloc // 힙 메모리에서 배열 할당을 위한 메모리 할당
    delete = free // 힙 메모리로 할당 받았던 메모리 반환
   
 * 
*/

/*
#include <iostream>
using namespace std;
int main() {
   int *p;
   p = new int;
   if (!p) {
      cout << "error" << '\n';
      return 0;
   }
   *p = 5;
   int n = *p;
   cout << *p << '\n' << n << '\n';
}
*/

/*
#include <iostream>
using namespace std;
int main() {
   int n;
   cout << "입력할 정수의 개수는?";
   cin >> n;
   int *arr = new int[n];
   if (*arr) {
      cout << "메모리를 할당할 수 없습니다.";
      return 0;
   }
   for (int i = 0; i < n; i++) {
      cout << i + 1 <<  "번째 정수: ";
      cin >> arr[i];
   }
   int sum = 0;
   for (int i = 0; i < n; i++) {
      sum += arr[i];
   }
   cout << "평균 = " << sum / n;
   delete [] arr;
}*/

/*
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
class Circle {
   int radius;
   public:  
      Circle();
      Circle(int r);
      ~Circle();
   void setRadius(int r) { radius = r; }
   double getArea() { return 3.14*radius*radius; }
};
Circle::Circle() {
   radius = 1;
   cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r) {
   radius = r;
   cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
   cout << "소멸자 실행 radius = " << radius << endl;
}
int main() {
   Circle *p , *q;
   p = new Circle;
   q = new Circle(30);

   cout << p -> getArea() << '\n';
   cout << q -> getArea() << '\n';

   delete p;
   delete q;
}
*/

/*
#include <iostream>
using namespace std;
class Circle {
   int radius;
   public:  
      Circle();
      Circle(int r);
      ~Circle();
   void setRadius(int r) { radius = r; }
   double getArea() { return 3.14*radius*radius; }
};
Circle::Circle() {
   radius = 1;
   cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r) {
   radius = r;
   cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
   cout << "소멸자 실행 radius = " << radius << endl;
}
int main() {
   int radius;
   while(true) {
      cout << "정수 반지름 입력(음수이면 종료)>> ";
      cin >> radius;
      if(radius < 0) break; // 음수가 입력되어 종료한다.
      Circle *p = new Circle(radius); // 동적 객체 생성
      cout << "원의 면적은 " << p->getArea() << endl;
      delete p; // 객체 반환
   }
}
*/

/*
#include <iostream>
using namespace std;
class Circle {
   int radius;
   public:  
      Circle();
      Circle(int r);
      ~Circle();
   void setRadius(int r) { radius = r; }
   double getArea() { return 3.14*radius*radius; }
};
Circle::Circle() {
   radius = 1;
   cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r) {
   radius = r;
   cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
   cout << "소멸자 실행 radius = " << radius << endl;
}
int main() {
   Circle *pCircle = new Circle[3];
   pCircle[0].setRadius(10);
   pCircle[1].setRadius(20);
   pCircle[2].setRadius(30);

   for (int i = 0; i < 3; i++) {
      cout << pCircle[i].getArea() << '\n';
   }
   
   for (int i = 0; i < 3; i++) {
      cout << pCircle -> getArea() << '\n';
      pCircle++;
   }
   delete [] pCircle;
}
*/
#include <iostream>
using namespace std;
class Circle {
   int radius;
   public:  
      Circle();
      Circle(int r);
      ~Circle();
   void setRadius(int r) { radius = r; }
   double getArea() { return 3.14*radius*radius; }
};
Circle::Circle() {
   radius = 1;
}
int main() {
   int n , radius;
   cout << "생성하고자 하는 원의 개수?";
   cin >> n;

   Circle *pArray = new Circle[n];
   for (int i = 0; i < n; i++) {
      cout << "원 " << i + 1 << "의 반지름은";
      cin  >> radius;
      pArray[i].setRadius(radius);
   }
   int count = 0;
   Circle *p = pArray;
   for (int i = 0; i < n; i++) {
      cout << p -> getArea() << '\n';
      if (p -> getArea() >= 100 && p -> getArea() <= 200) {
         count++;
      }
      p++;
   }
   cout << '\n' << "면적이 100에서 200 사이인 원의 개수는 " << count << '\n';
}