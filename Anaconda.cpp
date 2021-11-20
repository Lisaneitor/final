#include "Anaconda.h"

Anaconda::Anaconda() { }
Anaconda::Anaconda(int _x, int _y, int _w, int _h)
	:Base() {
	setX(_x);
	setY(_y);
	setdY(15);
	vector<string> parametros = LeerINPUT();
	System::String^ aux_fil = gcnew System::String(parametros.at(40).c_str());
	setMaxFil(System::Convert::ToInt32(aux_fil));
	System::String^ aux_col = gcnew System::String(parametros.at(41).c_str());
	setMaxCol(System::Convert::ToInt32(aux_col));
	setCol(0);
	setFil(0);
	//dy = 15;
}
Anaconda::~Anaconda() { }
