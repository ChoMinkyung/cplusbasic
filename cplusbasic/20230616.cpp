#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>.
#include <cstdlib>
using namespace std;

#include "20230616_tabtenn1.h"
#include "20230616_dma.h"

int main()
{
	/*
	//20230616_tabtenn1.h
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();

	if (rplayer1.HasTable()) cout << ": Ź���밡 �ִ�." << endl;
	else cout << ": Ź���밡 ����." << endl;

	player1.Name();

	if(player1.HasTable()) cout << ": Ź���밡 �ִ�." << endl;
	else cout << ": Ź���밡 ����." << endl;

	cout << "�̸� :	";
	rplayer1.Name();

	cout << "; ��ŷ: " << rplayer1.Rating() << endl;

	RatedPlayer rplayer2(1212, player1);

	cout << "�̸� :	";
	rplayer2.Name();

	cout << "; ��ŷ: " << rplayer2.Rating() << endl;
	*/

	//20230616_dma.h
	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo keys", 5);

	cout << "baseDMA ��ü�� ����Ѵ� : " << endl;
	cout << shirt << endl;

	cout << "lacksDMA ��ü�� ����Ѵ� : " << endl;
	cout << balloon << endl;

	cout << "hasDMA ��ü�� ����Ѵ� : " << endl;
	cout << map << endl;

	lacksDMA balloons(balloon);
	cout << "lacksDMA ���� ��� : " << endl;
	cout << balloons << endl;

	hasDMA map2;
	map2 = map;
	cout << "hasDMA ���� ��� : " << endl;
	cout << map2 << endl;
	return 0;
}