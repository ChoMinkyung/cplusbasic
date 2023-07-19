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
	Student* prev;
};


class DoubleLinkedList
{
private:
	Student head;
	Student tail;

public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void Insert(const Student& st);
	void Remove(int no);
	void Clear();
	void Print();
	void ReversePrint();
};

