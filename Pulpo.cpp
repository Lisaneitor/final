#include "Pulpo.h"
Pulpo::Pulpo() { }
Pulpo::Pulpo(int _x, int _y) : Base() {
	setX(_x);
	setY(_y);
	vector<string> parametros = LeerINPUT();
	System::String^ aux_fil = gcnew System::String(parametros.at(4).c_str());
	setMaxFil(System::Convert::ToInt32(aux_fil));
	System::String^ aux_col = gcnew System::String(parametros.at(5).c_str());
	setMaxCol(System::Convert::ToInt32(aux_col));
	setCol(0);
	setFil(0);
	fracMovX = 1;
	fracMovY = 1;
}
Pulpo::~Pulpo() { }
