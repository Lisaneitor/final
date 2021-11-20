#include "Pez.h"
Pez::Pez() { }
Pez::Pez(int _x, int _y, int _h, int _w) : Base() {
	des_pow = time(0);
	int a = rand() % 2;
	setX(_x);
	setY(_y);
	vector<string> parametros = LeerINPUT();
	System::String^ aux_fil = gcnew System::String(parametros.at(28).c_str());
	setMaxFil(System::Convert::ToInt32(aux_fil));
	System::String^ aux_col = gcnew System::String(parametros.at(29).c_str());
	setMaxCol(System::Convert::ToInt32(aux_col));
	setCol(0);
	setFil(0);
	if (a == 0) {
		Desplazar(dir::right);
		dx = 20;
	}
	if (a == 1) {
		Desplazar(dir::left);
		dx = -20;
	}
}
Pez::~Pez() { }
void Pez::Mover(Graphics^ g) {
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) {
		dx = dx * -1;
	}
	if (dx > 0)
		Desplazar(dir::right);
	if (dx < 0)
		Desplazar(dir::left);
	x += dx;
}
//