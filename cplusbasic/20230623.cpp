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

template<class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T& t) : cutoff(t) {}
	bool operator() (const T& v) { return v > cutoff; }
};

void outint(int n) { cout << n << " "; }

void Show(int);
const int LIM = 20;

const int Limit = 255;

//const char* file = "guests.txt";

struct planet
{
	char name[LIM];
	double population;
	double g;
};

const char* file = "planets.dat";
inline void eatline() { while (cin.get() != '\n')continue; }

int main()
{
	/*
	//p.1304
	TooBig<int> f100(100);
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);

	cout << "������ ����Ʈ: " << endl;
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	yadayada.remove_if(f100);
	etcetera.remove_if(TooBig<int>(200));

	cout << "����� ����Ʈ: " << endl;
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	//p.1318
	int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);

	cout << "�������� ����Ʈ�� ���� : \n\n\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;
	cout << endl;

	la.remove(4);
	cout << "remove() �ż��带 ����� �� : \n\n";
	cout << "la :\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;
	cout << endl;

	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 1);
	cout << "remove() �Լ��� ����� �� : \n\n";
	cout << "lb :\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;
	cout << endl;

	lb.erase(last, lb.end());
	cout << "erase() �ż��带 ����� �� : \n\n";
	cout << "lb :\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;
	cout << endl;

	//p.1362
	const char* state1 = "Florida";
	const char* state2 = "Kansas";
	const char* state3 = "Euphoria";
	int len = strlen(state2);

	cout << "���� �ε��� ���� : " << endl;
	int i;
	for (i = 0; i <= len; i++)
	{
		cout.write(state2, i);
		cout << endl;
	}

	cout << "���� �ε��� ���� : " << endl;
	for (i = len; i > 0; i--) cout.write(state2, i) << endl;

	cout << "���ڿ� ���� �ʰ� : " << endl;

	cout.write(state2, len + 5) << endl;


	//p. 1380
	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.setf(ios_base::showpos);
	cout.setf(ios_base::showpoint);
	cout.precision(3);

	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);


	cout  << "���� ���� : " << endl << endl;
	long n;
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	cout.setf(ios_base::internal, ios_base::adjustfield);
	cout.setf(old, ios_base::floatfield);

	cout << endl << "����(internal) ���� : " << endl << endl;
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	cout.setf(ios_base::right, ios_base::adjustfield);
	cout.setf(ios_base::fixed, ios_base::floatfield);

	cout << endl << "������ ���� : " << endl << endl;
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	// p.1390

	cout << "���� �Է��Ͻʽÿ�: ";
	int sum = 0;
	int input;

	while (cin >> input)
	{
		sum += input;
	}

	cout << "���������� �Է��� �� = " << input << endl;
	cout << "�հ� = " << sum << endl;

	//p.1404
	char input[Limit];

	cout << "getline()�� ó���� ���ڿ��� �Է��Ͻʽÿ� : " << endl;
	cin.getline(input, Limit, '#');
	cout << "������ ���� �Է��ϼ̽��ϴ�. : " << endl;
	cout << input << "\n1�ܰ� �Ϸ�\n";

	char ch;
	cin.get(ch);
	cout << "���� �Է� ���ڴ� " << ch << "�Դϴ�" << endl;

	if (ch != '\n') cin.ignore(Limit, '\n');

	cout << "get()�� ó���� ���ڿ��� �Է��Ͻʽÿ� : " << endl;
	cin.get(input, Limit, '#');
	cout << "������ ���� �Է��ϼ̽��ϴ� : " << endl;
	cout << input << "\n2�ܰ� �Ϸ�\n";

	cin.get(ch);
	cout << "���� �Է� ���ڴ� " << ch << "�Դϴ�" << endl;

	//p.1416
	string filename;

	cout << "�� ������ ���� �̸��� �Է��Ͻʽÿ�: ";
	cin >> filename;

	ofstream fout(filename.c_str());

	fout << "��й�ȣ ���⿡ �����Ͻʽÿ�.\n";
	cout << "��й�ȣ�� �Է��Ͻʽÿ� : ";
	float secret;
	cin >> secret;
	fout << "������ ��й�ȣ�� " << secret << "�Դϴ�." << endl;

	fout.close();

	ifstream fin(filename.c_str());
	cout << filename << " ������ ������ ������ �����ϴ� : " << endl;
	char ch;
	while (fin.get(ch)) cout << ch;
	cout << "���α׷��� �����մϴ�." << endl;
	fin.close();

	//p. 1426
	cout << endl;

	char ch;

	ifstream fin;
	fin.open(file);

	if (fin.is_open())
	{
		cout << file << " ������ ���� ������ ������ �����ϴ�: " << endl;
		while (fin.get(ch)) cout << ch;
		fin.close();
	}

	ofstream fout(file, ios_base::out | ios_base::app);

	if (!fout.is_open())
	{
		cerr << "����� ���� " << file << " ������ �� �� �����ϴ�." << endl;
		exit(EXIT_FAILURE);
	}

	cout << "���ο� �մ� �̸����� �Է��Ͻʽÿ� (�������� �� �� �Է�) : " << endl;
	string name;
	while (getline(cin, name) && name.size() > 0)
		fout << name << endl;

	fout.close();

	fin.clear();
	fin.open(file);
	if (fin.is_open())
	{
		cout << file << " ������ ������ ������ ������ �����ϴ� :" << endl;
		while (fin.get(ch)) cout << ch;
		fin.close();
	}

	cout << "���α׷��� �����մϴ�." << endl;
	*/

	planet pl;
	cout << fixed << right;

	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary); // binary file
	//NOTE: some systems don't accept the ios_base::binary mode
	if (fin.is_open())
	{
		cout << file << " ������ ���� ������ ������ �����ϴ� :" << "\n";
		while (fin.read((char*)&pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}
	// add new data
	ofstream fout(file,
		ios_base::out | ios_base::app | ios_base::binary);
	//NOTE: some systems don't accept the ios::binary mode
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output:\n";
		exit(EXIT_FAILURE);
	}
	cout << "Enter planet name (enter a blank line to quit):\n";
	cin.get(pl.name, 20);
	while (pl.name[0] != '\0')
	{
		eatline();
		cout << "Enter planetary population: ";
		cin >> pl.population;
		cout << "Enter planet's acceleration of gravity: ";
		cin >> pl.g;
		eatline();
		fout.write((char*)&pl, sizeof pl);
		cout << "Enter planet name (enter a blank line "
			"to quit):\n";
		cin.get(pl.name, 20);
	}
	fout.close();
	// show revised file
	fin.clear(); // not required for some implementations, but won't hurt
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin.read((char*)&pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}
	cout << "Done.\n";

	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);

	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);
		cout << file << " ������ ���� ������ ������ �����ϴ� :" << endl;

		while (finout.read((char*)&pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}

		if (finout.eof()) finout.clear();
		else
		{
			cerr << file << " ������ �дٰ� ���� �߻�" << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " ������ �� �� �����ϴ�. ����." << endl;
		exit(EXIT_FAILURE);
	}

	cout << "������ ���ڵ� ��ȣ�� �Է��Ͻʽÿ� : ";
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "�߸��� ���ڵ� ��ȣ�Դϴ�. ����." << endl;
		exit(EXIT_FAILURE);
	}

	streampos place = rec * sizeof pl;
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "���ڵ带 ã�ٰ� ���� �߻�.";
		exit(EXIT_FAILURE);
	}

	finout.read((char*)&pl, sizeof pl);

	cout << "���� ���ڵ��� ���� : " << endl;

	cout << rec << ": " << setw(LIM) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;

	if (finout.eof()) finout.clear();

	cout << "�༺�� �̸��� �Է��Ͻʽÿ� : ";
	cin.get(pl.name, LIM);
	eatline();
	cout << "�༺�� �α��� �Է��Ͻʽÿ� : ";
	cin >> pl.population;
	cout << "�༺�� �߷°��ӵ��� �Է��Ͻʽÿ� : ";
	cin >> pl.g;

	finout.seekp(place);
	finout.write((char*)&pl, sizeof pl) << flush;

	if (finout.fail())
	{
		cerr << "���ٰ� ���� �߻�" << endl;
		exit(EXIT_FAILURE);
	}

	ct = 0;
	finout.seekg(0);
	cout << file << "������ ������ ������ ������ �����ϴ�." << endl;

	while (finout.read((char*)&pl, sizeof pl))
	{
		cout << ct++ << ": " << setw(LIM) << pl.name << ": "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}

	finout.close();
	cout << "���α׷��� �����մϴ�." << endl;
}

void Show(int v)
{
	cout << v << ' ';
}