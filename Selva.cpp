#include "Selva.h"
Selva::Selva() : Nivel() {
	objP = new Pirana(rand() % 1400, rand() % 10 + 740, 200, 200);
	objK = new Kirby(20, 20, 50, 50, false);
	vector<string> parametros = objK->LeerINPUT();
	nombre_archivo_anaconda = parametros.at(39);
	nombre_archivo_arana = parametros.at(42);
	nombre_archivo_pirana = parametros.at(30);
	nombre_archivo_fruta = parametros.at(12);
	objK->setFuego(false);
}
Selva::~Selva() {
	for (int i = 0; i < arrAna.size(); i++) {
		delete arrAna.at(i);
	}
	delete objP, objK;
}
bool Selva::Colision_Enemigos() {
	bool resultado = false;
	bool resultado2 = false;
	Rectangle r1 = objK->getRectangle();

	// Anaconda 
	for (int i = 0; !resultado && i < arrAna.size(); i++) {
		Rectangle r2 = arrAna.at(i)->getRectangle();

		if (r1.IntersectsWith(r2)) {
			resultado = true;
			// Menos vidas de Kirby
			objK->setVidas();
			// Kirby vuelve a la esquina superior izquierda
			if (objK->getFuego())
				objK->setFuego(false);
			objK->setX(20);
			objK->setY(20);
		}

	}

	// Arana
	for (int i = 0; !resultado && i < arrAr.size(); i++) {
		Rectangle r2 = arrAr.at(i)->getRectangle();

		if (r1.IntersectsWith(r2)) {
			resultado = true;
			// Menos vidas de Kirby
			objK->setVidas();
			// Kirby vuelve a la esquina superior izquierda
			if (objK->getFuego())
				objK->setFuego(false);
			objK->setX(20);
			objK->setY(20);
		}
	}

	// Pirana
	Rectangle r2 = objP->getRectangle();

	if (r1.IntersectsWith(r2)) {
		resultado = true;
		// Menos vidas de Kirby
		objK->setVidas();
		// Kirby vuelve a la esquina superior izquierda
		if (objK->getFuego())
			objK->setFuego(false);
		objK->setX(20);
		objK->setY(20);
	}
	return resultado;
}
void Selva::Colision_Bala() {
	bool resultado = false;
	bool resultado2 = false;

	for (int i = 0; !resultado && i < arrAna.size(); i++) {
		Rectangle r2 = arrAna.at(i)->getRectangle();
		//bala
		for (int j = 0; !resultado2 && j < objK->get_cant_balas(); j++)
		{
			Rectangle rb = objK->get_bala_pos(j)->getRectangle();
			if (rb.IntersectsWith(r2)) {
				resultado = true;
				resultado2 = true;
				arrAna.at(i)->setEliminar(true);
				objK->get_bala_pos(j)->setEliminar(true);
				contador += 2;
			}
		}
	}

	for (int i = 0; !resultado && i < arrAr.size(); i++) {
		Rectangle r2 = arrAr.at(i)->getRectangle();
		//bala
		for (int j = 0; !resultado2 && j < objK->get_cant_balas(); j++)
		{
			Rectangle rb = objK->get_bala_pos(j)->getRectangle();
			if (rb.IntersectsWith(r2)) {
				resultado = true;
				resultado2 = true;
				arrAr.at(i)->setEliminar(true);
				objK->get_bala_pos(j)->setEliminar(true);
				contador += 2;
			}
		}
	}
}
bool Selva::Colision_PowerUp() {
	// Fruta
	bool resultado = false;
	Rectangle r1 = objK->getRectangle();

	for (int i = 0; !resultado && i < arrFr.size(); i++) {
		Rectangle r2 = arrFr.at(i)->getRectangle();

		if (r1.IntersectsWith(r2)) {
			resultado = true;
			arrFr.at(i)->setEliminar(true);
			// Empieza la velocidad
			time_fuegito = time(0);
			// TODO: Examinar todo fuego
			objK->setFuego(true);
		}
	}
	return resultado;
}
void Selva::Dibujar_Kirby(Graphics^ g, Bitmap^ bmp, Bitmap^ fire, Bitmap^ bala) {
	// Kirby Volando
	Colision_Basura();
	Colision_Bala();

	// Rapidez evaluada

	if (objK->getFuego() == true) {
		Dibujar_Fuego(g, fire, bala, bmp);

	}
	else if (objK->getFuego() == false) {
		/*vector<string> parametros = objK->LeerINPUT();
		System::String^ aux_fil = gcnew System::String(parametros.at(19).c_str());
		objK->setMaxFil(System::Convert::ToInt32(aux_fil));

		System::String^ aux_col = gcnew System::String(parametros.at(20).c_str());
		objK->setMaxCol(System::Convert::ToInt32(aux_col));*/

		Colision_PowerUp();
		Colision_Enemigos();
		objK->Dibujar_Imagen(g, bmp);
		objK->Mover(g);
	}

	if (objK->get_cant_balas() > 0 && objK->getFuego() == false) {
		objK->Mover_Bala(g, bala);
	}

	objK->Mover(g);

	if (objK->getVidas() == 0)
		esFin = true;
	if (contador == 50) {
		esFin = true;
		esGanador = true;
	}
}
void Selva::Disparar(Bitmap^ fire) {
	if (objK->getFuego()) {
		objK->Disparar(fire);
	}
}
void Selva::Dibujar_Enemigos(Graphics^ g, Bitmap^ bmpAna, Bitmap^ bmpAr, Bitmap^ bmpPir) {
	// Anaconda 
	for (int i = 0; i < arrAna.size(); i++) {
		if (arrAna.at(i)->getdY() + arrAna.at(i)->getY() > 700)
			arrAna.at(i)->setEliminar(true);
		if (arrAna.at(i)->getEliminar())
			arrAna.erase(arrAna.begin() + i);
	}
	for (int i = 0; i < arrAna.size(); i++) {
		arrAna.at(i)->Dibujar_Imagen(g, bmpAna);
		arrAna.at(i)->Mover(g);
	}
	// Arana 
	for (int i = 0; i < arrAr.size(); i++) {
		if (arrAr.at(i)->getdY() + arrAr.at(i)->getY() > 700)
			arrAr.at(i)->setEliminar(true);
		if (arrAr.at(i)->getEliminar())
			arrAr.erase(arrAr.begin() + i);
	}
	for (int i = 0; i < arrAr.size(); i++) {
		arrAr.at(i)->Dibujar_Imagen(g, bmpAr);
		arrAr.at(i)->Mover(g);
	}
	// Pirana 
	if (objP->getX() + objP->getdX() < 0)
		objP->setFil(1);
	if (objP->getX() + objP->getdX() > 1530 - objP->getW())
		objP->setFil(0);
	objP->Dibujar_Imagen(g, bmpPir);
	objP->Mover(g);
}
void Selva::Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp) {
	// Fruta
	for (int i = 0; i < arrFr.size(); i++) {
		arrFr.at(i)->Dibujar_Imagen(g, bmp);

		if (arrFr.at(i)->getEliminar())
			arrFr.erase(arrFr.begin() + i);
	}
}
void Selva::Insertar_PowerUp(Graphics^ g, Bitmap^ bmp) {
	// fruta
	if (difftime(time(0), time_powerup) > 20) {
		arrFr.push_back(new Fruta((gcnew System::Random())->Next(10, g->VisibleClipBounds.Width - bmp->Width),
			(gcnew System::Random())->Next(20, 200), 1, 1));
		time_powerup = time(0);
	}
}
void Selva::Insertar_Enemigos(Graphics^ g, Bitmap^ bmp) {
	if (difftime(time(0), time_enemigos) > 3) {
		arrAna.push_back(new Anaconda((gcnew System::Random())->Next(10, g->VisibleClipBounds.Width - bmp->Width),
			(gcnew System::Random())->Next(20, 200), 1, 1));
		arrAr.push_back(new Arana((gcnew System::Random())->Next(10, g->VisibleClipBounds.Width - bmp->Width),
			(gcnew System::Random())->Next(20, 200), 1, 1));
		time_enemigos = time(0);
	}
}
void Selva::Dibujar_Fuego(Graphics^ g, Bitmap^ fire, Bitmap^ bala, Bitmap^ bmp) {
	objK->Dibujar_Fuego(g, fire);
	objK->Mover_Bala(g, bala);

	if (difftime(time(0), time_fuegito) > 10) {
		objK->setFuego(false);
		objK->setCol(0);
		objK->setFil(0);
		objK->setMaxCol(2);
		objK->setMaxFil(4);
		objK->Dibujar_Imagen(g, bmp);
		objK->Mover(g);
	}
}
System::String^ Selva::retornar_nombre_archivo_anaconda() { return gcnew System::String(nombre_archivo_anaconda.c_str()); }
System::String^ Selva::retornar_nombre_archivo_arana() { return gcnew System::String(nombre_archivo_arana.c_str()); }
System::String^ Selva::retornar_nombre_archivo_fruta() { return gcnew System::String(nombre_archivo_fruta.c_str()); }
System::String^ Selva::retornar_nombre_archivo_pirana() { return gcnew System::String(nombre_archivo_pirana.c_str()); }

