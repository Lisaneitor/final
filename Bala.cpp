#include "Bala.h"
Bala::Bala() {}
Bala::Bala(int _x, int _y, int _w, int _h) : Base() {
	setX(_x);
	setY(_y);

	vector<string> parametros = LeerINPUT();
	System::String^ aux_fil = gcnew System::String(parametros.at(55).c_str());
	setMaxFil(System::Convert::ToInt32(aux_fil));
	System::String^ aux_col = gcnew System::String(parametros.at(56).c_str());
	setMaxCol(System::Convert::ToInt32(aux_col));
	setCol(0);
	setFil(0);
}

void Bala::Mover(Graphics^ g) {
	if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height) {
		dy = 0;
		setEliminar(true);
	}
	if (x + dx < 1 || x + dx + w > g->VisibleClipBounds.Width) {
		dx = 0;
		setEliminar(true);
	}

	y += dy;
	x += dx;
}
Bala::~Bala() {}