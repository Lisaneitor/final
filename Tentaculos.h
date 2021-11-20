#pragma once
#include "Base.h"
class Tentaculos :
    public Base
{
private:
public:
    Tentaculos();
    ~Tentaculos();
    void Mover(Graphics^ g);
    Tentaculos(int _x, int _y);
};

