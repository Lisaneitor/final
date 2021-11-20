#include "Kirby.h"

Kirby::Kirby() {
	/*vector<string> parametros = LeerINPUT();
	dy = 0;
	dx = 0;
	setX(20);
	setY(20);
	System::String^ aux_fil = gcnew System::String(parametros.at(25).c_str());
	setMaxFil(System::Convert::ToInt32(aux_fil));
	System::String^ aux_col = gcnew System::String(parametros.at(26).c_str());
	setMaxCol(System::Convert::ToInt32(aux_col));
	setCol(0);
	setFil(0);
	fracMovX = 4;
	fracMovY = 4;
	direc = dir::down;
	vidas = 6;*/
}
Kirby::Kirby(int _x, int _y, int _w, int _h, bool _nada)
	:Base() {
	nada = _nada;

	vector<string> parametros = LeerINPUT();
	if (!nada) {

		dir hor_dir = dir::right;
		dy = y / fracMovY;
		dx = 0;
		setX(_x);
		setY(_y);
		System::String^ aux_fil = gcnew System::String(parametros.at(19).c_str());
		setMaxFil(System::Convert::ToInt32(aux_fil));

		System::String^ aux_col = gcnew System::String(parametros.at(20).c_str());
		setMaxCol(System::Convert::ToInt32(aux_col));
		setCol(0);
		setFil(0);
	}
	else {
		max_fil = 4;
		max_col = 8;
		dy = 0;
		dx = 0;
		dy = 0;
		dx = 0;
		setX(_x);
		setY(_y);
		System::String^ aux_fil = gcnew System::String(parametros.at(25).c_str());
		setMaxFil(System::Convert::ToInt32(aux_fil));
		System::String^ aux_col = gcnew System::String(parametros.at(26).c_str());
		setMaxCol(System::Convert::ToInt32(aux_col));
		setCol(0);
		setFil(0);
	}
	direc = dir::down;
	vidas = 3;
	fracMovX = 4;
	fracMovY = 4;
}
Kirby::~Kirby() { }
int Kirby::getVidas() { return vidas; }
void Kirby::setVidas() { vidas -= 1; }
void Kirby::Mover(Graphics^ g) {
	if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height)
		dy = 0;
	if (x + dx < 1 || x + dx + w > g->VisibleClipBounds.Width)
		dx = 0;

	y += dy;
	x += dx;
}
void Kirby::Dibujar_Congelado(Graphics^ g, Bitmap^ bmp) {
	// Imagen animada
	w = bmp->Width / 1;
	h = bmp->Height / 3;
	Rectangle porcion = Rectangle(0 * w, 1 * h, w, h);
	Rectangle zoom = Rectangle(x, y, w * 1.2, h * 1.2);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
}
void Kirby::Dibujar_Fuego(Graphics^ g, Bitmap^ bmp) {
	// Imagen de kirby con poder
	//descubramoslo
	vector<string> parametros = LeerINPUT();
	System::String^ aux_fil = gcnew System::String(parametros.at(52).c_str());
	int max_f = System::Convert::ToInt32(aux_fil);
	System::String^ aux_col = gcnew System::String(parametros.at(53).c_str());
	int max_c = (System::Convert::ToInt32(aux_col));

	w = bmp->Width / max_c;
	h = bmp->Height / max_f;
	Rectangle porcion = Rectangle(col * w, fil * h, w, h);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);

	col++;
	if (col == max_c)
		col = 0;
}
void Kirby::Disparar(Bitmap^ kirbyfuego) {

	if (direc == dir::left || direc == dir::right) {
		balas.push_back(new Bala(x + w / 2, y + h / 2, 1, 1));

		if (direc == dir::left) {
			balas.at(balas.size() - 1)->setdX(-15);
			balas.at(balas.size() - 1)->setFil(0);
		}
		if (direc == dir::right) {
			balas.at(balas.size() - 1)->setdX(15);
			balas.at(balas.size() - 1)->setFil(1);
		}
	}
}
void Kirby::Mover_Bala(Graphics^ g, Bitmap^ bmp_bala) {
	for (int i = 0; i < balas.size(); i++)
	{
		balas.at(i)->Dibujar_Imagen(g, bmp_bala);
		balas.at(i)->Mover(g);

		if (balas.at(i)->getEliminar())
			balas.erase(balas.begin() + i);
	}
}
int Kirby::get_cant_balas() { return balas.size(); }
Base* Kirby::get_bala_pos(int indice) { return balas.at(indice); }