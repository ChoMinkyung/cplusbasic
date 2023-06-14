#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "20230609_Q2_vector.h"

int main()
{
	double x, y, z;
	
	cout << "V1 (x,y,z) : ";
	cin >> x >> y >> z;
	cVector3 v1(x, y, z);

	cout << "V2 (x,y,z) : ";
	cin >> x >> y >> z;
	cVector3 v2(x, y, z);

	cout << endl;
	cout << "V1 : " << v1 << endl;
	cout << "V2 : " << v2 << endl;

	cout << endl;
	cout << "V1 length : " << v1.length() << endl;
	cout << "V2 length : " << v2.length() << endl;

	cout << endl;
	cout << "V1 & V2 angle : " << v1.Angle(v2) << endl;

	cout << endl;
	cout << "V1 dot V2 : " << v1.Dot(v2) << endl;
	cout << "V1 Cross V2 : " << v1.Cross(v2) << endl;


	cout << endl;
	cVector3 v3 = v1 + v2;
	cout << "V1 : " << v1 << endl;
	cout << "V2 : " << v2 << endl;
	cout << "V3 = V1 + V2 : " << v3 << endl;

	cout << endl;
	v3 = v1 - v2;
	cout << "V1 : " << v1 << endl;
	cout << "V2 : " << v2 << endl;
	cout << "V3 = V1 - V2 : " << v3 << endl;

	cout << endl;
	v3 = v1 * 3;
	cout << "V1 * 3 : " << v3 << endl;

	cout << endl;
	v3 = v2 / 2;
	cout << "V2 / 2 : " << v3 << endl;

	cout << endl;
	cout << "V1 norm : " << v1.Normalize() << endl;
	cout << "V2 norm : " << v2.Normalize() << endl;


}