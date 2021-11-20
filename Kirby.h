#pragma once
#include "Base.h"
#include "Bala.h"
class Kirby :
    public Base
{
private:
    int vidas;
    dir hor_dir;
    vector<Base*>balas;
public:
    Kirby();
    Kirby(int _x, int _y, int _w, int _h, bool nada);
    void Mover(Graphics^ g);
    ~Kirby();
    int getVidas();
    void setVidas();
    void Dibujar_Congelado(Graphics^ g, Bitmap^ bmp);
    //power up de kirby fuego
    void Dibujar_Fuego(Graphics^ g, Bitmap^ bmp);
    void Disparar(Bitmap^ kirbyfuego);
    void Mover_Bala(Graphics^ g, Bitmap^ bmp_bala);
    int get_cant_balas();
    Base* get_bala_pos(int indice);
};
