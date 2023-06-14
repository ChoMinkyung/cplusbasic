#pragma once
//p.681
#include<string>
using namespace std;

class Stock
{
private:
	string company;
	int shares;
	double share_val;
	double total_val;
	//void set_tot() { total_val = shares * share_val; }
};

