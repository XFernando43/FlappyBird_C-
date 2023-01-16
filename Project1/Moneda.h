#pragma once
#include "CEntidad.h"
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace std;
class Moneda: CEntidad {
	bool estado;
public:
	Moneda(Bitmap^ img, int x, int y) {
		this->x = x;
		this->y = y;
		dx = 20; dy = 3;
		idfilas = 0; idcolumnas = 0;
		AltoImangem = img->Height;
		AnchoImagen = img->Width;
		altoPersonaje = AltoImangem;
		anchoPersonaje = AnchoImagen;
		estado = false;
	}
	void Draw(Bitmap^ img, Graphics^ L) {
		Rectangle seccion = Rectangle(idcolumnas * anchoPersonaje, idfilas * altoPersonaje, anchoPersonaje, altoPersonaje);
		Rectangle Tamanho = Rectangle(x, y, anchoPersonaje / 7, altoPersonaje / 7);
		L->DrawImage(img, Tamanho, seccion, GraphicsUnit::Pixel);
	}

	void Mover() { x -= dx; }
	void funciona_porfavorcito() {}

	bool getEstado() { return estado; }
	int getX() { return x; }
	int getY() { return y; }
	int getAltoMoneda() { return altoPersonaje; }
	int getAnchoMoneda() { return anchoPersonaje; }

	void setDx(int x) { this->x = x; }
	void setEstado(bool e) { estado = e; }
};