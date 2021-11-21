#include "Sierra.h"
Sierra::Sierra() {
	objC = new Condor(1000, 300, 1, 1);
	objK = new Kirby(20, 20, 50, 50, false);
	vector<string> parametros = objK->LeerINPUT();
	nombre_archivo_cushuro = parametros.at(9);
	nombre_archivo_granizo = parametros.at(15);
}
Sierra::~Sierra() {
	for (int i = 0; i < arrGr.size(); i++)
		delete arrGr.at(i);
	for (int i = 0; i < arrCsh.size(); i++)
		delete arrCsh.at(i);
	delete objC, objK;
}
bool Sierra::Colision_Enemigos() {
	bool resultado = false;
	// Condor
	Rectangle r1 = objK->getRectangle();
	Rectangle r2 = objC->getRectangle();
	if (r1.IntersectsWith(r2)) {
		resultado = true;
		objK->setVidas();
		objK->setX(20);
		objK->setY(20);
		if (pausa)
			pausa = false;
	}
	// Granizo
	for (int i = 0; !resultado && i < arrGr.size(); i++) {
		Rectangle rgr = arrGr.at(i)->getRectangle();
		if (r1.IntersectsWith(rgr)) {
			resultado = true;
			time_pausa = time(0);
			objK->setVidas();
			objK->Volar(none);
			arrGr.at(i)->setEliminar(true);
			pausa = true;
		}
	}
	return resultado;
}
bool Sierra::Colision_PowerUp() {
	bool resultado = false;
	Rectangle r1 = objK->getRectangle();

	for (int i = 0; i < arrCsh.size(); i++) {
		Rectangle rch = arrCsh.at(i)->getRectangle();
		if (r1.IntersectsWith(rch)) {
			resultado = true;
			arrCsh.at(i)->setEliminar(true);
			// Empieza la velocidad
			time_rapidez = time(0);
			rapidez = true;
			objK->setFracMovX(2);
			objK->setFracMovY(2);
		}
	}
	return resultado;
}
void Sierra::Insertar_Enemigos() {
	// Granizo
	if (difftime(time(0), time_enemigos) > 5) {
		arrGr.push_back(new Granizo(rand() % 1400, rand() % 200 + 20, 200, 200));
		time_enemigos = time(0);
	}
}
void Sierra::Insertar_PowerUp(Graphics^ g, Bitmap^ bmp) {
	// Cushuro
	if (difftime(time(0), time_powerup) > 20) {
		arrCsh.push_back(new Cushuro((gcnew System::Random())->Next(10, g->VisibleClipBounds.Width - bmp->Width),
			(gcnew System::Random())->Next(20, 200), 1, 1));
		time_powerup = time(0);
	}
}
void Sierra::Dibujar_Kirby(Graphics^ g, Bitmap^ bmp, Bitmap^ bmpCong) {
	// Kirby Volando
	Colision_Basura();
	Colision_Enemigos();
	Colision_PowerUp();

	// Rapidez evaluada
	if (rapidez) {
		if (difftime(time(0), time_rapidez) > 5) {
			rapidez = false;
			objK->setFracMovX(4);
			objK->setFracMovY(4);
		}
	}

	// Si esta congelado 
	if (pausa)
		Dibujar_Congelado(g, bmpCong);
	else {
		objK->Dibujar_Imagen(g, bmp);
		objK->Mover(g);
	}

	if (objK->getVidas() == 0)
		esFin = true;
	if (contador == 30) {
		esFin = true;
		esGanador = true;
		Resumen(g);
	}
}
void Sierra::Dibujar_Enemigos(Graphics^ g, Bitmap^ bmpGr, Bitmap^ bmpC) {
	objC->Dibujar_Imagen(g, bmpC);
	objC->Mover(g);

	for (int i = 0; i < arrGr.size(); i++) {
		arrGr.at(i)->Dibujar_Imagen(g, bmpGr);
		arrGr.at(i)->Mover(g);
	}
	for (int i = 0; i < arrGr.size(); i++) {
		if (arrGr.at(i)->getEliminar())
			arrGr.erase(arrGr.begin() + i);
	}
}
void Sierra::Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp) {
	for (int i = 0; i < arrCsh.size(); i++) {
		arrCsh.at(i)->Dibujar(g, bmp);
		arrCsh.at(i)->Mover(g);
	}
	for (int i = 0; i < arrCsh.size(); i++) {
		if (arrCsh.at(i)->getEliminar())
			arrCsh.erase(arrCsh.begin() + i);
	}
}
void Sierra::Dibujar_Congelado(Graphics^ g, Bitmap^ congelado) {
	objK->Dibujar_Congelado(g, congelado);
	if (difftime(time(0), time_pausa) > 5)
		pausa = false;
}
System::String^ Sierra::retornar_nombre_archivo_cushuro() { return gcnew System::String(nombre_archivo_cushuro.c_str()); }
System::String^ Sierra::retornar_nombre_archivo_granizo() { return gcnew System::String(nombre_archivo_granizo.c_str()); }