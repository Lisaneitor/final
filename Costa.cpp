#include "Costa.h"
Costa::Costa() {
	objK = new Kirby(20, 20, 50, 50, true); 
	objP = new Pulpo((rand()% 1000 + 1250) / 2, 500);
	// 
	vector<string> parametros = objK->LeerINPUT();
	nombre_archivo_pulpo = parametros.at(3);
	nombre_archivo_tenta = parametros.at(0);

}
Costa::~Costa() {
	delete objP, objK;
	for (int i = 0; i < arrTenta.size(); i++)
		delete arrTenta.at(i);
}
void Costa::Dibujar_Enemigos(Graphics^ g, Bitmap^ bmpTenta, Bitmap^ bmpCabeza) {
	objP->Dibujar_Imagen(g, bmpCabeza);
	for (int i = 0; i < arrTenta.size(); i++) {
		arrTenta.at(i)->Dibujar_Imagen(g, bmpTenta);
		arrTenta.at(i)->Mover(g);

		if (arrTenta.at(i)->getEliminar()) {
			arrTenta.erase(arrTenta.begin() + i);
		}
	}
}
void Costa::Dibujar_Kirby(Graphics^ g, Bitmap^ bmp) {
	// Kirby Nadando
	Colision_Basura();
	Colision_Enemigos();
	Colision_PowerUp();
	Colision_Pulpo();

	objK->Dibujar_Imagen(g, bmp);
	objK->Mover(g);

	if (rapidez) {
		if (difftime(time(0), time_rapidez) > 5) {
			rapidez = false;
			objK->setFracMovX(4);
			objK->setFracMovY(4);
		}
	}

	if (objK->getVidas() == 0)
		esFin = true;
	if (contador == 3) {
		esFin = true;
		esGanador = true;
		Resumen(g);
	}
}
void Costa::Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp) {
	for (int i = 0; i < arrPz.size(); i++) {
		arrPz.at(i)->Dibujar_Imagen(g, bmp);
		arrPz.at(i)->Mover(g);

		if (arrPz.at(i)->getEliminar()) {
			arrPz.erase(arrPz.begin() + i);
		}
	}
}
bool Costa::Colision_Pulpo() {
	bool resultado_colision = false;
	System::Drawing::Rectangle r1 = objK->getRectangle();
	System::Drawing::Rectangle r3 = objP->getRectangle();

	if (r1.IntersectsWith(r3)) {
		resultado_colision = true;
		objK->setX(20);
		objK->setY(20);
		objK->setVidas();
	}

	for (int i = 0; !resultado_colision && i < arrTenta.size(); i++) {

		System::Drawing::Rectangle r2 = arrTenta.at(i)->getRectangle();
		//probar este code // no puedo e.e
		if (r1.IntersectsWith(r2)) {
			resultado_colision = true;
			objK->setX(20);
			objK->setY(20);
			objK->setVidas();
		}
	}
	return resultado_colision;
}
bool Costa::Colision_PowerUp() {
	// Pez
	bool resultado_colision = false;
	System::Drawing::Rectangle r1 = objK->getRectangle();

	for (int i = 0; i < arrPz.size(); i++) {
		System::Drawing::Rectangle r2 = arrPz.at(i)->getRectangle();

		resultado_colision = r1.IntersectsWith(r2);

		if (resultado_colision) {
			arrPz.at(i)->setEliminar(true);
			rapidez = true;
			time_rapidez = time(0);
			objK->setFracMovX(2);
			objK->setFracMovY(2);
		}
		//elimina si no lo agarraste
		if (!resultado_colision && arrPz.at(i)->getPow()) {
			arrPz.at(i)->setEliminar(true);
		}
	}
	return resultado_colision;
}
void Costa::Insertar_PowerUp(Graphics^ g, Bitmap^ bmpPez) {
	// Pez
	if (difftime(time(0), time_powerup) > 20) {
		time_powerup = time(0);
		arrPz.push_back(new Pez(rand() % 1000 + 80, rand() % 700 + 50, 0, 0));
	}
}

void Costa::Insertar_Enemigos(Graphics^ g, Bitmap^ bmp, Bitmap^ bmpTenta) {
	// Tentaculos
	//objP = new Pulpo(g->VisibleClipBounds.Width / 2 - bmp->Width / 2, 710);
	if (difftime(time(0), time_enemigos) > 3) {
		time_enemigos = time(0);
		int aux = rand() % 2;
		int max_x = (g->VisibleClipBounds.Width / 2 - bmp->Width / 2 - bmpTenta->Width) + 1;
		int max_y = (g->VisibleClipBounds.Height - bmpTenta->Height) + 1;
		int min_2x = (g->VisibleClipBounds.Width / 2 + bmp->Width / 2) + 1;
		int max_2x = (g->VisibleClipBounds.Width - bmpTenta->Width) + 1;

		if (aux == 0) {
			arrTenta.push_back(new Tentaculos(rand() % max_x + 1, max_y));
			arrTenta.at(arrTenta.size() - 1)->setdX(-10);
		}

		else {
			arrTenta.push_back(new Tentaculos(rand() % (max_2x - min_2x) + min_2x, max_y));
			arrTenta.at(arrTenta.size() - 1)->setdX(10);
		}
	}
}
System::String^ Costa::retornar_nombre_archivo_pulpo() { return gcnew System::String(nombre_archivo_pulpo.c_str()); }
System::String^ Costa::retornar_nombre_archivo_tenta() { return gcnew System::String(nombre_archivo_tenta.c_str()); }
