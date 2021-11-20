#pragma once
#include "Nivel.h"
#include "Condor.h"
#include "Granizo.h"
#include "Cushuro.h"
#include <vector>
using namespace std;
class Sierra :
    public Nivel
{
private:
    Condor* objC;
    vector<Base*> arrGr;
    vector<Base*> arrCsh;
    string nombre_archivo_granizo;
    string nombre_archivo_cushuro;
public:
    Sierra();
    ~Sierra();
    bool Colision_Enemigos();
    bool Colision_PowerUp();
    void Insertar_Enemigos();
    void Insertar_PowerUp(Graphics^ g, Bitmap^ bmp);
    void Dibujar_Kirby(Graphics^ g, Bitmap^ bmp, Bitmap^ bmpCong);
    void Dibujar_Congelado(Graphics^ g, Bitmap^ bmp);
    void Dibujar_Enemigos(Graphics^ g, Bitmap^ bmpGr, Bitmap^ bmpC);
    void Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp);
    System::String^ retornar_nombre_archivo_granizo();
    System::String^ retornar_nombre_archivo_cushuro();
};

