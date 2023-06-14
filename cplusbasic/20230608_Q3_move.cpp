#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include "20230608_Q3_move.h"

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    cout << "x : " << x << " y : " << y << endl;
}

Move Move::add(const Move& m) const
{
    return Move(x + m.x, y+m.y);
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
