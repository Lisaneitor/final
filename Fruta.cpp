#include "Fruta.h"
Fruta::Fruta() { }
Fruta::Fruta(int _x, int _y, int _w, int _h)
	:Base() {
	int tmp = rand() % 5;
	fil = tmp;
	setX(_x);
	setY(_y);
	vector<string> parametros = LeerINPUT();
	System::String^ aux_fil = gcnew System::String(parametros.at(13).c_str());
	setMaxFil(System::Convert::ToInt32(aux_fil));
	System::String^ aux_col = gcnew System::String(parametros.at(14).c_str());
	setMaxCol(System::Convert::ToInt32(aux_col));
	setCol(0);
	setFil(0);
	des_pow = time(0);
}
Fruta::~Fruta() { }
