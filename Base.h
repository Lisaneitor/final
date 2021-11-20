#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
using namespace System::Drawing;
public enum dir { up, down, left, right, none };
class Base
{
protected:
	//variable que define el tiempo en que desaparece el power up
	time_t des_pow;
	int x, y, w, h, dx, dy;
	bool eliminar;
	int max_fil, max_col, fil, col; // Sprites
	dir direc;
	dir hor_direc;
	int fracMovY, fracMovX;
	int color;
	bool nada;
	bool fuego;
public:
	Base();
	Base(int _x, int _y, int _w, int _h);
	Base(int _x, int _y, int _w, int _h, int _max_fil, int _max_col, int _fil, int _col);
	~Base();
	int getX();
	int getY();
	int getdX();
	int getdY();
	int getW();
	int getH();
	int getFil();
	int getCol();
	int getMaxFil();
	int getMaxCol();
	int getFracMovY();
	int getFracMovX();
	bool getEliminar();
	void setX(int n);
	void setY(int n);
	void setdX(int n);
	void setdY(int n);
	void setW(int n);
	void setH(int n);
	void setFil(int n);
	void setCol(int n);
	void setMaxFil(int n);
	void setMaxCol(int n);
	void setFracMovX(int n);
	void setFracMovY(int n);
	void setEliminar(bool n);
	Rectangle getRectangle();
	virtual void Mover(Graphics^ g);
	void Dibujar(Graphics^ g, Bitmap^ bmp);
	void Borrar(Graphics^ g);
	virtual void Dibujar_Imagen(Graphics^ g, Bitmap^ bmp);
	int getColor();
	// Desplazar - Kirby nada
	void Nadar(dir n);
	// Desplazar - Kirby vuela
	void Volar(dir n);
	// Desplazar - Kirby fuego
	void Fuego(dir n);
	void setNada();
	bool getNada();
	void setFuego(bool fuego);
	bool getFuego();
	void Desplazar(dir orientacion);
	bool getPow();
	vector<string> LeerINPUT();
	void GrabarOUTPUT(vector<string>);
};