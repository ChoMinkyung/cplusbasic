#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef struct Student
{
	int no;
	string name;
};

typedef struct Node
{
	Student* data;
	Node* next;
};

typedef struct ChainHash
{
	int size;
	Node** first_hash;
};

class Hash
{
private:
	ChainHash *hash_table;
public:
	Hash();
	Hash(int size);
	~Hash();

	void Insert(const Student& st);
	void Remove(int no);
	void Clear();
	void Print();
	int Find(int no);

};

