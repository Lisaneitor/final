#include "Nivel.h"
Nivel::Nivel() {
	esGanador = false;
	esFin = false;
	rapidez = false;
	pausa = false;
	contador = 0;
	// La cantidad de Basura puede cambiar despues 
	for (int i = 0; i < 10; i++)
		arrB.push_back(new Basura(rand() % 1400, rand() % 100 + 720, 200, 200));
	time_init_app = time(0);
	time_rapidez = time(0);
	time_pausa = time(0);
	time_enemigos = time(0);
	time_powerup = time(0);
	time_fuegito = time(0);
	time_basura = time(0);
}
Nivel::~Nivel() {
	for (int i = 0; i < arrB.size(); i++)
		delete arrB.at(i);
}

void Nivel::Desplazar(dir mover) {
	if (objK->getNada())
		objK->Nadar(mover);
	else {

		if (objK->getFuego()) {
			objK->Fuego(mover);
		}
		else {
			objK->Volar(mover);
		}
	}
}
bool Nivel::getFin() {
	return esFin;
}
bool Nivel::getGanador() {
	return esGanador;
}
int Nivel::getTiempo() {
	return int(difftime(time(0), time_init_app));
}
int Nivel::getVidas() {
	return objK->getVidas();
}
int Nivel::getContador() {
	return contador;
}
void Nivel::Resumen(Graphics^ g) {
	g->Clear(Color::Black);
	Font^ miFont = gcnew Font("Arial", 22);
	SolidBrush^ miBack = gcnew SolidBrush(Color::Bisque);
	int tmp = getTiempo();
	if (esGanador)
		g->DrawString("Completaste el nivel con un tiempo de " + tmp + " segundos", miFont, miBack,
			g->VisibleClipBounds.Width / 4, g->VisibleClipBounds.Height / 2);
	else
		g->DrawString("PERDISTE con un tiempo de " + tmp + " segundos", miFont, miBack,
			g->VisibleClipBounds.Width / 4, g->VisibleClipBounds.Height / 2);
}
bool Nivel::Colision_Basura() {
	bool resultado = false;
	Rectangle r1 = objK->getRectangle();

	for (int i = 0; !resultado && i < arrB.size(); i++) {
		Rectangle r2 = arrB.at(i)->getRectangle();

		if (r1.IntersectsWith(r2)) {
			resultado = true;
			arrB.at(i)->setEliminar(true);
			contador++;
		}
	}
	return resultado;
}
void Nivel::Dibujar_Basura(Graphics^ g, Bitmap^ bmp) {
	for (int i = 0; i < arrB.size(); i++) {
		arrB.at(i)->Dibujar_Imagen(g, bmp);

		if (arrB.at(i)->getEliminar())
			arrB.erase(arrB.begin() + i);
	}
}
// Modulos Virtuales
bool Nivel::Colision_Enemigos() {
	return false;
}
bool Nivel::Colision_PowerUp() {
	return false;
}
void Nivel::Dibujar_Kirby(Graphics^ g, Bitmap^ bmp) {  }
void Nivel::Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp) { }

void Nivel::Insertar_Basura(Graphics^ g, Bitmap^ bmp) {
	if (difftime(time(0), time_basura) > 5) {
		arrB.push_back(new Basura((gcnew System::Random())->Next(10, g->VisibleClipBounds.Width - bmp->Width -10),
			(gcnew System::Random())->Next(g->VisibleClipBounds.Height-250, g->VisibleClipBounds.Height - bmp->Height/7 - 10)
			, 1, 1));

		time_basura = time(0);
	}
}
void Nivel::Insertar_Enemigos() { }
