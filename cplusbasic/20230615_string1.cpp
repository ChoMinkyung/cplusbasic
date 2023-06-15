#define _CRT_SECURE_NO_WARNINGS


#include "20230615_string1.h"
#include <string>
int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
}



String::String(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;
}

String& String::operator=(const String& st)
{
	if (this == &st) return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}


bool operator<(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is) st = temp;
	while (is && is.get() != '\n') continue;
	return is;
}

String& String::operator+(const String& st)
{
	char* temp = new char[len + 1];
	strcpy(temp, str);

	len += st.len;
	str = new char[len + 1];
	strcpy(str, temp);
	strcat(str, st.str);
	return *this;
}

String& String::operator+(const char* s)
{
	char* temp = new char[len + 1];
	strcpy(temp, str);

	len += strlen(s);
	str = new char[len + 1];
	strcpy(str, temp);
	strcat(str, s);
	return *this;
}

String operator+(const char* s, const String& st)
{
	int len = st.len + strlen(s);
	char *str = new char[len + 1];
	strcpy(str, s);
	strcat(str, st.str);
	String result(str);
	//char* result = String::String(str);

	return result;
}

void String::stringup()
{

	for (int i = 0; i < len; i++)
	{
		if (str[i] <= 'z' && str[i]>='a') str[i] -= 32;
	}
}

void String::stringlow()
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] < 'Z' && str[i]>'A') str[i] += 32;
	}
}


int String::has(const char s)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == s) count++;
	}

	return count;
}