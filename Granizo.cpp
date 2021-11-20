#include "Granizo.h"
Granizo::Granizo() {}

Granizo::Granizo(int _x, int _y, int _w, int _h) : Base() {
    System::Random^ r = gcnew System::Random();
    dy = r->Next(3, 10);
    delete r;
    setX(_x);
    setY(_y);
    vector<string> parametros = LeerINPUT();
    System::String^ aux_fil = gcnew System::String(parametros.at(16).c_str());
    setMaxFil(System::Convert::ToInt32(aux_fil));
    System::String^ aux_col = gcnew System::String(parametros.at(17).c_str());
    setMaxCol(System::Convert::ToInt32(aux_col));
    setCol(0);
    setFil(0);
}
void Granizo::Mover(Graphics^ g) {
    if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height) {
        dy = 0;
        setEliminar(true);
    }
    y += dy;
}
Granizo::~Granizo() {}
