#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
   다음을 포함하는 Cirect2D 클래스를 정의하라
   - 원의 중심을 나타내는 x, y 라는 두 개의 double 데이터 필드와 get 상수 함수.
   - double 데이터 필드 radius 와 get 상수 함수
   - (x, y) 가 (0, 0) , radius 가 1 인 기본 원을 생성하는 인수 없는 생성자
   - 지정된 x, y 와 radius 로 원을 생성하는 생성자
   - 원의 면적을 반환하는 getArea() 상수 함수
   - 원의 둘레는 반환하는 getPerimeter() 상수 함수
   - 지정된 점 (x, y) 가 생성된 원 내부에 있을 경우,
     true 를 반환하는 contains(double x, double y) 상수 함수
   - 지정된 원이 생성된 원 내부에 있을 경우
     true 를 반환하는 contains(const Circle2D& circle) 상수 함수
   - 지정된 원이 생성된 원과 중첩되는 경우,
     true를 반환하는 overlaps(const Circle2D& circle) 상수 함수
   - 클래스에 대한 UML 다이어그램을 그리고 클래스를 구현하라.

   Circle2D 객체 c1(2, 2, 5.5), c2(2, 2, 5.5), c3(4, 5, 10.5) 를 생성하고
   c1의 면적과 둘레, c1.contains(3, 3), c1.contains(c2), c1.overlaps(c3) 의 결과를
   화면에 출력하는 프로그램을 작성하라
*/

#include "20230612_Q2_Circle2D.h"

int main()
{
    Circle2D c1(2, 2, 5.5);
    Circle2D c2(2, 2, 5.5);
    Circle2D c3(4, 5, 10.5);

    cout << "c1의 중심 : (" << c1.getX() << ", " << c1.getY() << ") 반지름 : " << c1.getRadius() << endl;
    cout << "c2의 중심 : (" << c2.getX() << ", " << c2.getY() << ") 반지름 : " << c2.getRadius() << endl;
    cout << "c3의 중심 : (" << c3.getX() << ", " << c3.getY() << ") 반지름 : " << c3.getRadius() << endl;

    cout << endl;

    cout << "C1의 면적과 둘레 : " << c1.getArea() << ", " << c1.getPerimeter() << endl << endl;
    
    cout << "(3,3)은 c1 내부에 ";
    if (c1.contains(3, 3)) cout << "있습니다." << endl;
    else cout << "없습니다." << endl;

    cout << "c2는 c1 내부에 ";
    if (c1.contains(c2)) cout << "있습니다." << endl;
    else cout << "없습니다." << endl;

    cout << "c1과 c3는 ";
    if (c1.overlaps(c3)) cout << "겹칩니다." << endl;
    else cout << "겹치지 않습니다." << endl;
}