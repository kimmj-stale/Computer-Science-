/**
 * 필요한 tactic의 함수를 별도로 미리 정할 수 있다.
*/

/* 함수 선언 1
#include <iostream>
using namespace std;
int absolute_number(int n){             ->          별도 함수를 지정
    if (n > 0) {
        return n;
    }
    else {
        return -n;
    }
}
int main() {
    int a;
    cin >> a;
    cout << absolute_number(a) << '\n';
}
*/

/**
 * ADT (추상 자료형)
 * 구체적인 기능의 완성 과정을 언급하지 않고 순수하게 기능이 무엇인지를 나열하는 것 , 추상화란 시스템의 간략화 된 기술 또는 명세
 * 프로그램 / 알고리즘의 구상 단계
*/

/**
 * Recursion function(재귀함수)
 * 함수 본인을 다시 호출하는 과정
 * stack overflow가 날 때 까지 반복
*/

/* 일반적인 재귀함수
#include <iostream>
using namespace std;
void recursive(int n) {
    if (n <= 0) {
        return;                 ->          stack overflow가 나기 전에 함수 탈출문 구현
    }
    else {
        cout << "Recursive call!" << ' ' << n << '\n';
        n--;
    }
    recursive(n);               ->          함수 재귀 호출
}
int main() {
    int k;
    cin >> k;
    recursive(k);
}
*/

/*실습 - 팩토리얼 구현(점화식) - 나중에 해보기
#include <stdio.h>
int factorial(int a) {
    if (a == 0) return 1;
    else {
        return a * factorial(a - 1);    //  재귀 함수 형식으로 구현
    }
}

int main() {
    int n;
    scanf("%d" , &n);
    int ans = factorial(n);
    printf("%d" , ans);
    return 0;
}
*/

/*
// 이진 탐색 알고리즘 !!재귀 함수로 구현!!
int BSearchRecursive(int arr[], int first, int last, int target)
{
    int mid;
    if(first > last)
        return -1;

    mid = (first + last) / 2;

    if(arr[mid] == target) {        //  찾는 target이 mid 위치에 있다면 mid return
        return mid;
    }

    else if(arr[mid] > target) {    //  찾는 target이 mid의 값보다 작다면 mid의 우측 범위를 배제
        return BSearchRecursive(arr, first, mid-1, target);
    }

    else {                          //  찾는 target이 mid의 값보다 크다면 mid의 좌측 범위를 배제
        return BSearchRecursive(arr, mid+1, last, target);
    }
}
*/

/* 이진 탐색 트리 - 반복문으로 구현 
int BSearchRecursive(int arr[], int first, int last, int target) {
    int low = first;
    int high = last;
    int mid = (low + high) / 2;

    while (low < high) {
        if (arr[mid] < target) {
            low = mid + 1;
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
}
*/
