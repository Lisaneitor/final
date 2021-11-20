#pragma once
#include "Nivel.h"
#include "Pirana.h" 
#include "Anaconda.h"
#include "Arana.h"
#include "Fruta.h"
#include <vector>

using namespace std;
class Selva :
    public Nivel
{
private:
    vector<Base*> arrAna;
    vector<Base*> arrAr;
    vector<Base*> arrFr;
    Pirana* objP;
    string nombre_archivo_anaconda;
    string nombre_archivo_pirana;
    string nombre_archivo_arana;
    string nombre_archivo_fruta;
    int reCol, reFil;
public:
    Selva();
    ~Selva();
    bool Colision_Enemigos();
    void Colision_Bala();
    bool Colision_PowerUp();
    void Dibujar_Kirby(Graphics^ g, Bitmap^ bmp, Bitmap^ fire, Bitmap^ bala);
    void Dibujar_Enemigos(Graphics^ g, Bitmap^ bmpAna, Bitmap^ bmpAr, Bitmap^ bmpPir);
    void Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp);
    void Insertar_Enemigos(Graphics^ g, Bitmap^ bmp);
    void Insertar_PowerUp(Graphics^ g, Bitmap^ bmp);
    void Dibujar_Fuego(Graphics^ g, Bitmap^ fire, Bitmap^ bala, Bitmap^ bmp);
    void Disparar(Bitmap^ fire);
    System::String^ retornar_nombre_archivo_anaconda();
    System::String^ retornar_nombre_archivo_pirana();
    System::String^ retornar_nombre_archivo_arana();
    System::String^ retornar_nombre_archivo_fruta();

};
