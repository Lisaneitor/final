#pragma once
#include "Pulpo.h"
#include "Tentaculos.h"
#include "Pez.h"
#include "Nivel.h"
#include <vector>
using namespace std;
class Costa :
    public Nivel
{
private:
    Pulpo* objP;
    vector<Base*> arrPz;
    vector<Base*> arrTenta;
    vector<Base*> arrP;
    string nombre_archivo_tenta;
    string nombre_archivo_pulpo;
public:
    Costa();
    ~Costa();
    void Dibujar_Enemigos(Graphics^ g, Bitmap^ bmpTenta, Bitmap^ bmpCabeza);
    void Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp);
    bool Colision_Pulpo();
    bool Colision_PowerUp();
    void Dibujar_Kirby(Graphics^ g, Bitmap^ bmp);
    // NOse porque esta mal 
    void Insertar_Enemigos(Graphics^ g, Bitmap^ bmp, Bitmap^ bmpTenta);
    void Insertar_PowerUp(Graphics^ g, Bitmap^ bmpPez);
    System::String^ retornar_nombre_archivo_pulpo();
    System::String^ retornar_nombre_archivo_tenta();
};

