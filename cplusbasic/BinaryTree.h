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
	Node* left;
	Node* right;
};

class BinaryTree
{
private:
	Node* root;

public:
	BinaryTree();
	~BinaryTree();

	void Insert(const Student& st);
	void Remove(int no);
	void Clear();
	void Print(Node* node);
	Node* GetRoot();
};

