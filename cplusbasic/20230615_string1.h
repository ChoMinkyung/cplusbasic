#pragma once
#include <iostream>

using namespace std;

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String(const char* s);
	String();
	String(const String& st);
	~String();

	int length() const { return len; }

	// �����ε�
	String& operator=(const String& st);
	String& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i)const;

	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);

	static int HowMany();

	// 20230615 Q1
	String& operator+(const String& st);
	String& operator+(const char * s);
	
	friend String operator+(const char * s, const String& st);

	int has(const char s);
	void stringup();
	void stringlow();

};

