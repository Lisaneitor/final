#pragma once
#include "Costa.h"
#include "Sierra.h"
#include "Selva.h"
class Juego
{
private:
	Costa* nvCosta;
	Sierra* nvSierra;
	Selva* nvSelva;
	/*
	 Contador de nivel
	 Costa - 1
	 Sierra - 2
	 Selva - 3
	 */
	Kirby* objK;
	time_t time_init_app;
	int nivel;
	int contador;
public:
	Juego();
	~Juego();
	void Jugar_Costa(Graphics^ g, Bitmap^ bmpPez, Bitmap^ bmpPulpo,
		Bitmap^ bmpTenta, Bitmap^ bmpKirbyNada, Bitmap^ bmpBasura);
	void Jugar_Sierra(Graphics^ g, Bitmap^ bmpCushuro, Bitmap^ bmpGranizo,
		Bitmap^ bmpCondor, Bitmap^ bmpKirbyVuela, Bitmap^ bmpKirbyCong, Bitmap^ bmpBasura);
	void Jugar_Selva(Graphics^ g,
		Bitmap^ bmpFruta, Bitmap^ bmpAnaconda, Bitmap^ bmpArana,
		Bitmap^ bmpPirana, Bitmap^ bmpKirbyVuela, Bitmap^ bmpKirbyFuego,
		Bitmap^ bmpBasura, Bitmap^ bala);
	void Disparar(Bitmap^ fire);
	int getNivel();
	void Desplazar(dir mover);
	int getVidas();
	int getTiempo();
	int getContador();
	bool getFin();
	bool getGanador();
	void Resumen(Graphics^ g);
	void setNivel();
	void GrabarResultado(vector<string>datos);
	void DrawVidas(Graphics^ g, Bitmap^ heart);
};

