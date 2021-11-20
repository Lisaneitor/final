#pragma once
#include "Base.h"
class Pez :
    public Base
{
public:
	Pez();
	Pez(int _x, int _y, int _h, int _w);
	~Pez();
	void Mover(Graphics^ g);
};
