#pragma once
#include "Base.h"
class Pirana :
    public Base
{
private:
public:
    Pirana();
    Pirana(int _x, int _y, int _w, int _h);
    ~Pirana();
    void Mover(Graphics^ g);
};
