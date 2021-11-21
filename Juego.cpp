#include "Juego.h"
Juego::Juego() {
	// Test de nivel selva
	nivel = 3;
	time_init_app = time(0);
	contador = 0;
	nvCosta = new Costa();
	nvSierra = new Sierra();
	nvSelva = new Selva();
}
Juego::~Juego() {
	delete nvCosta, nvSierra, nvSelva;
}
void Juego::Jugar_Costa(Graphics^ g, Bitmap^ bmpPez, Bitmap^ bmpPulpo,
	Bitmap^ bmpTenta, Bitmap^ bmpKirbyNada, Bitmap^ bmpBasura) {
	nvCosta->Dibujar_Kirby(g, bmpKirbyNada);
	nvCosta->Dibujar_Basura(g, bmpBasura);
	nvCosta->Dibujar_PowerUp(g, bmpPez);
	nvCosta->Dibujar_Enemigos(g, bmpTenta, bmpPulpo);
	nvCosta->Insertar_Basura(g, bmpBasura);
	nvCosta->Insertar_PowerUp(g, bmpPez);
	nvCosta->Insertar_Enemigos(g, bmpPulpo, bmpTenta);
}
void Juego::Jugar_Sierra(Graphics^ g, Bitmap^ bmpCushuro, Bitmap^ bmpGranizo,
	Bitmap^ bmpCondor, Bitmap^ bmpKirbyVuela, Bitmap^ bmpKirbyCong, Bitmap^ bmpBasura) {
	nvSierra->Dibujar_Kirby(g, bmpKirbyVuela, bmpKirbyCong);
	nvSierra->Dibujar_Basura(g, bmpBasura);
	nvSierra->Dibujar_PowerUp(g, bmpCushuro);
	nvSierra->Dibujar_Enemigos(g, bmpGranizo, bmpCondor);
	nvSierra->Insertar_Basura(g, bmpBasura);
	nvSierra->Insertar_PowerUp(g, bmpCushuro);
	nvSierra->Insertar_Enemigos();
}
void Juego::Jugar_Selva(Graphics^ g,
	Bitmap^ bmpFruta, Bitmap^ bmpAnaconda, Bitmap^ bmpArana,
	Bitmap^ bmpPirana, Bitmap^ bmpKirbyVuela, Bitmap^ bmpKirbyFuego, Bitmap^ bmpBasura, Bitmap^ bala) {
	nvSelva->Dibujar_Kirby(g, bmpKirbyVuela, bmpKirbyFuego, bala);
	nvSelva->Dibujar_Basura(g, bmpBasura);
	nvSelva->Dibujar_PowerUp(g, bmpFruta);
	nvSelva->Dibujar_Enemigos(g, bmpAnaconda, bmpArana, bmpPirana);
	nvSelva->Insertar_Basura(g, bmpBasura);
	nvSelva->Insertar_PowerUp(g, bmpFruta);
	nvSelva->Insertar_Enemigos(g, bmpAnaconda);
}
void Juego::Disparar(Bitmap^ fire) {
	nvSelva->Disparar(fire);
}
int Juego::getNivel() {
	return nivel;
}
void Juego::Desplazar(dir mover) {
	if (nivel == 1)
		nvCosta->Desplazar(mover);
	if (nivel == 2)
		nvSierra->Desplazar(mover);
	if (nivel == 3)
		nvSelva->Desplazar(mover);
}
int Juego::getVidas() {
	int n = 0;
	if (nivel == 1)
		n = nvCosta->getVidas();
	if (nivel == 2)
		n = nvSierra->getVidas();
	if (nivel == 3)
		n = nvSelva->getVidas();
	return n;
}
int Juego::getTiempo() {
	return int(difftime(time(0), time_init_app));
}
int Juego::getContador() {
	int n = 0;
	if (nivel == 1)
		n = nvCosta->getContador();
	if (nivel == 2)
		n = nvSierra->getContador();
	if (nivel == 3)
		n = nvSelva->getContador();
	return n;
}
bool Juego::getFin() {
	bool n = false;
	if (nivel == 1)
		n = nvCosta->getFin();
	if (nivel == 2)
		n = nvSierra->getFin();
	if (nivel == 3)
		n = nvSelva->getFin();
	return n;
}
bool Juego::getGanador() {
	bool n = false;
	if (nivel == 1)
		n = nvCosta->getGanador();
	if (nivel == 2)
		n = nvSierra->getGanador();
	if (nivel == 3)
		n = nvSelva->getGanador();
	return n;
}
void Juego::Resumen(Graphics^ g) {
	if (nivel == 1)
		nvCosta->Resumen(g);
	if (nivel == 2)
		nvSierra->Resumen(g);
	if (nivel == 3)
		nvSelva->Resumen(g);
}
void Juego::setNivel() {
	++nivel;
}
void Juego::GrabarResultado(vector<string>datos) {
	objK->GrabarOUTPUT(datos);
}
void Juego::DrawVidas(Graphics^ g, Bitmap^ heart) {

	Rectangle r = Rectangle(0, 0, heart->Width, heart->Height);
	int a = 0;
	int ancho = (g->VisibleClipBounds.Width);
	for (int i = 0; i < getVidas(); i++)
	{
		g->DrawImage(heart, ancho - (heart->Width * 5) + a, 10, r, GraphicsUnit::Pixel);
		
		a += 45;
	}
}

