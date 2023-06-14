#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "20230609_Q2_vector.h"

int main()
{
	cVector3 u(-1, 3, 2);
	cVector3 v(3, -4, 1);

	cout << "1. 연산" << endl;
	cout << "a + v = " << u + v << endl;
	cout << "u - v = " << u - v << endl;

	cVector3 temp1 = 3 * u;
	cVector3 temp2 = 2 * v;

	cout << "3u + 2v = " << temp1 + temp2 << endl;

	temp1 = -2 * u;

	cout << "-2u + v = " << temp1 + v << endl;

	cout << endl << "2. u 정규화 : " << u.Normalize() << endl;
	cout << "   v 정규화 : " << v.Normalize() << endl;;

	cout << endl << "3. 두 벡터 사이의 각" << endl;
	

	v.Reset(1, 1, 1);
	u.Reset(2, 3, 4);

	cout << "u" << u << "와 v" << v << " = " << u.Angle(v) << endl;

	
	v.Reset(1, 1, 0);
	u.Reset(-2, 2, 0);
	cout << "u" << u << "와 v" << v << " = " << u.Angle(v) << endl;

	v.Reset(-1,-1, -1);
	u.Reset(3, 1, 0);
	cout << "u" << u << "와 v" << v << " = " << u.Angle(v) << endl;

	v.Reset(0, 1, 3);
	u.Reset(5, 1, 0);
	cout << endl << "4. 삼각형에 수직인 벡터" << endl;
	
	cout << "n" << v.Cross(u) << endl;

	

}