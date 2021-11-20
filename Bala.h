#pragma once
#include "Base.h"
class Bala :
    public Base
{
public:
    Bala();
    Bala(int _x, int _y, int _w, int _h);
    void Mover(Graphics^ g);
    ~Bala();
};

