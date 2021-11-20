#include "Base.h"

Base::Base() {
	dx = dy = 0;
	direc = dir::none;
	hor_direc = dir::right;
	eliminar = false;
	nada = false;
	fuego = false;
}
Base::Base(int _x, int _y, int _w, int _h) {
	// Imagen estatica
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	dx = dy = 0;
	direc = dir::none;
	eliminar = false;
	nada = false;
	fuego = false;
}
Base::Base(int _x, int _y, int _w, int _h, int _max_fil, int _max_col, int _fil, int _col) {
	// Imagen animada
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	max_fil = _max_fil;
	max_col = _max_col;
	fil = _fil;
	col = _col;
	dx = dy = 0;
	direc = dir::none;
	eliminar = false;
	nada = false;
	fuego = false;
}
Base::~Base() {}
int Base::getX() { return x; }
int Base::getY() { return y; }
int Base::getdX() { return dx; }
int Base::getdY() { return dy; }
int Base::getW() { return w; }
int Base::getH() { return h; }
int Base::getFil() { return fil; }
int Base::getCol() { return col; }
int Base::getMaxFil() { return max_fil; }
int Base::getMaxCol() { return max_col; }
int Base::getFracMovX() { return fracMovX; }
int Base::getFracMovY() { return fracMovY; }
bool Base::getEliminar() { return eliminar; }
void Base::setX(int n) { x = n; }
void Base::setY(int n) { y = n; }
void Base::setdX(int n) { dx = n; }
void Base::setdY(int n) { dy = n; }
void Base::setW(int n) { w = n; }
void Base::setH(int n) { h = n; }
void Base::setFil(int n) { fil = n; }
void Base::setCol(int n) { col = n; }
void Base::setMaxFil(int n) { max_fil = n; }
void Base::setMaxCol(int n) { max_col = n; }
void Base::setFracMovX(int n) { fracMovX = n; }
void Base::setFracMovY(int n) { fracMovY = n; }
void Base::setEliminar(bool n) { eliminar = n; }
Rectangle Base::getRectangle() {
	return Rectangle(x, y, w, h);
}
// Modifique desplazar para que es realice 
// dependiendo que que fila es la animacion
void Base::Nadar(dir n) {
	direc = n;
	dx = dy = 0;
	// Tener cuidado a que fila pertenece que
	// Cambiar fila si es que es para otra cosa
	//
	// Cuando Kirby nada
	if (direc == dir::up) {
		dy = -(h / fracMovY);
		fil = 2;
	}
	if (direc == dir::down) {
		dy = (2 * h / fracMovY);
		fil = 3;
	}
	if (direc == dir::left) {
		dx = -(w / fracMovX);
		fil = 1;
	}
	if (direc == dir::right) {
		dx = (w / fracMovX);
		fil = 0;
	}
}
void Base::Volar(dir n) {
	if (direc == dir::left)
		hor_direc = direc;
	if (direc == dir::right)
		hor_direc = direc;
	direc = n;
	dx = dy = 0;
	// Tener cuidado a que fila pertenece que
	// Cambiar fila si es que es para otra cosa
	if (direc == dir::up) {
		if (hor_direc == dir::left)
			fil = 3;
		else
			fil = 2;
		dy = -(h / fracMovY);
	}
	if (direc == dir::down) {
		if (hor_direc == dir::left)
			fil = 1;
		else
			fil = 0;
		dy = (2 * h / fracMovY);
	}
	if (direc == dir::left) {
		dx = -(w / fracMovX);
		dy = (h / fracMovY);
		fil = 1;
	}
	if (direc == dir::right) {
		dx = (w / fracMovX);
		dy = (h / fracMovY);
		fil = 0;
	}
}
void Base::Fuego(dir n) {
	direc = n;
	dx = dy = 0;
	// Tener cuidado a que fila pertenece que
	// Cambiar fila si es que es para otra cosa
	//
	// Cuando 	if (direc == dir::left)
	hor_direc = direc;
	if (direc == dir::right)
		hor_direc = direc;
	direc = n;
	dx = dy = 0;
	// Tener cuidado a que fila pertenece que
	// Cambiar fila si es que es para otra cosa
	if (direc == dir::up) {
		if (hor_direc == dir::left)
			fil = 3;
		else
			fil = 2;
		dy = -(h / fracMovY);
	}
	if (direc == dir::down) {
		if (hor_direc == dir::left)
			fil = 1;
		else
			fil = 0;
		dy = (2 * h / fracMovY);
	}
	if (direc == dir::left) {
		dx = -(w / fracMovX);
		dy = (h / fracMovY);
		fil = 1;
	}
	if (direc == dir::right) {
		dx = (w / fracMovX);
		dy = (h / fracMovY);
		fil = 0;
	}
}

void Base::Mover(Graphics^ g) {
	if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height)
		dy = dy * -1;
	if (x + dx < 1 || x + dx + w > g->VisibleClipBounds.Width)
		dx = dx * -1;

	y += dy;
	x += dx;
}
void Base::Dibujar(Graphics^ g, Bitmap^ bmp) {
	// Para imagen estatica
	w = bmp->Width;
	h = bmp->Height;
	Rectangle porcion = Rectangle(0, 0, w, h);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
}
void Base::Borrar(Graphics^ g) {
	// Tratar de hacerlo dsp
}
void Base::Dibujar_Imagen(Graphics^ g, Bitmap^ bmp) {
	// Imagen animada
	w = bmp->Width / max_col;
	h = bmp->Height / max_fil;
	Rectangle porcion = Rectangle(col * w, fil * h, w, h);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);

	// Solo cambia columna
	// Para otros ejercicios puedes necesitar cambiar fila
	col++;
	if (col == max_col)
		col = 0;
}
int Base::getColor() {
	return color;
}
void Base::setNada() {
	nada = true;
}
bool Base::getNada() {
	return nada;
}
void Base::setFuego(bool _fuego) {
	fuego = _fuego;
}
bool Base::getFuego() {
	return fuego;
}
void Base::Desplazar(dir orientacion) {
	if (orientacion == dir::left) { fil = 0; }
	if (orientacion == dir::right) { fil = 1; }
}
bool Base::getPow() {
	return (difftime(time(0), des_pow) > 15);
}
vector<string> Base::LeerINPUT() {
	string linea;
	vector<string> resultado;
	ifstream miarchivo("INPUT.txt");
	if (!miarchivo.fail()) {
		while (!miarchivo.eof()) {
			getline(miarchivo, linea);
			resultado.push_back(linea);
		}
	}
	return resultado;
}
void Base::GrabarOUTPUT(vector<string> datos) {
	ofstream miarchivo("OUTPUT.txt", std::ofstream::app);
	if (!miarchivo.fail()) {
		for (int i = 0; i < datos.size(); i++) {
			miarchivo << datos.at(i) << "\n";
		}
		miarchivo.flush();
		miarchivo.close();
	}
}
