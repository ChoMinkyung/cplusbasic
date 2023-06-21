
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

#include "20230619_Q2_QueueTp.h"
#include "20230619_worker0.h"

const int LIM = 4;

int main()
{
	Queue<const Worker*> worker(LIM);

	Waiter bob("홍길동", 314L, 5);
	Singer bev("조수미", 522L, 3);

	Waiter w_temp;
	Singer s_temp;

	worker.enqueue(&bob);
	worker.enqueue(&bev);
	worker.enqueue(&w_temp);
	worker.enqueue(&s_temp);


	int i;
	for (i = 2; i < LIM; i++)w_temp->Set();

	for (i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		cout << endl;
	}
	return 0;

}