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

void devide(const char* sourceFile, const char* desFile);
void combine(const char* sourceFile, const char* desFile);

int main()
{
	//const char* sourceFile = "rex.png";
	//const char * desFile = "dest.png";
	char sourceFile[100];
	char desFile[100];
	
	cout << "Source 파일 이름을 입력하세요 : ";
	cin.getline(sourceFile, 100);
	cout << "destination 파일 이름을 입력하세요 : ";
	cin.getline(desFile, 100);

	
	devide(sourceFile, desFile);
	combine(sourceFile, desFile);

}

void devide( const char* sourceFile, const char* desFile)
{
	int size;
	int c;
	int n = 1;
	char a = n + '0';
	string dot = ".";
	string dest_file_name = a + dot + desFile;

	cout << "사이즈를 입력하세요 : ";
	cin >> size;
	ifstream fin(sourceFile, ios_base::in | ios_base::binary);

	ofstream fout(dest_file_name, ios_base::out | ios_base::binary);

	//ofstream out()

	if (!fout.is_open())
	{
		cerr << "출력을 위해 " << dest_file_name << " 파일을 열 수 없습니다." << endl;
		exit(EXIT_FAILURE);
	}

	if (fin.is_open())
	{
		cout << sourceFile << " 파일의 현재 내용은 다음과 같습니다. : " << endl;
		int i = 0;
		while ((c = fin.get()) != EOF)
		{
			if (i > size)
			{
				i = 0;
				n++;
				cout << "\tfile : " << dest_file_name << endl;
				if (n > 9)
				{
					int nn = n / 10;
					char b = nn + '0';
					int nnn = n % 10;
					a = nnn + '0';
					dest_file_name = b;
					dest_file_name = dest_file_name + a + dot + desFile;
				}
				else
				{
					a = n + '0';
					dest_file_name = a + dot + desFile;
				}
				fout.close();
				fout.open(dest_file_name, ios_base::out | ios_base::binary);
				fout.seekp(0);
				if (!fout.is_open())
				{
					cerr << "출력을 위해 " << dest_file_name << " 파일을 열 수 없습니다." << endl;
					exit(EXIT_FAILURE);
				}
			}
			fout.put(c);
			i++;
		}
	}

	cout << "Split Done" << endl;

	fin.close();
	fout.close();
}

void combine(const char* sourceFile, const char* desFile)
{
	int n;
	cout << "파일 개수를 입력하세요 : ";
	cin >> n;
	int c;
	char a = 1 + '0';
	string dot = ".";
	string dest_file_name = a + dot + desFile;

	ifstream fin(dest_file_name, ios_base::in | ios_base::binary);
	ofstream fout("combine.png", ios_base::out | ios_base::binary);

	cout << "combine..." << endl;
	for (int i = 1; i <=n; i++)
	{
		cout << "\tfile : " << dest_file_name << endl;
		if (i > 9)
		{
			int nn = i / 10;
			char b = nn + '0';
			int nnn = i % 10;
			a = nnn + '0';
			dest_file_name = b;
			dest_file_name = dest_file_name + a + dot + desFile;
		}
		else
		{
			a = i + '0';
			dest_file_name = a + dot + desFile;
		}
		fin.close();
		fin.open(dest_file_name, ios_base::out | ios_base::binary);
		fin.seekg(0);
		while ((c = fin.get()) != EOF) fout.put(c);
	}

	cout << "Combine Done" << endl;
	fin.close();
	fout.close();
}