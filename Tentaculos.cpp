#include "Tentaculos.h"
Tentaculos::Tentaculos() { }
Tentaculos::~Tentaculos() { }
Tentaculos::Tentaculos(int _x, int _y):Base(_x, _y, 1, 1) {
	fracMovX = 1;
	fracMovY = 1;
	max_col = 2;
	max_fil = 1;
	col = 0;
	fil = 0;
}
void Tentaculos::Mover(Graphics^ g) {
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) {
		dx = 0;
		setEliminar(true);
	}
	x += dx;
}
