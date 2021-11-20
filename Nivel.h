#pragma once
#include "Kirby.h"
#include "Basura.h"
#include <vector>
using namespace std;

class Nivel
{
protected:
	bool esFin;
	bool esGanador;
	int contador;
	bool rapidez;
	bool pausa;
	// Tiempo inicio de la aplicacion
	time_t time_init_app;
	// Tiempo de rapidez aumentada
	time_t time_rapidez;
	// Tiempo de pausa por congelamiento
	time_t time_pausa;
	// Tiempo para que aparezcan enemigos
	time_t time_enemigos;
	// Tiempo para que aparezcan power ups
	time_t time_powerup;
	// Tiempo para el fuegito
	time_t time_fuegito;
	// Tiempo para la basura
	time_t time_basura;

	Kirby* objK;
	vector<Base*> arrB;
public:
	Nivel();
	~Nivel();
	void Desplazar(dir mover);
	// El virtual de Kirby puede que cambie
	bool Colision_Basura();
	virtual bool Colision_Enemigos();
	virtual bool Colision_PowerUp();
	virtual void Dibujar_Kirby(Graphics^ g, Bitmap^ bmp);
	virtual void Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp);
	void Insertar_Basura(Graphics^ g, Bitmap^ bmp);
	virtual void Insertar_Enemigos();
	void Dibujar_Basura(Graphics^ g, Bitmap^ bmp);
	bool getFin();
	bool getGanador();
	int getTiempo();
	int getVidas();
	int getContador();
	void Resumen(Graphics^ g);
};
