#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef struct Student
{
	int no;
	string name;
	Student* next;
};

class LinkedList
{
private:
	Student head;
	Student* tail;

public:
	LinkedList();
	~LinkedList();

	void Insert(const Student& st);
	void Remove(int no);
	void Clear();
	void Print();
};

