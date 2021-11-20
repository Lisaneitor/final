#pragma once
#include "Base.h"
class Cushuro :
    public Base
{
public:
    Cushuro();
    Cushuro(int _x, int _y, int _w, int _h);
    void Mover(Graphics^ g);
    ~Cushuro();
};
