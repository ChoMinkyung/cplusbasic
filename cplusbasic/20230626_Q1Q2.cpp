#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <set>
#include <map>
#include <fstream>
#include <iomanip>
using namespace std;

void encoding();
void decoding();

int password = 10;

int main()
{
	encoding();
	decoding();
}

void encoding()
{
	char sourceFile[100];
	char desFile[100];

	cout << "Source ���� �̸��� �Է��ϼ��� : ";
	cin.getline(sourceFile, 100);
	cout << "destination ���� �̸��� �Է��ϼ��� : ";
	cin.getline(desFile, 100);

	int c;
	ifstream fin(sourceFile, ios_base::in | ios_base::binary);

	ofstream fout(desFile, ios_base::out | ios_base::binary);


	if (!fout.is_open())
	{
		cerr << "����� ���� " << desFile << " ������ �� �� �����ϴ�." << endl;
		exit(EXIT_FAILURE);
	}

	if (fin.is_open())
	{
		cout << sourceFile << " Encoding... " << endl;

		while ((c = fin.get()) != EOF)
		{
			fout.put(c + password);
		}
	}

	cout << "Encoding Done" << endl;

	fin.close();
	fout.close();
}

void decoding()
{
	char sourceFile[100];
	char desFile[100];

	cout << "Source ���� �̸��� �Է��ϼ��� : ";
	cin.getline(sourceFile, 100);
	cout << "destination ���� �̸��� �Է��ϼ��� : ";
	cin.getline(desFile, 100);

	int c;
	ifstream fin(sourceFile, ios_base::in | ios_base::binary);

	ofstream fout(desFile, ios_base::out | ios_base::binary);


	if (!fout.is_open())
	{
		cerr << "����� ���� " << desFile << " ������ �� �� �����ϴ�." << endl;
		exit(EXIT_FAILURE);
	}

	if (fin.is_open())
	{
		cout << sourceFile << " Dncoding... " << endl;

		while ((c = fin.get()) != EOF)
		{
			fout.put((char)(c - password));
		}
	}

	cout << "Dncoding Done" << endl;

	fin.close();
	fout.close();
}