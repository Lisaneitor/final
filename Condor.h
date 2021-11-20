#pragma once
#include "Base.h"
class Condor :
    public Base
{
public:
    Condor();
    Condor(int _x, int _y, int _w, int _h);
    void Mover(Graphics^ g);
    ~Condor();
};
