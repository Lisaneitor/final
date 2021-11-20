#include "Cushuro.h"
Cushuro::Cushuro() { }
Cushuro::Cushuro(int _x, int _y, int _w, int _h) : Base() {
    System::Random^ r = gcnew System::Random();
    dy = r->Next(3, 10);
    delete r;
    setX(_x);
    setY(_y);
    vector<string> parametros = LeerINPUT();
    System::String^ aux_fil = gcnew System::String(parametros.at(10).c_str());
    setMaxFil(System::Convert::ToInt32(aux_fil));
    System::String^ aux_col = gcnew System::String(parametros.at(11).c_str());
    setMaxCol(System::Convert::ToInt32(aux_col));
    setCol(0);
    setFil(0);
    des_pow = time(0);
}
Cushuro::~Cushuro() { }
void Cushuro::Mover(Graphics^ g) {
    if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height) {
        dy = 0;
        setEliminar(true);
    }
    y += dy;
}
    