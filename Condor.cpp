#include "Condor.h"
Condor::Condor() { }
Condor::Condor(int _x, int _y, int _w, int _h)
	: Base() {
	System::Random^ r = gcnew System::Random();
	dx = -r->Next(30, 45);
	delete r;
	setX(_x);
	setY(_y);
	vector<string> parametros = LeerINPUT();
	System::String^ aux_fil = gcnew System::String(parametros.at(7).c_str());
	setMaxFil(System::Convert::ToInt32(aux_fil));

	System::String^ aux_col = gcnew System::String(parametros.at(8).c_str());
	setMaxCol(System::Convert::ToInt32(aux_col));
	setCol(0);
	setFil(0);
}
void Condor::Mover(Graphics^ g) {
	if (x + dx < 1 || x + dx + w > g->VisibleClipBounds.Width) {
		dx *= -1;

		if (dx > 0)
			fil = 1;
		else
			fil = 0;
	}
	x += dx;
}
Condor::~Condor() { }
