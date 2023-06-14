#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
   ������ �����ϴ� Cirect2D Ŭ������ �����϶�
   - ���� �߽��� ��Ÿ���� x, y ��� �� ���� double ������ �ʵ�� get ��� �Լ�.
   - double ������ �ʵ� radius �� get ��� �Լ�
   - (x, y) �� (0, 0) , radius �� 1 �� �⺻ ���� �����ϴ� �μ� ���� ������
   - ������ x, y �� radius �� ���� �����ϴ� ������
   - ���� ������ ��ȯ�ϴ� getArea() ��� �Լ�
   - ���� �ѷ��� ��ȯ�ϴ� getPerimeter() ��� �Լ�
   - ������ �� (x, y) �� ������ �� ���ο� ���� ���,
     true �� ��ȯ�ϴ� contains(double x, double y) ��� �Լ�
   - ������ ���� ������ �� ���ο� ���� ���
     true �� ��ȯ�ϴ� contains(const Circle2D& circle) ��� �Լ�
   - ������ ���� ������ ���� ��ø�Ǵ� ���,
     true�� ��ȯ�ϴ� overlaps(const Circle2D& circle) ��� �Լ�
   - Ŭ������ ���� UML ���̾�׷��� �׸��� Ŭ������ �����϶�.

   Circle2D ��ü c1(2, 2, 5.5), c2(2, 2, 5.5), c3(4, 5, 10.5) �� �����ϰ�
   c1�� ������ �ѷ�, c1.contains(3, 3), c1.contains(c2), c1.overlaps(c3) �� �����
   ȭ�鿡 ����ϴ� ���α׷��� �ۼ��϶�
*/

#include "20230612_Q2_Circle2D.h"

int main()
{
    Circle2D c1(2, 2, 5.5);
    Circle2D c2(2, 2, 5.5);
    Circle2D c3(4, 5, 10.5);

    cout << "c1�� �߽� : (" << c1.getX() << ", " << c1.getY() << ") ������ : " << c1.getRadius() << endl;
    cout << "c2�� �߽� : (" << c2.getX() << ", " << c2.getY() << ") ������ : " << c2.getRadius() << endl;
    cout << "c3�� �߽� : (" << c3.getX() << ", " << c3.getY() << ") ������ : " << c3.getRadius() << endl;

    cout << endl;

    cout << "C1�� ������ �ѷ� : " << c1.getArea() << ", " << c1.getPerimeter() << endl << endl;
    
    cout << "(3,3)�� c1 ���ο� ";
    if (c1.contains(3, 3)) cout << "�ֽ��ϴ�." << endl;
    else cout << "�����ϴ�." << endl;

    cout << "c2�� c1 ���ο� ";
    if (c1.contains(c2)) cout << "�ֽ��ϴ�." << endl;
    else cout << "�����ϴ�." << endl;

    cout << "c1�� c3�� ";
    if (c1.overlaps(c3)) cout << "��Ĩ�ϴ�." << endl;
    else cout << "��ġ�� �ʽ��ϴ�." << endl;
}